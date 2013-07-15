<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create basis_of_record vocabulary.
 */
function bir_taxonomy_basis_of_record() {
  return array(
    array(
      'name' => t('Basis of Record'),
      'machine_name' => 'basis_of_record',
      'description' => t('Basis of record information for specimens.'),
      'hierarchy' => 0,
      'module' => 'bir_taxonomy',
      'weight' => 2,
    ),
    array(
      'name' => 'Germplasm/seed',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Living organism',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Observation',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Specimen',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
