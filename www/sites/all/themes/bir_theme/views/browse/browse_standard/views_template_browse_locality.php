
<!-- View template for bir browse - BIR Image -->


<tr>
<td width="100%">
<input type="checkbox" name="nid[]" value="<?php echo $fields['nid']->content; ?>" />
<strong><a href="/locality/<?php print $fields['nid']->content; ?>"><?php print $fields['title']->content; ?></strong></a>
&nbsp;-&nbsp; <a href="<?php print $edit_url ?>/edit">Edit</a><br /><font size="-2">
<strong>Continent/Ocean:</strong> <?php print $fields['continent_ocean']->content; ?>&nbsp;
<strong>Country:</strong> <?php print $fields['geolocation_country']->content; ?>&nbsp;&nbsp;
<strong>State/Province/County:</strong> <?php print $fields['geolocation_province']->content; ?><br />
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
</font>
</font>
</td>
<td></td>
<td width="400" align="right">
  <a rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full4 ?>"><img src="<?php print $full3 ?>" alt="" class="border"/></a>
</td>
</tr>

