<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create name_source vocabulary.
 */
function bir_taxonomy_name_source() {
  return array(
    array(
      'name' => t('Determination Name Sources'),
      'machine_name' => 'name_source',
      'description' => t('List of determination name sources.'),
      'hierarchy' => 0,
      'module' => 'bir_taxonomy',
      'weight' => 14,
    ),
  );
}
