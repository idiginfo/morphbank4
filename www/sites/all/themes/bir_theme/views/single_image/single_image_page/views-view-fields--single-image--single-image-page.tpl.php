<?php
$theme_path = base_path() . path_to_theme();
$full = "/bir-api/node/{$fields['nid']->content}.jpg";
$full2 = "/bir-api/node/{$fields['nid']->content}.jpeg";
?>

<div class="single-node">
  <h2 class="single-node-title">Image: [ <?php print $fields['title']->content; ?> ]
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <!-- Annotate --><a href="#"><img src="<?php print $theme_path . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>&nbsp;&nbsp;
  <!-- Print --><a href="#"><img src="<?php print $theme_path . '/' ?>images/printer.png" alt="Print" border="0"/></a>&nbsp;&nbsp;
  </h2>
  <div class="single-node-page-left">
    <h4>Image Information</h4>
    <ul class="two-col-tab-left">
      <li>
        <span class="list-label">Submitted By:</span>
        <a href="/profile/<?php print $fields['name']->content; ?>">
          <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
      </li>
      <li>
        <span class="list-label">Contributor:</span>
        <a href="/profile/<?php print $fields['contributor']->content; ?>">
          <?php print $fields['field_first_name_1']->content; ?>&nbsp;<?php print $fields['field_last_name_1']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_1']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li>
        <span class="list-label">Date Submitted:</span>
        <?php print $fields['created']->content; ?>
      </li>
      <li>
        <span class="list-label">Last modified date:</span>
        <?php print $fields['changed']->content; ?>
      </li>
    </ul>
    <div class="clearfix"></div>
    <ul class="two-col-tab-left">
      <li><h4>Image File</h4></li>
      <li>
        <span class="list-label">Original File Name:</span>
        <?php print $fields['original_file_name']->content; ?>
      </li>
      <li>
        <span class="list-label">Width:</span>
        <?php print $fields['image_width']->content; ?>
      </li>
      <li>
        <span class="list-label">Height:</span>
        <?php print $fields['image_height']->content; ?>
      </li>
      <li>
        <span class="list-label">Resolution:</span>
        <?php print $fields['resolution']->content; ?>
      </li>
      <li>
        <span class="list-label">EOL Listing:</span>
        <?php print $fields['eol']->content == 1 ? 'Yes' : 'No'; ?>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li><h4>Licensing Information</h4></li>
      <li>
        <span class="list-label">Photographer:</span>
        <?php print $fields['photographer']->content; ?>
      </li>
      <li>
        <span class="list-label">Download: </span>
        <a href="<?php print $full2; ?>.jpeg"  target="_blank">Full size</a>
        <a href="<?php print $full ?>.jpg"  target="_blank">Medium size</a>
      </li>
      <li>
        <span class="list-label">Copyright: </span>
        <?php print $fields['copyright_text']->content; ?></a>
      </li>
      <li>
        <span class="list-label">License type: </span>
        <?php
          $CCval = $fields['creative_commons']->content;
          echo html_entity_decode($CCval, ENT_COMPAT, 'ISO-8859-1');
        ?>  
      </li>
    </ul>
  </div>
  <div class="single-node-page-right">
    <a rel="shadowbox;title=Title: <?php print $fields['title']->raw; ?>;" href="<?php print $full2 ?>"><img src="<?php print $full ?>" alt="" class="border single-node-image" /></a>
    <br />
    <!-- Help --><a href="#"><img src="<?php print $theme_path . '/' ?>images/help.png" alt="Help Text" border="0" align="texttop"/></a>
  </div>
</div>