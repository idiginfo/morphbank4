<?php
/**
 * This template is used to print a single field in a view. It is not
 * actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the
 * template is perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$fields = $view->style_plugin->rendered_fields;
$key = key($fields);
$content_type = $fields[$key]['type'];
$nid = $fields[$key]['nid'];

switch ($content_type) {
  case "bir_image":
    $path = "/image/$nid";
    break;
  case "bir_specimen":
    $path = "/specimen/$nid";
    $output = "Specimen[$nid]";
    break;
  case "bir_view":
    $path = "/view/$nid";
    break;
  case "bir_locality":
    $path = "/locality/$nid";
    break;
  case "bir_album":
    $path = "/album/$nid";
    break;
  default:
    echo "";
}
?>

<a href = "<?php print $path; ?>"><?php print $output ?></a>
