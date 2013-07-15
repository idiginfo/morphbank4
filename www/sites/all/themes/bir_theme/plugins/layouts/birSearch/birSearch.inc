<?php
// $Id: front.inc,v 1.1.2.1 2008/12/16 21:27:58 $

/**
* Implementation of hook_panels_layouts().
*/
function bir_birSearch_panels_layouts() {
  $items['birSearch'] = array(
    'title' => t('birSearch'),
	'category' => t('Columns: 2'),
    'icon' => 'birSearch.png',
    'theme' => 'panels_birSearch',
    'css' => 'birSearch.css',
    'regions' => array(
    'left' => t('Left side'),
    'right' => t('Right side')
     ),
  );

  return $items;
}
?>
