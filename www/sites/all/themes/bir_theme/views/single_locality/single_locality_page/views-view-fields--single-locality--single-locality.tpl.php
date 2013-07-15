<?php
$theme_path = base_path() . path_to_theme();

$default_img = $theme_path . '/images/no-image.png';
$standard_image_jpg = "/bir-api/node/{$fields['standard_image']->content}.jpg";
$standard_image_jpeg = "/bir-api/node/{$fields['standard_image']->content}.jpeg";

$full = !empty($fields['standard_image']->content) ? $standard_image_jpg : $default_img;
$full2 = !empty($fields['standard_image']->content) ? $standard_image_jpeg : $default_img;
?>
<h2 class="single-node-title">Locality Record: [ <?php print $fields['title']->content; ?> ]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<!-- Annotate --><a href="#"><img src="<?php print $theme_path . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>&nbsp;&nbsp;
<!-- Print --><a href="#"><img src="<?php print $theme_path . '/' ?>images/printer.png" alt="Print" border="0"/></a>&nbsp;&nbsp;
</h2>
<h4>Location Information</h4>
<ul class="two-col-tab-left">
  <li>
    <span class="list-label">Continent/Ocean: </span>
    <?php print $fields['continent_ocean']->content; ?>
  </li>
  <li>
    <span class="list-label">Country: </span>
    <?php print $fields['country']->content; ?>
  </li>
  <li>
    <span class="list-label">State/Province/County:</span>
    <?php print $fields['province']->content; ?>
  </li>
  <li>
    <span class="list-label">Latitude:</span>
    <?php print $fields['latitude']->content; ?>
  </li>
  <li>
    <span class="list-label">Longitude:</span>
    <?php print $fields['longitude']->content; ?>
  </li>
  <li>
    <span class="list-label">Lat/Lng Precision:</span>
    <?php print $fields['coordinate_precision']->content; ?>
  </li>
  <li>
    <span class="list-label">Depth:</span>
    <?php print $fields['max_depth']->content; ?> - <?php print $fields['min_depth']->content; ?>
  </li>
  <li>
    <span class="list-label">Elevation:</span>
    <?php print $fields['max_elevation']->content; ?><?php print $fields['min_elevation']->content; ?>
  </li>
</ul>
