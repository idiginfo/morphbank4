<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create sex vocabulary.
 */
function bir_taxonomy_sex() {
  return array(
    array(
      'name' => t('Sex'),
      'machine_name' => 'sex',
      'description' => t('Sex.'),
      'module' => 'bir_taxonomy',
      'weight' => 9,
    ),
    array(
      'name' => 'Bisexual',
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Female',
      'description' => 'Female description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Hermaphrodite',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Hermaphrodite, Dioecious',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Indeterminate',
      'description' => 'Indeterminate description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Male',
      'description' => 'Male description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'male and female',
      'description' => 'both male and female specimens in image',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Not applicable',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Not Provided',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Undetermined',
      'description' => 'Undetermined description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unknown',
      'description' => 'Unknown description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unspecified',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
