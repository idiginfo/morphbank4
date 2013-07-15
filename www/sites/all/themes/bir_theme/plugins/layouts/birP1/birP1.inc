<?php
// $Id: front.inc,v 1.1.2.1 2008/12/16 21:27:58 $

/**
* Implementation of hook_panels_layouts().
*/
function bir_birP1_panels_layouts() {
  $items['birP1'] = array(
    'title' => t('birP1'),
	'category' => t('Columns: 2'),
    'icon' => 'birP1.png',
    'theme' => 'panels_birP1',
    'css' => 'birP1.css',
    'regions' => array(
    'left' => t('Left side'),
    'right' => t('Right side')
     ),
  );

  return $items;
}
?>
