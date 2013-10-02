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
<!-- getlocations-view-map.tpl -->
<div class="getlocations_map_wrapper browse-map">
<?php print $map; ?>
</div>
<!-- /getlocations-view-map.tpl -->
<div class="browse-map-table">
<table class="tb1">
<?php
$field_array = $view->style_plugin->rendered_fields;
foreach ($field_array as $fields) {
  switch($fields['type']) {
    case 'bir_image':
      $path = "/image/{$fields['nid']}";
      break;
    case 'bir_specimen':
      $path = "/specimen/{$fields['nid']}";
      break;
    case 'bir_locality':
      $path = "/locality/{$fields['nid']}";
      break;
    case 'bir_view':
      $path = "/view/{$fields['nid']}";
      break;
    case 'bir_album':
      $path = "/album/{$fields['nid']}";
      break;
  }
  $edit = "/node/{$fields['nid']}/edit";
?>
<tr>
<td width="100%">
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']; ?>" />
<strong><a href="<?php print $path; ?>"><?php print $fields['title']; ?></strong></a>
&nbsp;-&nbsp; <a href="<?php print $edit ?>">Edit</a>
<br /><font size="-2">
<strong>Submitted By</strong>:
  <a href="/profile/<?php print $fields['author']; ?>">
  <?php print $fields['field_first_name']; ?>&nbsp;<?php print $fields['field_last_name']; ?>
  </a>
</font>
</font>
<br />
</td>
</tr>
<?php
}
?>
</table>
</div>
