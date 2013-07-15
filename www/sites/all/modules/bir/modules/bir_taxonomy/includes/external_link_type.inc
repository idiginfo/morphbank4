<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create external_link_typ vocabulary.
 */
function bir_taxonomy_external_link_type() {
  return array(
    array(
      'name' => t('External Link Type'),
      'machine_name' => 'external_link_type',
      'description' => t('List of external link types.'),
      'hierarchy' => 0,
      'module' => 'bir_taxonomy',
      'weight' => 15,
    ),
    array(
      'name' => 'Determination Resource',
      'description' => 'More information regarding determination',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'EOL',
      'description' => 'Link to an EOL taxon page',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'External Unique Reference',
      'description' => 'An external unique identifier for the object',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GenBank',
      'description' => 'GenBank sequences',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Google Maps',
      'description' => 'Google Maps location',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Institution',
      'description' => 'Link to institution',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Morphbank',
      'description' => 'Link to Morphbank object',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Ontology',
      'description' => 'Link to ontology site',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Other',
      'description' => 'Other',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Project',
      'description' => 'Link to a project',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Publication',
      'description' => 'Link to publication',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Specimen Database',
      'description' => 'Added by users via upload',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Web Page',
      'description' => 'Link to a web page',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
