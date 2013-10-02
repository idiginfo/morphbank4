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
   * Set thumb variables.
   */
  protected function setThumbVars() {
    $nw = entity_metadata_wrapper('node', $this->data);
    $field_image = $nw->field_image->value();
    $this->thumbFile = $nw->getIdentifier() . '.jpg';
    $this->thumbUri = file_build_uri($this->thumbFile);
    $this->thumbFid = !empty($field_image) ? $nw->field_image->file->fid->value() : '';

    return;
  }

  /**
   * Render an image.
   */
  public function render($data) {
    $this->data = $data;
    $this->imageServerUrl = variable_get('image_server_url');
    $this->thumb = FALSE;

    if ($this->type == 'thumb') {
      $this->setThumbVars();
      if (file_exists($this->thumbUri) && exif_imagetype($this->thumbUri) && $this->thumbFid) {
        return $this->renderThumb();
      }
      $this->thumb = TRUE;
    }

    return $this->renderImage();
  }

  /**
   * Render image and create thumbnail if needed.
   */
  private function renderImage() {

    $image_data = $this->getImage();

    if ($this->thumb) {
      $image_data = $this->createThumbnail($image_data);
    }

    return $image_data;
  }

  /**
   * Retrieve image from image server
   */
  private function getImage() {
    $image = new BirImage();
    $image->set_variables($this->data);

    $data = array(
    	 'id' => $this->data->nid,
      'imgType' => $this->type,
      'imgSize' => $this->setImageSize(),
    );

    $response = $image->get_remote($data);

    if ($response->code >= 400) {
      $this->thumb = FALSE;
      $data = $this->defaultImage();
    } else {
      $data = $response->data;
    }

    return $data;
  }

  /**
   * Return default image
   */
  private function defaultImage() {

    $theme_path = drupal_get_path('theme', variable_get('theme_default', NULL));
    $image_file = realpath("$theme_path/images/" . variable_get('no_image_name'));
    $handle = fopen($image_file, "rb");
    $image = fread($handle, filesize($image_file));

    return $image;
  }

  /**
   * Renders a thumbnail.
   */
  private function renderThumb() {

    return readfile($this->thumbUri);

  }

  /**
   * Set image size query params if called.
   */
  private function setImageSize() {

    $size = NULL;

    if (!empty($_GET['width'])) {
      $size = $_GET['width'];
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
    file_unmanaged_save_data($rawdata, $this->thumbUri, FILE_EXISTS_REPLACE);

    return;
  }
}


class ServicesThumbFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "thumb";
  }
}

class ServicesJpgFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "jpg";
  }
}

class ServicesJpegFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "jpeg";
  }
}

class ServicesTifFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "tif";
  }
}

class ServicesDngFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "dng";
  }
}

class ServicesBmpFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "bmp";
  }
}

class ServicesGifFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "gif";
  }
}

class ServicesPngFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "png";
  }
}

class ServicesTpcFormatter extends ServicesImageFormatter {
  public function __construct() {
    $this->type = "tpc";
  }
}
