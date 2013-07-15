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
<div class="single-node">
  <?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php foreach ($rows as $id => $row): ?>
    <div class="<?php print $classes_array[$id]; ?>">
      <?php print $row; ?>
    </div>
  <?php endforeach; ?>
  <?php 
  $lat = $variables['view']->result[0]->node_getlocations_fields_entities__getlocations_fields_latit;
  $lng = $variables['view']->result[0]->node_getlocations_fields_entities__getlocations_fields_longi;
  if (!empty($lat) && !empty($lng)) {
  ?>
  <!-- getlocations-view-map.tpl -->
  <div class="getlocations_map_wrapper getlocations_float">
  <?php print $map; ?>
  </div>
  <!-- /getlocations-view-map.tpl -->
  <?php } ?>
</div>