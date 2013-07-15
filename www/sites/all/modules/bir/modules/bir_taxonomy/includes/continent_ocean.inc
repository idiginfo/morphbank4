<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create continent_ocean vocabulary.
 */
function bir_taxonomy_continent_ocean() {
  return array(
    array(
      'name' => t('Continent/Ocean'),
      'machine_name' => 'continent_ocean',
      'description' => t('List of locations by continent or ocean'),
      'module' => 'bir_taxonomy',
      'weight' => 3,
    ),
    array(
      'name' => 'Not Applicable',
      'description' => 'Continent/Ocean location not applicable',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unpecified',
      'description' => 'Continent/Ocean location unspecified',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Africa',
      'description' => 'Continent/Ocean location Africa',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Antarctica',
      'description' => 'Continent/Ocean location Antarctica',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Asia',
      'description' => 'Continent/Ocean location Asia',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Europe',
      'description' => 'Continent/Ocean location Europe',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Indian Ocean',
      'description' => 'Continent/Ocean location Indian Ocean',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Indo-malayan Region',
      'description' => 'Continent/Ocean location Indo-malayan Region',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'North America',
      'description' => 'Continent/Ocean location North America',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Oceania',
      'description' => 'Continent/Ocean location Oceania',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pacific Ocean',
      'description' => 'Continent/Ocean location Pacific Ocean',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'South America',
      'description' => 'Continent/Ocean location South America',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
