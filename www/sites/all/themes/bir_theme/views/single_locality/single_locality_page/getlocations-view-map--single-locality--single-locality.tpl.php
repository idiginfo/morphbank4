<?php
/**
 * @file getlocations-view-map.tpl.php
 * @author Bob Hutchinson http://drupal.org/user/52366
 * @copyright GNU GPL
 *
 * Default simple view template to display a list of rows.
 * Derived from views-view-unformatted.tpl.php
 *
 * @ingroup views_templates
 */
?>
<?php
$theme_path = base_path() . path_to_theme();
$fields = $view->style_plugin->rendered_fields[0];

$default_img = $theme_path . '/images/no-image.png';
$standard_image_jpg = "/bir-api/node/{$fields['standard_image']}.jpg";
$standard_image_jpeg = "/bir-api/node/{$fields['standard_image']}.jpeg";

$full = !empty($fields['standard_image']) ? $standard_image_jpg : $default_img;
$full2 = !empty($fields['standard_image']) ? $standard_image_jpeg : $default_img;
?>
<div class="single-node">
  <h2 class="single-node-title">Locality Record: [ <?php print $fields['title']; ?> ]
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <!-- Annotate --><a href="#"><img src="<?php print $theme_path . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>&nbsp;&nbsp;
  <!-- Print --><a href="#"><img src="<?php print $theme_path . '/' ?>images/printer.png" alt="Print" border="0"/></a>&nbsp;&nbsp;
  </h2>
  <div class="single-node-page-left">
    <h4>Locality Information</h4>
    <ul class="two-col-tab-left">
      <li>
        <span class="list-label">Submitted By:</span>
        <a href="/profile/<?php print $fields['name']; ?>">
          <?php print $fields['field_first_name']; ?>&nbsp;<?php print $fields['field_last_name']; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail']; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
      </li>
      <li>
        <span class="list-label">Contributor:</span>
        <a href="/profile/<?php print $fields['contributor']; ?>">
          <?php print $fields['field_first_name_1']; ?>&nbsp;<?php print $fields['field_last_name_1']; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_1']; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
      </li>
      <li>
        <span class="list-label">Group:</span>
        <?php print $fields['og_group_ref']; ?>
      </li>
      <li>
        <span class="list-label">Continent/Ocean: </span>
        <?php print $fields['continent_ocean']; ?>
      </li>
      <li>
        <span class="list-label">Country: </span>
        <?php print $fields['country']; ?>
      </li>
      <li>
        <span class="list-label">State/Province/County:</span>
        <?php print $fields['province']; ?>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li>
        <span class="list-label">Public/Private: </span>
        <?php print $fields['group_content_access']; ?>
      </li>
      <li>
        <span class="list-label">Date Submitted:</span>
        <?php print $fields['created']; ?>
      </li>
      <li>
        <span class="list-label">Last modified date:</span>
        <?php print $fields['changed']; ?>
      </li>
      <li>
        <span class="list-label">Latitude:</span>
        <?php print $fields['latitude']; ?>
      </li>
      <li>
        <span class="list-label">Longitude:</span>
        <?php print $fields['longitude']; ?>
      </li>
      <li>
        <span class="list-label">Lat/Lng Precision:</span>
        <?php print $fields['coordinate_precision']; ?>
      </li>
      <li>
        <span class="list-label">Depth:</span>
        <?php print $fields['max_depth']; ?> - <?php print $fields['min_depth']; ?>
      </li>
      <li>
        <span class="list-label">Elevation:</span>
        <?php print $fields['max_elevation']; ?><?php print $fields['min_elevation']; ?>
      </li>
    </ul>
    <div class="clearfix"></div>
  </div>
  <div class="single-node-page-right">
    <?php if (!empty($fields['latitude']) && !empty($fields['longitude'])): ?>
    <!-- getlocations-view-map.tpl -->
    <div class="getlocations_map_wrapper getlocations_float">
    <?php print $map; ?>
    </div>
    <!-- /getlocations-view-map.tpl -->
    <?php endif; ?>
  </div>
</div>
