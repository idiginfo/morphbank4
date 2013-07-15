<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create type_status vocabulary.
 */
function bir_taxonomy_type_status() {
  return array(
    array(
      'name' => t('Type Status'),
      'machine_name' => 'type_status',
      'description' => t('List of type status'),
      'module' => 'bir_taxonomy',
      'weight' => 11,
    ),
    array(
      'name' => 'Holotype',
      'description' => 'Holotype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Isotype',
      'description' => 'Isotype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Lectotype',
      'description' => 'Lectotype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Neotype',
      'description' => 'Neotype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Nontype',
      'description' => 'Nontype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Not Provided',
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Paralectotype',
      'description' => 'Paralectotype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Paratype',
      'description' => 'Paratype',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Syntype',
      'description' => 'Syntype',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
