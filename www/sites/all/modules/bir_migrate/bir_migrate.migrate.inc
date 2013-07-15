<?php

/**
 * @file
 * Because the name of this file is the module name plus '.migrate.inc', when
 * hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded.
 */

/*
 * Implements hook_migrate_api().
 */
function bir_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'MorphbankImage' => array('class_name' => 'MorphbankImage'),
      'MorphbankSpecimen' => array('class_name' => 'MorphbankSpecimen'),
    ),
  );
  return $api;
}

/**
 * Implements hook_disable().
 *
 * Deregister its migrations.
 */
function bir_migrate_disable() {
  // based on: drupal.org/node/1418350#comment-5557772.
  Migration::deregisterMigration('MorphbankImage');
  Migration::deregisterMigration('MorphbankSpecimen');
}