<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create developmental_stage vocabulary.
 */
function bir_taxonomy_developmental_stage() {
  return array(
    array(
      'name' => t('Developmental Stage'),
      'machine_name' => 'developmental_stage',
      'description' => t('Developmental stage.'),
      'module' => 'bir_taxonomy',
      'weight' => 5,
    ),
    array(
      'name' => 'Adult',
      'description' => 'Adult description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Adult and Subadult',
      'description' => 'Adult and Subadult description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Colony',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'egg, larva, and pupa',
      'description' => 'host is used by egg, larval, and pupal stages of wasp. Host is mummifed by late larval wasp stage. Mummy shelters pupal wasp s',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Final instar larva',
      'description' => 'Final instar larva description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'flower',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Juvenile',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Larva',
      'description' => 'Larva description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Mature',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Neonate',
      'description' => 'Not provided',
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
      'name' => 'not provided',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pupa',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Seed',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Seedling',
      'description' => 'Seedling',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Subadult',
      'description' => 'Subadult description',
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
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unspecified',
      'description' => 'Unspecified description',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
