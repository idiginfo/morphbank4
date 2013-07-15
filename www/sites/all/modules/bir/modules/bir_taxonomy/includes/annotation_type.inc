<?php
/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create annotation_type vocabulary.
 */
function bir_taxonomy_annotation_type() {
  return array(
    array(
      'name' => t('Annotation Type'),
      'machine_name' => 'annotation_type',
      'description' => t('List of annnotation types'),
      'module' => 'bir_taxonomy',
      'weight' => 1,
    ),
    array(
      'name' => 'Determination',
      'description' => 'Determination',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'General',
      'description' => 'General',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Legacy',
      'description' => 'Legacy',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Taxon Name',
      'description' => 'Taxon Name',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'XML',
      'description' => 'XML',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
