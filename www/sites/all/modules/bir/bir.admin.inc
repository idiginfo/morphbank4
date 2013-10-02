<?php

/**
 * @file
 * Admin form for BIR.
 */

/**
 * Admin settings form.
 */
function bir_admin_settings($form, &$form_state) {

  $form  = array();
  $form['image_server_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Server URL'),
    '#size' => 50,
    '#maxlength' => 500,
    '#default_value' => variable_get('image_server_url', ''),
    '#description' => t('Image Server URL where images are stored. Include trailing slash.'),
  );
  $form['no_image_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Default Image'),
    '#size' => 50,
    '#maxlength' => 500,
    '#default_value' => variable_get('no_image_name', 'no-image.png'),
    '#description' => t('Default image shown when no image returned by image server. ("/themes/bir_theme/images/no-image.png")'),
  );
  $form['creative_commons'] = array(
    '#type' => 'textfield',
    '#title' => t('Creative Commons'),
    '#size' => 100,
    '#maxlength' => 255,
    '#default_value' => variable_get('creative_commons', '<a href="http://creativecommons.org/licenses/by-nc-sa/3.0/us/" rel="license">'
      . '<img src="http://i.creativecommons.org/l/by-nc-sa/3.0/us/88x31.png" style="border-width: 0pt;" alt="Creative Commons License"/>'
      . '</a>'),
    '#description' => t('Creative Commons license for uploaded images.'),
  );

  return system_settings_form($form);
}
