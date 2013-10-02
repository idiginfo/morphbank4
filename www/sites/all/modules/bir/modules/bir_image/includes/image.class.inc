<?php
/**
 * @file
 * BIR Image Class.
 */

/**
 * The class used for handling image processing.
 */
class BirImage {
  /**
   * The node.
   *
   * @var object
   */
  private $node;

  /**
   * The node wrapper.
   *
   * @var object
   */
  private $nw;

  /**
   * The original node wrapper.
   *
   * @var object
   */
  private $ow;

  /**
   * Node id.
   *
   * @var integer
   */
  private $nid;

  /**
   * Uri for the thumbnail.
   *
   * @var string
   */
  private $thumb_uri;

  /**
   * Respons from image server request.
   *
   * @var object
   */
  private $response;

  /**
   * Original file if one already exists.
   *
   * @var object
   */
  private $original_file;


  public function __construct() {}

  /**
   * Set needed variables.
   */
  public function set_variables($node) {
    $this->node = $node;
    $this->nw = entity_metadata_wrapper('node', $node);
    $this->nid = $this->nw->getIdentifier();
    $this->thumb_uri = file_build_uri("{$this->nid}.jpg");
    $this->imageServerUrl = variable_get('image_server_url');

    return;
  }

  /**
   * Method to process images when node inserted.
   */
  public function insert() {
    $this->process();
  }

  /**
   * Method to process images when node is updated.
   * Checks if new file is being uploaded then processes.
   * Receive error when trying to access $ow->field_image->file->fid and it doesn't exist
   * so using field_image array.
   */
  public function update($node) {
    $ow = entity_metadata_wrapper('node', $this->node->original);

    $nf = $this->nw->field_image->value();
    $of = $ow->field_image->value();

    if ($nf['fid'] == $of['fid'] && file_exists($this->thumb_uri)) {
      return;
    }

    $this->process();
  }

  /**
   * Method to process images.
   */
  private function process() {
    // Retrieve information for uploaded image file from database.
    $this->original_file = file_load($this->nw->field_image->file->fid->value());

    $this->post_remote();

    if ($this->response->code >= 400) {
      drupal_set_message($response->error, 'error');
      return;
    }

    list($data, $width, $height, $type) = explode('^', $this->response->data);
    if (!$width) {
      drupal_set_message($data, 'error');
      return;
    }

    // We do not store original image file on app server so delete it.
    file_delete($this->original_file, TRUE);

    // Get image thumbnail from image server.
    $data = array(
      'id' => $this->nid,
      'imgType' => 'thumb',
    );
    $this->get_remote($data);

    if ($this->response->code >= 400) {
      drupal_set_message($response->error, 'error');
      return;
    }

    $file = file_save_data($this->response->data, $this->thumb_uri, FILE_EXISTS_REPLACE);

    $image_info = image_get_info($this->thumb_uri);
    $file->width = $image_info['width'];
    $file->height = $image_info['height'];

    $this->update_fields($file, $width, $height, $type);

    return;
  }

  /**
   * Post image to remote image server and set response.
   */
  private function post_remote() {
    // Absolute file path.
    $wrapper = file_stream_wrapper_get_instance_by_uri($this->original_file->uri);
    $filepath = $wrapper->realpath();

    // Get file information.
    $fileinfo = pathinfo($this->original_file->uri);

    // New file name.
    $new_file_name = str_replace($fileinfo['filename'], $this->nid, $fileinfo['basename']);

    // Set boundry for multi-part form
    $boundary = md5(uniqid());

    $post_data = array(
      'action' => 'upload',
      'id' => $this->nid,
      'fileName' => $new_file_name,
      'image' => "$filepath|$new_file_name|{$this->original_file->filemime}",
    );

    $options = array(
      'method' => 'POST',
      'data' => $this->multipart_encode($boundary, $post_data),
      'headers' => array('Content-Type' => "multipart/form-data; boundary=$boundary"),
    );

    $this->response = drupal_http_request(variable_get('image_server_url'), $options);

    return;
  }

  /**
   * Get thumbnail from image server.
   */
  public function get_remote($data) {
    $options = array('headers' => $this->set_if_modified());

    $full_url = url($this->imageServerUrl, array('query' => $data));

    $this->response = drupal_http_request($full_url, $options);

    // Return response when Services is calling this function
    return $this->response;
  }

  /**
   * Update fields of the node.
   */
  private function update_fields($file, $width, $height, $type) {
    $this->nw->field_image->file->set($file);
    $this->nw->original_image_source->set($this->original_file->filename);
    $this->nw->creative_commons->set(variable_get('creative_commons'));
    $this->nw->image_width->set($width);
    $this->nw->image_height->set($height);
    $this->nw->image_type->set($type);
    $this->nw->identifier->set($this->nw->uuid->value());
    $this->nw->standard_image->set($this->nw);

    // Update node fields.
    field_attach_update('node', $this->node);

    return;
  }

  /**
   * Base function to encode data array for post to image server
   */
  public function multipart_encode($boundary, $params){
    $output = "";
    foreach ($params as $key => $value){
      $output .= "--$boundary\r\n";
      if ($key == 'image'){
        $output .= $this->multipart_enc_file($value);
      } else {
        $output .= $this->multipart_enc_text ($key, $value);
      }
    }
    $output .="--$boundary--";
    return $output;
  }

  /**
   * Function to encode image file
   */
  private function multipart_enc_file($value){
    list($path, $filename, $mimetype) = explode('|', $value);
    if (substr($path, 0, 1) == "@") {
      $path = substr($path, 1);
    }
    $data = "Content-Disposition: form-data; name=\"image\"; fileName=\"$filename\"\r\n";
    $data .= "Content-Transfer-Encoding: binary\r\n";
    $data .= "Content-Type: $mimetype\r\n\r\n";
    $data .= file_get_contents($path) . "\r\n";
    return $data;
  }

  /**
   * Function to encode text data
   */
  private function multipart_enc_text($name, $value){
    return "Content-Disposition: form-data; name=\"$name\"\r\n\r\n$value\r\n";
  }

  /**
   * Set If Modified header
   */
  public function set_if_modified() {
    if (!function_exists('getallheaders')) {
      $headers = array();
      foreach ($_SERVER as $name => $value) {
        if (substr($name, 0, 5) == 'HTTP_') {
          $headers[str_replace(' ', '-', ucwords(strtolower(str_replace('_', ' ', substr($name, 5)))))] = $value;
        }
      }
    }
    else {
      $headers = getallheaders();
    }

    if (isset($headers['If-Modified-Since'])) {
      return array('If-Modified-Since' => $headers['If-Modified-Since']);
    }

    return array();
  }

}