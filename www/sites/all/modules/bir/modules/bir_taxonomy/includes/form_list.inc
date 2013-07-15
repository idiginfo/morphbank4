<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create form_list vocabulary.
 */
function bir_taxonomy_form_list() {
  return array(
    array(
      'name' => t('Form'),
      'machine_name' => 'form',
      'description' => t('Form.'),
      'module' => 'bir_taxonomy',
      'weight' => 6,
    ),
    array(
      'name' => 'Bonzai',
      'description' => 'Bonzai',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned',
      'description' => 'Acidic Cleaned Diatom Frustule',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Closed',
      'description' => 'Applies to mature female gymnosperm cones',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'contracted',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Developing',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'dormant',
      'description' => 'as twig appears in leafless state',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Dwarf',
      'description' => 'Dwarf',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'early spring',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Early Winter',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Emergent',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Endodermal',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Epitoke',
      'description' => 'reproductive stolen',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Expanded',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Fall',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'free-living',
      'description' => 'non-symbiotic',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Fruiting',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'host',
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
      'name' => 'Large',
      'description' => 'For bark, the form of a fully mature tree',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Late summer',
      'description' => 'Late summer',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Late Winter',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Leafless',
      'description' => 'Plant in winter or other season of dormancy',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Medium',
      'description' => 'For bark, the form intermediate between a sapling and a mature tree.',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Mesogleal',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Mid Winter',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Not Applicable',
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
      'name' => 'Not specified',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Open',
      'description' => 'Applies to mature female gymnosperm cones',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Parthenogenetic',
      'description' => 'Parthenogenetic description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Rainy season',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Receptive',
      'description' => 'Applies to female gymnosperm cones',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'reproductive',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Small',
      'description' => 'For bark, the form of a sapling',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Spring',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Summer',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Summer re-bloom',
      'description' => 'Summer re-bloom',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Symbiotic',
      'description' => 'living in intimate contact',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Undetermined',
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unknown',
      'description' => 'Unknown',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unspecified',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Winter',
      'description' => 'Winter',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
