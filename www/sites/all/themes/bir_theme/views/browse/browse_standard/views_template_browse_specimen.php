
<!-- View template for bir browse - BIR Image -->


<tr>
<td width="100%">
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']->content; ?>" />
<strong>Specimen [<?php print $fields['nid']->content; ?>] <a href="/specimen/<?php print $fields['nid']->content; ?>"><?php print $fields['title']->content; ?></strong></a>
&nbsp;-&nbsp; <a href="<?php print $edit_url ?>/edit">Edit</a><br />
<font size="-2">
<strong>Scientific name</strong>: <?php print $fields['scientific_name_1']->content; ?> - <strong>Form</strong>: <?php print $fields['form']->content; ?> - <strong>Sex</strong>: <?php print $fields['sex']->content; ?><br />
<strong>Basis of record</strong>: <?php print $fields['basis_of_record']->content; ?><br />
<strong>Catalog number</strong>: <?php print $fields['catalog_number']->content; ?><br />
<strong>Collector name</strong>: <?php print $fields['collector_name']->content; ?><br />
<strong>Submitted By</strong>:
  <a href="/profile/<?php print $fields['author']->content; ?>">
  <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
  </a>
<br />
<strong>Date created</strong>: <?php print $fields['created']->content; ?><br />
<strong>No. Images</strong>: <?php print $fields['image_count']->content; ?>
<?php if ($fields['image_count']->content > 0) { ?>
- <a href="/specimen-images/<?php print $fields['nid']->content; ?>?format=simple" rel="shadowbox;height=768;width=1024;">View Images</a>
<?php } ?>
</font>
<td></td>
</td>
<td width="400">
  <a rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full4 ?>"><img src="<?php print $full3 ?>" alt="" class="border"/></a>
</td>
</tr>