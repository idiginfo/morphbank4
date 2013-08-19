<?php
$theme_path = base_path() . path_to_theme();

$default_img = $theme_path . '/images/no-image.png';

$standard_image_jpg = "/bir-api/node/{$fields['standard_image']->content}.jpg";
$standard_image_jpeg = "/bir-api/node/{$fields['standard_image']->content}.jpeg";

$full = !empty($fields['standard_image']->content) ? $standard_image_jpg : $default_img;
$full2 = !empty($fields['standard_image']->content) ? $standard_image_jpeg : $default_img;

?>
<div class="single-node">
  <h2 class="single-node-title">Album Record: [ <?php print $fields['title']->content; ?> ]
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <!-- Annotate --><a href="#"><img src="<?php print $theme_path . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>&nbsp;&nbsp;
  <!-- Print --><a href="#"><img src="<?php print $theme_path . '/' ?>images/printer.png" alt="Print" border="0"/></a>&nbsp;&nbsp;
  </h2>
  <div class="single-node-page-left">
    <h4>Album Information</h4>
    <ul class="one-col">
      <li>
        <span class="list-label">Submitted By:</span>
        <a href="/profile/<?php print $fields['name']->content; ?>">
          <?php print $fields['field_first_name']->content; ?>&nbsp;<?php print $fields['field_last_name']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
      </li>
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
  </div>
  <div class="single-node-page-right">
    <a rel="shadowbox;title=Title: <?php print $fields['title_1']->raw; ?>;" href="<?php print $full2 ?>"><img src="<?php print $full ?>" alt="" class="border single-node-image" /></a>
    <br />
    <a href="#"><img src="<?php print $theme_path . '/' ?>images/help.png" alt="Help Text" border="0" align="texttop"/></a>
    <h4>Standard Image File</h4>
    <ul class="one-col">
      <li>
        <span class="list-label">Image Record: </span>
        <?php print $fields['title_1']->content; ?>
      </li>
      <li>
        <span class="list-label">Submitted By:</span>
        <?php if ($fields['name_1']->content != 'Anonymous' && !empty($fields['name_1']->content)): ?>
        <a href="/profile/<?php print $fields['name_1']->content; ?>">
          <?php print $fields['field_first_name_1']->content; ?>&nbsp;<?php print $fields['field_last_name_1']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_1']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
        <?php endif; ?>
      </li>
      <li>
        <span class="list-label">Contributer: </span>
        <?php if ($fields['name_2']->content != 'Anonymous' && !empty($fields['name_2']->content)): ?>
        <a href="/profile/<?php print $fields['name_2']->content; ?>">
          <?php print $fields['field_first_name_2']->content; ?>&nbsp;<?php print $fields['field_last_name_2']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_2']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
        <?php endif; ?>
      </li>
      <li>
        <span class="list-label">Date Submitted: </span>
        <?php print $fields['created_1']->content; ?>
      </li>
      <li>
        <span class="list-label">Last modified date: </span>
        <?php print $fields['changed_1']->content; ?>
      </li>
    </ul>
    <div class="clearfix"></div>
    <H4>Licensing Information</H4>
    <ul class="one-col">
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
      <li>
        <span class="list-label">Download: </span>
        <?php if (!empty($fields['standard_image']->content)): ?>
        <a href="/bir-api/node/<?php print $fields['standard_image']->content; ?>.jpeg"  target="_blank">Full size</a>
        <a href="/bir-api/node/<?php print $fields['standard_image']->content; ?>.jpg"  target="_blank">Medium size</a>
        <?php endif; ?>
      </li>
    </ul>
  </div>
</div>

