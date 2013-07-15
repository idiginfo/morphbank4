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
$fields = $view->style_plugin->rendered_fields[0]; 
?>
<div class="single-node">
  <h2 class="single-node-title">Locality</h2>
  <ul class="two-col-tab-left">
    <li>
      <span class="list-label">Locality Template Title: </span>
      <?php print $fields['locality_title']; ?>
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
  <?php if (!empty($fields['latitude']) && !empty($fields['longitude'])): ?>
  <!-- getlocations-view-map.tpl -->
  <div class="getlocations_map_wrapper getlocations_float">
  <?php print $map; ?>
  </div>
  <!-- /getlocations-view-map.tpl -->
  <?php endif; ?>
</div>
