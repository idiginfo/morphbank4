<?php

/**
 * @file
 * Classes to handle rest services for images
 */

/**
 * Class to handle rest server image
 */
class ServicesImageFormatter implements ServicesFormatterInterface {

  protected $type;
  protected $imageServerUrl;
  protected $thumbDir;
  protected $thumbFile;
  protected $thumbUri;
  protected $thumbFid;
  protected $thumb;

  /**
   * Render an image.
   */
  public function render($data) {
    $this->data = $data;
    $this->imageServerUrl = variable_get('image_server_url', 'http://itest.morphbank.net');
    $this->thumb = FALSE;

    return $this->getImage();
  }

  protected function setImageType($type) {
    $this->type = $type;
  }

  /**
   * Set variables for thumbnails.
   */
  protected function setVariables() {
    $this->thumbDir = file_default_scheme() . "://bir_thumbs";

    $this->thumbFile = isset($this->data->field_image[LANGUAGE_NONE][0]['filename']) ?
      $this->data->field_image[LANGUAGE_NONE][0]['filename'] : "{$this->data->nid}.jpg";

    $this->thumbUri = isset($this->data->field_image[LANGUAGE_NONE][0]['uri']) ?
      $this->data->field_image[LANGUAGE_NONE][0]['uri'] : "$this->thumbDir/$this->thumbFile";

    $this->thumbFid = isset($this->data->field_image[LANGUAGE_NONE][0]['uri']) ?
      $this->data->field_image[LANGUAGE_NONE][0]['fid'] : FALSE;

    return;
  }

  /**
   * Render a thumbnail immediately or get remote image and set thumb.
   */
  protected function getImage() {
    if ($this->type == 'thumb') {
      if (file_exists($this->thumbUri) && exif_imagetype($this->thumbUri) && $this->thumbFid) {
        return $this->renderThumb();
      }
      $this->thumb = TRUE;
    }

    return $this->getRemoteImage();
  }

  /**
   * Retrieves remote image and create thumbnail if needed.
   */
  private function getRemoteImage() {
    // Unset unecessary query string.
    unset($_GET['q']);
    // Handle morphbank furi differently.
    if (preg_match('/morphbank/', $this->data->furi[LANGUAGE_NONE][0]['value'])) {
      $this->imageServerUrl = 'http://images.morphbank.net';
      $id = preg_replace('/[^0-9]/', '', $this->data->furi[LANGUAGE_NONE][0]['value']);
    }
    else {
      $id = $this->data->nid;
    }

    $image_size = $this->setImageSize();
    $url = "{$this->imageServerUrl}/?id=$id&imgType={$this->type}$image_size";

    $request = $this->getAllHeaders();
    $header = isset($request['If-Modified-Since']) ? array($request['If-Modified-Since']) : array();
    $ch = curl_init();
    $timeout = 0;
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_BINARYTRANSFER, 1);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $header);
    $rawdata = curl_exec($ch);
    if (curl_errno($ch)) {
      $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL));
      $image_file = realpath("$theme_path/images/no-image.png");
      $handle = fopen($image_file, "rb");
      $image = fread($handle, filesize($image_file));
      return $image;
    }

    curl_close($ch);

    if ($this->thumb) {
      return $this->createThumbnail($rawdata);
    }

    return $rawdata;
  }

  /**
   * Renders a thumbnail.
   */
  private function renderThumb() {
    /*
    header("Cache-Control: public");
    header('image/jpeg');
    header('Last-Modified: ' . date("r", @filemtime($this->thumbUri)));
    */
    return readfile($this->thumbUri);
  }

  /**
   * Set image size query params if called.
   */
  private function setImageSize() {
    $size = NULL;

    if (!empty($_GET['width'])) {
      $size = '&imgSize=' . $_GET['width'];
    }

    if (!empty($_GET['width']) && !empty($_GET['height'])) {
      $size .= 'x' . $_GET['height'];
    }

    return $size;
  }

  /**
   * Create thumbnail and update file_managed and node field_image.
   */
  private function createThumbnail($rawdata) {
    $this->moveFile($rawdata);

    if (!$fid = $this->checkFileManagedUri()) {
      $fid = $this->createManagedFile();
    }

    $file = file_load($fid);

    $this->updateNode($file);

    return $this->renderThumb();
  }

  /**
   * Check if uri already exists in file_managed.
   */
  private function checkFileManagedUri() {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'file')
      ->propertyCondition('uri', $this->thumbUri)
      ->execute();
    if (empty($result)) {
      return FALSE;
    }

    $fid = current(array_keys($result['file']));

    return $fid;
  }

  /**
   * Update node associated with image.
   */
  private function updateNode($file) {
    $image_info = image_get_info($this->thumbUri);
    $file->width = $image_info['width'];
    $file->height = $image_info['height'];

    $obj = new stdClass();
    $obj->nid = $this->data->nid;
    $obj->vid = $this->data->vid;
    $obj->type = $this->data->type;
    $obj->field_image[LANGUAGE_NONE][0] = (array) $file;

    /*
     * MySQL deadlocks when mulitple calls are made to the rest server
     * and thumbs created. Catching the exception as it bubbles up allows
     * the image to show, and the field update will occur
     * at a later time when not so many calls are being made.
     */
    try {
      field_attach_update('node', $obj);
    }
    catch (Exception $e) {
      watchdog('Field update for node ' . $obj->nid, $e->getMessage());
    }

    return;
  }

  /**
   * Create managed file.
   */
  private function createManagedFile() {
    $file = new stdClass();
    $file->uid = $this->data->uid;
    $file->filename = $this->thumbFile;
    $file->uri = $this->thumbUri;
    $file->filemime = "image/jpeg";
    $file->status = 1;

    $file = file_save($file);

    return $file->fid;
  }

  /**
   * Move image.
   */
  private function moveFile($rawdata) {
    file_prepare_directory($this->thumbDir, FILE_CREATE_DIRECTORY);
    file_unmanaged_save_data($rawdata, $this->thumbUri, FILE_EXISTS_REPLACE);

    return;
  }

  /**
   * Get headers for server.
   */
  private function getAllHeaders() {
    if (!function_exists('getallheaders')) {
      return $this->getAllHeadersCustom();
    }
    else {
      return getallheaders();
    }
  }

  /**
   * Create function if not in PHP.
   */
  private function getAllHeadersCustom() {
    $headers = array();
    foreach ($_SERVER as $name => $value) {
      if (substr($name, 0, 5) == 'HTTP_') {
        $headers[str_replace(' ', '-', ucwords(strtolower(str_replace('_', ' ', substr($name, 5)))))] = $value;
      }
    }
    return $headers;
  }
}

class ServicesThumbFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("thumb");
    $this->setVariables();
  }
}

class ServicesJpgFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("jpg");
  }
}

class ServicesJpegFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("jpeg");
  }
}

class ServicesTifFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("tif");
  }
}

class ServicesDngFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("dng");
  }
}

class ServicesBmpFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("bmp");
  }
}

class ServicesGifFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("gif");
  }
}

class ServicesPngFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("png");
  }
}

class ServicesTpcFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->setImageType("tpc");
  }
}
