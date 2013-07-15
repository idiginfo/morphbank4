<?php

/**
 * @file
 * Include file for BIR vocabulary and terms.
 */

/**
 * Function to create imaging_technique vocabulary.
 */
function bir_taxonomy_imaging_technique() {
  return array(
    array(
      'name' => t('Imaging Technique'),
      'machine_name' => 'imaging_technique',
      'description' => t('Image technique used for specimen.'),
      'module' => 'bir_taxonomy',
      'weight' => 8,
    ),
    array(
      'name' => 'Auto-Montage',
      'description' => 'Image stacking software, name coined by Syncroscopy company, but often used universally',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Auto-montage, alcohol temporary mount',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Automontage Pro software from Syncroscopy for image-stacking 3D',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera',
      'description' => 'camera through ocular of dissecting microscope',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera nikon coolpix',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera via compound microscope',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera via compound microscope with cross polarizer',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera via dissection scope',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'digital camera via stereomicroscope',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital camera, flash',
      'description' => 'Digital camera with 2 strobes',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital camera, mounted flash',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital, available light',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital, macro',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital, macro flash',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Digital, macro, underwater',
      'description' => 'Olympus in UW housing',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Dissection microscope',
      'description' => 'Dissection microscope description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'EntoVision',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Entovision - Compound microscope',
      'description' => 'Whole-mount specimen imaged using a compound microscope',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'EntoVision, brightfield',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'ESEM',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GT EntoVision, stereomicroscope',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'GT Vision, stereomicroscope',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Illustration',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Image stacking',
      'description' => 'Software for montage images but not referring to a specific trade name',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Light microscopy, digital image stacking',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Microptics',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Nikonos with macro lens',
      'description' => 'underwater film camera',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Nomarski',
      'description' => 'Differential Phase Contrast Compound Scope',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Not provided',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Polarized microscopy',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Radiograph, scan',
      'description' => 'Not provided',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Reflected light, macrophotography',
      'description' => 'Reflected light, macrophotography description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Reflected light, scan',
      'description' => 'Reflected light, scan description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'ROV mounted digital video',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Scan',
      'description' => 'Flatbed scanner',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'SEM',
      'description' => 'SEM description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'SEM, brightfield',
      'description' => 'SEM, brightfield description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'SEM, Microptics & Confocal',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'single image, reflected light microscopy',
      'description' => 'single image taken with (digital) camera (and phototube) through dissecting microscope optics',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Transmitted light, brightfield',
      'description' => 'Transmitted light, brightfield description',
      'format' => 'plain_text',
      'parent' => '',
    ),
    array(
      'name' => 'Unknown',
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
      'name' => 'Video Frame',
      'description' => '',
      'format' => 'plain_text',
      'parent' => '',
    ),
  );
}
