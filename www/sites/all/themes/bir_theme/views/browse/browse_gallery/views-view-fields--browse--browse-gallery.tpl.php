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
$node_jpg = "/bir-api/node/{$fields['nid']->content}.jpg";
$standard_image_thumb = "/bir-api/node/{$fields['standard_image']->content}.thumb";
$standard_image_jpg = "/bir-api/node/{$fields['standard_image']->content}.jpg";

if ($fields['type']->content == 'bir_image') {
  $full = !empty($fields['nid']->content) ? $node_thumb : $default_img;
  $full2 = !empty($fields['nid']->content) ? $node_jpg : $default_img;
} else {
  $full = !empty($fields['standard_image']->content) ? $standard_image_thumb : $default_img;
  $full2 = !empty($fields['standard_image']->content) ? $standard_image_jpg : $default_img;
}

switch ($fields['type']->content) {
  case "bir_image":
    $path = "/image/{$fields['nid']->content}";
    break;
  case "bir_specimen":
    $path = "/specimen/{$fields['nid']->content}";
    break;
  case "bir_view":
    $path = "/view/{$fields['nid']->content}";
    break;
  case "bir_locality":
    $path = "/locality/{$fields['nid']->content}";
    break;
  case "bir_album":
    $path = "/albums/{$fields['nid']->content}";
    break;
  default:
    $path = "";
}
//include("views_template_browse_gallery.php");
?>
<div class="browse-gallery">
<img src="<?php print $full ?>" alt="" class="border" width="140"/>
<a class="float-left" rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full2 ?>"><?php print $magnifier; ?>zoom</a>
<a class="float-right" href="<?php print $edit_path; ?>"><?php print $edit_img; ?>Edit</a>
<br />
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']->content; ?>" />
<a href="<?php print $path; ?>"><?php print $fields['title']->content; ?></a>
</div>

