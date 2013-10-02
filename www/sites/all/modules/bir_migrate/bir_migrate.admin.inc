<?php
/**
 * @file
 * Admin form for BIR Migrate.
 */

/**
 * Admin settings form.
 */
function bir_migrate_admin_settings($form, &$form_state) {

  $form  = array();
  $form['bir_migration_user'] = array(
    '#type' => 'select',
    '#title' => t('User'),
    '#options' => bir_migrate_set_user_options(),
    '#default_value' => variable_get('bir_migration_user', 1),
    '#description' => t('User to run migrations under. Nodes will been shown as submitted by this user.'),
  );
  $form['bir_migration_specimen_file'] = array(
    '#type' => 'textfield',
    '#title' => t('Specimen Migration File'),
    '#size' => 100,
    '#maxlength' => 255,
    '#default_value' => variable_get('bir_migration_specimen_file'),
    '#description' => t('Full path to specimen migration file on the server. (i.e. /data/migration/specimens.csv)'),
  );
  $form['bir_migration_image_file'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Migration File'),
    '#size' => 100,
    '#maxlength' => 255,
    '#default_value' => variable_get('bir_migration_image_file'),
    '#description' => t('Full path to specimen migration file on the server. (i.e. /data/migration/images.csv)'),
  );
  $form['bir_migration_default_node_status'] = array(
    '#type' => 'select',
    '#title' => t('Default Node Status'),
    '#options' => array('Private', 'Public'),
    '#default_value' => variable_get('bir_migration_default_node_status', 1),
    '#description' => t('Default for public/private node status during migrations when not included in migration.'),
  );

  return system_settings_form($form);
}

function bir_migrate_set_user_options() {
  $options = array();
  $users = entity_load('user');
  foreach ($users as $account) {
    if ($account->uid > 0) {
      $profile = profile2_load_by_user($account, 'bir_profile');
      $wrapper = entity_metadata_wrapper('profile2', $profile);
      $uid = $wrapper->getIdentifier();
      $first_name = $wrapper->field_first_name->value();
      $last_name = $wrapper->field_last_name->value();
      $options[$uid] = $first_name . " " . $last_name;
    }
  }

  return $options;
}
