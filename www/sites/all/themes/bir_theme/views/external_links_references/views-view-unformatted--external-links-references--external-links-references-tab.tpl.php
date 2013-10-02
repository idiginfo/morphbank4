<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="single-node">
  <?php
  $fields = $view->style_plugin->rendered_fields;
  $external_links = "";
  $external_references = "";
  foreach ($fields as $field) {
    while (list($key, $val) = each($field)) {
      list(,$type,) = explode('_', $key);
      $external_links .= $type == 'link' ? "<td>$val</td>" : "";
      $external_references .= $type == 'reference' ? "<td>$val</td>" : "";
    }
    $external_links = !empty($external_links) ? "<tr>$external_links</tr>" : "";
    $external_references .= !empty($external_references) ? "<tr>$external_references</tr>" : "";
  }
  ?>
  <table class="links-references">
     <thead>
      <tr><th><h4>External Links</h4></th></tr>
    </thead>
    <tbody>
      <tr>
        <th width="15%">Type</th>
        <th width="25%">Label</th>
        <th width="25%">Url</th>
        <th width="35%">Description</th>
      </tr>
      <?php print $external_links; ?>
    </tbody>
  </table>
  <table class="links-references">
     <thead>
      <tr><th><h4>External References</h4></th></tr>
    </thead>
    <tbody>
      <tr>
        <th>Id</th>
        <th>Description</th>
      </tr>
      <?php print $external_references; ?>
    </tbody>
  </table>
</div>