
<tr>
<td width="100%">
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']->content; ?>" />
<strong><a href="/view/<?php print $fields['nid']->content; ?>"><?php print $fields['title']->content; ?></strong></a>
&nbsp;-&nbsp; <a href="<?php print $edit_url ?>/edit">Edit</a><br />
<font size="-2">
<strong>View angle</strong>: <?php print $fields['view_angle']->content; ?><br />
<strong>Imaging technique</strong>: <?php print $fields['imaging_technique']->content; ?><br />
<strong>Preparation technique</strong>: <?php print $fields['imaging_preparation_technique']->content; ?><br />
<strong>Specimen part</strong>: <?php print $fields['specimen_part']->content; ?><br />
<strong>Sex</strong>: <?php print $fields['sex']->content; ?><br />
<strong>Form</strong>: <?php print $fields['form']->content; ?><br />
<strong>Contributor</strong>: 
  <a href="/profile/<?php print $fields['contributor']->content; ?>">
  <?php print $fields['field_first_name_1']->content; ?>&nbsp;<?php print $fields['field_last_name_1']->content; ?>
  </a>
  &nbsp;-&nbsp;<strong>Group</strong> <?php print $fields['og_group_ref']->content; ?>
<br />
<strong>Submitted By</strong>: 
  <a href="/profile/<?php print $fields['author']->content; ?>">
  <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
  </a>
<br />
<strong>Date created</strong>: <?php print $fields['created']->content; ?><br />
<strong>No. Images:</strong> <?php print $fields['image_count']->content; ?>
<?php if ($fields['image_count']->content > 0) { ?>  
- <a href="view-images/<?php print $fields['nid']->content; ?>?format=simple" rel="shadowbox;height=768;width=1024;">View Images</a>
<?php } ?>
</font> 
</font>
<td></td>
</td>
<td width="400">
  <a rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full4 ?>"><img src="<?php print $full3 ?>" alt="" class="border"/></a>
</td>
</tr>