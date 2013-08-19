<tr>
<td width="100%">
<strong><a href="/album/<?php print $fields['nid']->content; ?>"><?php print $fields['title']->content; ?></strong></a>
&nbsp;-&nbsp; <a href="<?php print $edit_url ?>/edit">Edit</a><br />
<font size="-2">
<strong>Submitted By</strong>: 
  <a href="/profile/<?php print $fields['author']->content; ?>">
  <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
  </a>
  &nbsp;-&nbsp;<strong>Date created</strong>: <?php print $fields['created']->content; ?><br />
<strong>No. Images:</strong> <?php print $fields['image_count']->content; ?>
<?php if ($fields['image_count']->content > 0) { ?>  
- <a href="/album-images/<?php print $fields['nid']->content; ?>?format=simple" rel="shadowbox;height=768;width=1024;">View Images</a>
<?php } ?>
</font> 
</font>
</td>
<td></td>
<td width="400">
  <a rel="shadowbox[bir-gallery];title=Title: <?php print $fields['title']->content; ?>;" href="<?php print $full4 ?>"><img src="<?php print $full3 ?>" alt="" class="border"/></a>
</td>
</tr>
