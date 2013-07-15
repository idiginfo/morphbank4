<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create scientific_name vocabulary.
 */
function bir_taxonomy_scientific_name() {
  return array(
    array(
      'name' => t('Scientific Name'),
      'machine_name' => 'scientific_name',
      'description' => t('Scientific names for taxon.'),
      'hierarchy' => 0,
      'module' => 'bir_taxonomy',
      'weight' => 13,
    ),
  );
}
