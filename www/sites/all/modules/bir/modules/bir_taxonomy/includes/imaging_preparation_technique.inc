<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create imaging_preparation_technique vocabulary.
 */
function bir_taxonomy_imaging_preparation_technique() {
  return array(
    array(
      'name' => t('Imaging Preperation Technique'),
      'machine_name' => 'imaging_preparation_technique',
      'description' => t('Image preparation technique used for specimen.'),
      'module' => 'bir_taxonomy',
      'weight' => 7,
    ),
    array(
      'name' => '4% formalin',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Acid cleaned, gold-palladium coated',
      'description' => 'Cleaned with hydrogen peroxide/sulfuric acid, sputter-coated with gold-palladium',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'air dried from ethanol',
      'description' => 'EtOH to air',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Air dried from ethanol, Au-Pd coated',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Air dried, Au-Pd coated',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Air dried, gold coated',
      'description' => 'Air dried, gold coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'brushed clean, temporarily mounted on minuten',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Card mount',
      'description' => 'Mounted on small rectangular card',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in absolute ethanol',
      'description' => 'Cleaned in absolute ethanol description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in absolute ethanol, air dried, mounted in Euparal',
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in ammonia, air dried, gold coated',
      'description' => 'Cleaned in ammonia, air dried, gold coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in ammonia, mounted in Euparal',
      'description' => 'Cleaned in ammonia, mounted in Euparal description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in HMDS',
      'description' => 'Cleaned in HMDS description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned in HMDS, air dried, AU-coated',
      'description' => 'Cleaned in HMDS, air dried, AU-coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleaned with 10% KOH, immersed in glycerol',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleared in 10% KOH, mounted in glycerol or glycerin-gelatin',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleared in KOH, mounted in Canada balsam',
      'description' => 'Cleared in KOH, mounted in Canada balsam description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleared in KOH, mounted in Euparal',
      'description' => 'Cleared in KOH, mounted in Euparal description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleared in KOH, platinum-coated',
      'description' => 'Cleared in KOH, platinum-coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'cleared in lactic acid',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Cleared in methyl salicylate',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Critical',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Critical Point Dried',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Critical point dried, Au-Pd coated',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Critical Point Dried, Pinned',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digested in KOH, Au-Pd coated',
      'description' => 'digested in KOH, Au-Pd coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digested in proteinase K, Au-Pd coated',
      'description' => 'digested in proteinase K, Au-Pd coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digested in proteinase K, immersed in glycerol',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digested with trypsine',
      'description' => 'soft tissues removed with trypsine or other proteinase',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Dissection',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Dry',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Ethanol preserved',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Ethanol preserved Alcian blue stained',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Ethanol preserved methyl green stained',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Flattened but not dried',
      'description' => 'Not Provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'gold-palladium coated',
      'description' => 'gold-palladium coated',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GuSCN 1h, gold-palladium',
      'description' => 'DNA extracted for 1 h in GuSCN-based buffer, then gold-palladium coated',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GuSCN based buffer 4 hour',
      'description' => 'DNA leached out by soaking 4 h in GuSCN -based buffer before imaging',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GuSCN-based buffer 1 hour',
      'description' => 'DNA leached out by soaking 1 h in GuSCN-based buffer before imaging',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GuSCN-based buffer 2 hour',
      'description' => 'DNA leached out by soaking 2 h in GuSCN-based buffer before imaging',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'hematoxylin and eosin stained thin sections',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'HMDS',
      'description' => 'HMDS description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'HMDS, gold coated',
      'description' => 'HMDS, gold coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'HMDS, gold-palladium coated',
      'description' => 'HMDS, gold-palladium coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Immersed in ethanol',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Live',
      'description' => 'living specimen in seawater',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Live, partially relaxed',
      'description' => 'Live animal, partially relaxed in Magnesium Chloride',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'manual preparation by Carrie Ancell',
      'description' => 'manual preparation by Carrie Ancell description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Metal coated',
      'description' => 'Metal coated description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Metal coated, no preparation',
      'description' => 'Metal coated, no preparation description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Mounted in Canada balsam',
      'description' => 'Mounted in Canada balsam description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'mounted on prestick',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'No preparation',
      'description' => 'Not Provided',
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
      'name' => 'Petrographic microscopy',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Phallus, phallobase removed',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pinned',
      'description' => 'pinned with no modification',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pinned and Spread',
      'description' => 'Specimen has been pinned and wings spread',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pinned and wings spread',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'pinned, GuSCN 2-h, crit-pt-dried',
      'description' => 'Pinned, DNA extracted for 2 h in GuSCN-based buffer, critical-point-dried',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'pinned, GuSCN 2-h, eth-ac-dried',
      'description' => 'Pinned, DNA extracted for 2 h in GuSCN-based-buffer, ethyl acetate-dried',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pinned, no preparation',
      'description' => 'Pinned, untreated',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'pinned, untreated',
      'description' => 'pinned, not treated',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Plaster cast',
      'description' => 'cast of the original specimen',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'point',
      'description' => 'point, HMDS',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Pressed and Dried',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Randall, J. E. 1961 A technique for fish photography. Copeia. 1961(2): 241-242',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Rinsed sample',
      'description' => 'Lugol\'s fixed, rinsed, air-dried, sputter-coated (gold/palladium)',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Sectioned',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'shaved',
      'description' => 'hair removed to show sculpture',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Slide Mounted',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'sodium hypochlorite centrifugation protocol',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'UNKNOWN',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unspecified',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Wet Mount',
      'description' => 'slide mounted',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
