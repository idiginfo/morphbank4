<?php
/**
 * @file
 * Drush commands for BIR.
 */

/**
 * Implements hook_drush_command().
 */
function bir_drush_command() {
  $items = array();

  $items['bir-process-images'] = array(
    'description' => dt('Process images on image server.'),
    'aliases' => array('bir-pi'),
    'arguments' => array(
      'range' => dt('Starting and ending node id separated by dash.'),
      'list' => dt('Comma separated list of node ids to process.'),
      'days' => dt('Number of day(s) in the past to begin processing. Overrides list and range.'),
      'start' => dt('Starting node id to begin processing upward from. Overrides days, list, and range.'),
    ),
    'options' => array(
      'range' => dt('Starting and ending node id separated by dash.'),
      'list' => dt('Comma separated list of node ids to process.'),
      'days' => dt('Number of day(s) in the past to begin processing. Overrides list and range.'),
      'start' => dt('Starting node id to begin processing upward from. Overrides days, list, and range.'),
    ),
    'examples' => array(
      'drush bir-process-images --range=2000-2309' => dt('Process images for given node range.'),
      'drush bir-process-images --list=2409,2309' => dt('Process images for given node ids.'),
      'drush bir-process-images --days=7' => dt('Process images from 7 days ago to now.'),
      'drush bir-process-images --start=1234' => dt('Process images for given node id and greater.'),
      'drush bir-pi --range=2000-2309' => dt('Process images for given node range.'),
      'drush bir-pi --list=2409,2309' => dt('Process images for given node ids.'),
      'drush bir-pi --days=7' => dt('Process images from 7 days ago to now.'),
      'drush bir-pi --start=1234' => dt('Process images for given node id and greater.'),
    ),
  );


  return $items;
}

/**
 * Process images on image server.
 */
function drush_bir_process_images() {
  $range = drush_get_option('range');
  $list = drush_get_option('list');
  $days = drush_get_option('days');
  $start = drush_get_option('start');

  if (empty($range) && empty($list) && empty($days) && empty($start)) {
    drush_die(dt('You need to set options for processing. Type "drush help bpi" for help.'));
  }

  // Retrieve data and populate $nids
  if (!empty($start)) {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'bir_image')
      ->propertyCondition('nid', $nid, '>=')
      ->propertyOrderBy('nid', 'ASC');
    $result = $query->execute();
    $nids = array_keys($result['node']);
  } elseif (!empty($days)) {
    $time = strtotime("-$days day");
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'bir_image')
      ->propertyCondition('created', $time, '>=')
      ->propertyOrderBy('nid', 'ASC');
    $result = $query->execute();
    $nids = array_keys($result['node']);
  } elseif (!empty($list)) {
    $nids = explode(',', $list);
  } else {
    list($start, $end) = explode('-', $range);
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'bir_image')
      ->propertyCondition('nid', trim($start), '>=')
      ->propertyCondition('nid', trim($end), '<=')
      ->propertyOrderBy('nid', 'ASC');
    $result = $query->execute();
    $nids = array_keys($result['node']);
  }

  // If nids is empty now, then there are not images to process
  if (empty($nids)) {
    drush_die(dt('No images need to be processed.'));
  }

  // Chunk the data so each process does not time out.
  $chunks = array_chunk($nids, 20);
  $operations = array();
  $count_chunks = count($chunks);

  // For each chunk, assign function to run
  foreach ($chunks as $chunk) {
    $i++;
    $image_count = count($chunk);
    $operations[] = array(
      "bir_image_process_images",
      array(
        $chunk,
        'details'=> t('Processing batch @chunk of @count containing @image_count images',
            array(
              '@chunk' => $i,
              '@count' => $count_chunks,
              '@image_count' => $image_count,
        )),
      ),
    );
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Process images batch'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred'),
    'finished' => 'bir_image_process_images_finished'
  );

  //Get the batch process all ready!
  batch_set($batch);
  $batch =& batch_get();

  //Because we are doing this on the back-end, we set progressive to false.
  $batch['progressive'] = FALSE;

  //Start processing the batch operations.
  drush_backend_batch_process();
}
