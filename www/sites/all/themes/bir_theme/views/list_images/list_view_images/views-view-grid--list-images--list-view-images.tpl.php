<?php

$theme_path = base_path() . path_to_theme();

$mag_vars = array(
  'path' => $theme_path . '/images/magnifier.png',
  'alt' => 'Magnifying glass',
  'attributes' => array('align' => 'middle'),
);
$magnifier = theme('image', $mag_vars);

$edit_vars = array(
  'path' => $theme_path . '/images/page_edit.png',
  'alt' => 'Default Image',
  'attributes' => array('align' => 'middle'),
);
$edit_img = theme('image', $edit_vars);

$default_img = $theme_path . '/images/no-image.png';

$edit_path = "/node/{$fields['nid']->content}/edit";

$node_thumb = "/bir-api/node/{$fields['nid']->content}.thumb";
$node_jpeg = "/bir-api/node/{$fields['nid']->content}.jpeg";

$full = !empty($fields['nid']->content) ? $node_thumb : $default_img;
$full2 = !empty($fields['nid']->content) ? $node_jpeg : $default_img;

$path = "/image/{$fields['nid']->content}";
?>
<div class="browse-gallery">
<img src="<?php print $full ?>" alt="" class="border" width="140"/>
<a class="float-left" rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full2 ?>"><?php print $magnifier; ?>zoom</a>
<a class="float-right" href="<?php print $edit_path; ?>"><?php print $edit_img; ?>Edit</a>
<br />
<a href="<?php print $path; ?>"><?php print $fields['title']->content; ?></a>      
</div>
