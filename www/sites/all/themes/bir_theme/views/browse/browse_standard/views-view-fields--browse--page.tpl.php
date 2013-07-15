<?php

/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php
global $base_url;

$no_image = base_path() . path_to_theme() . '/images/no-image.png';
$node_thumb = "/bir-api/node/{$fields['nid']->content}.thumb";
$node_jpg = "/bir-api/node/{$fields['nid']->content}.jpg";
$standard_image_thumb = "/bir-api/node/{$fields['standard_image']->content}.thumb";
$standard_image_jpg = "/bir-api/node/{$fields['standard_image']->content}.jpg";

$full = !empty($fields['nid']->content) ? $node_thumb : $no_image;
$full2 = !empty($fields['nid']->content) ? $node_jpg : $no_image;

$full3 = !empty($fields['standard_image']->content) ? $standard_image_thumb : $no_image;
$full4 = !empty($fields['standard_image']->content) ? $standard_image_jpg : $no_image;

$edit_url = "/node/{$fields['nid']->content}";

/**
 * See bir_check_browse_access()
 * Check if user has premissions to view node data in browse.
 */
/*
$permission = bir_check_browse_access($fields['og_group_ref_1']->content, $fields['group_content_access']->content, $fields['type']->content);

if ($permission) {
  switch ($fields['type']->content) {
    case "bir_image":
      include("views_template_browse_image.php");
      break;
    case "bir_specimen":
      include("views_template_browse_specimen.php");
      break;
    case "bir_view":
      include("views_template_browse_view.php");
      break;
    case "bir_locality":
      include("views_template_browse_locality.php");
      break;
    case "bir_album":
      include("views_template_browse_album.php");
      break;
    default:
      echo "No template for " . $fields['type']->content;
  }
}
*/
switch ($fields['type']->content) {
    case "bir_image":
      include("views_template_browse_image.php");
      break;
    case "bir_specimen":
      include("views_template_browse_specimen.php");
      break;
    case "bir_view":
      include("views_template_browse_view.php");
      break;
    case "bir_locality":
      include("views_template_browse_locality.php");
      break;
    case "bir_album":
      include("views_template_browse_album.php");
      break;
    default:
      echo "No template for " . $fields['type']->content;
  }
?>