
<!-- View template for bir browse - BIR Image -->


<tr>
<td width="70%">
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']->content; ?>" />
<strong><a href="/image/<?php print $fields['nid']->content; ?>">
<?php print !empty($fields['title']->content) ? $fields['title']->content : 'View Details'; ?></a></strong>
&nbsp;-&nbsp; <a href="<?php print $edit_url ?>/edit">Edit</a><br />
<FONT SIZE="-2">
<strong>View</strong>: <?php print $fields['view_angle']->content; ?><br />
<strong>Specimen</strong>: <?php print $fields['specimen_part']->content; ?><br />
<strong>Scientific_name</strong>: <?php print $fields['scientific_name']->content; ?><br />
<strong>Technique</strong>: <?php print $fields['imaging_technique']->content; ?><br />
<strong>Submitted By</strong>:
  <a href="/profile/<?php print $fields['author']->content; ?>">
  <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
  </a>
<br />
<strong>Date Created</strong>:<?php print $fields['created']->content; ?>
</FONT>
</td>
<td width="30%">
<font size="-2">
<strong>Dimensions</strong>: <?php print $fields['image_width']->content; ?> x <?php print $fields['image_height']->content; ?><br />
<strong>Type</strong>: <?php print $fields['image_type']->content; ?><br />
<strong>Resolution</strong>: <?php print $fields['resolution']->content; ?><br />
<strong>Magnification</strong>: <?php print $fields['magnification']->content; ?>
</font>
</td>
<td width="400">
  <a rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full2 ?>"><img src="<?php print $full ?>" alt="" class="border"/></a>
</td>

</tr>
