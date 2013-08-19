<?php
$theme_path = base_path() . path_to_theme();

$default_img = $theme_path . '/images/no-image.png';
$standard_image_jpg = "/bir-api/node/{$fields['standard_image']->content}.jpg";
$standard_image_jpeg = "/bir-api/node/{$fields['standard_image']->content}.jpeg";

$full = !empty($fields['standard_image']->content) ? $standard_image_jpg : $default_img;
$full2 = !empty($fields['standard_image']->content) ? $standard_image_jpeg : $default_img;
?>
<div class="single-node">
  <h2 class="single-node-title">Specimen Record: [<?php print $fields['nid']->content; ?>] <?php print $fields['title']->content; ?>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  <!-- Annotate --><a href="#"><img src="<?php print $theme_path . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>&nbsp;&nbsp;
  <!-- Print --><a href="#"><img src="<?php print $theme_path . '/' ?>images/printer.png" alt="Print" border="0"/></a>&nbsp;&nbsp;
  </h2>
  <div class="single-node-page-left">
    <h4>Specimen Information</h4>
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
          <?php print $fields['field_first_name_2']->content; ?>&nbsp;<?php print $fields['field_last_name_2']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_2']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
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
      <li>
        <span class="list-label">Basis of Record:</span>
        <?php print $fields['basis_of_record']->content; ?>
      </li>
      <li>
        <span class="list-label">Sex:</span>
        <?php print $fields['sex']->content; ?>
      </li>
      <li>
        <span class="list-label">Type status:</span>
        <?php print $fields['type_status']->content; ?>
      </li>
      <li>
        <span class="list-label">Preparation type:</span>
        <?php print $fields['preparation_type']->content; ?>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li>
        <span class="list-label">Development stage:</span>
        <?php print $fields['developmental_stage']->content; ?>
      </li>
      <li>
        <span class="list-label">No of Individuals:</span>
        <?php print $fields['individual_count']->content; ?>
      </li>
      <li>
        <span class="list-label">Form:</span>
        <?php print $fields['form']->content; ?>
      </li>
    </ul>
    <div class="clearfix"></div>
    <h4>Names & Determinations</h4>
    <ul class="two-col-tab-left">
      <li>
        <span class="list-label">Determination scientific name: </span>
        <?php print $fields['scientific_name']->content; ?>
      </li>
      <li>
        <span class="list-label">Determination name source: </span>
        <?php print $fields['name_source']->content; ?>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li>
        <span class="list-label">Determined by: </span>
        <?php print $fields['individual_name']->content; ?>
      </li>
      <li>
        <span class="list-label">Date determined: </span>
        <?php print $fields['date_identified']->content; ?>
      </li>
    </ul>
    <ul class="one-col">
      <li>
        <span class="list-label">Citation: </span>
        <a href="#"><img src="<?php print base_path() . path_to_theme() . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>
        <?php print $fields['citation']->content; ?>
      </li>
      <li>
        <span class="list-label">Determiner comment: </span>
        <?php print $fields['determination_comment']->content; ?>
      </li>
      <li>
        <span class="list-label">Determination: </span><a href="#"><img src="<?php print base_path() . path_to_theme() . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>
        <br />
        <?php
        $taxon_array = unserialize($fields['taxon_hierarchy']->content);
        $left_list = '';
        $right_list = '';
        if (!empty($taxon_array)) {
          $i = 0;
          foreach ($taxon_array as $taxon => $name) {
            $left_list .= ($i % 2 == 0) ? "<li>$taxon: $name</li>" : "";
            $right_list .= ($i % 2 != 0) ? "<li>$taxon: $name</li>" : "";
            $i++;
          }
        }
        ?>
        <ul class="two-col-tab-left">
        <?php print $left_list; ?>
        </ul>
        <ul class="two-col-tab-right">
        <?php print $right_list; ?>
        </ul>
      </li>
    </ul>
    <div class="clearfix"></div>
    <h4>Collection information</h4>
    <ul class="two-col-tab-left">
      <li>
        <span class="list-label">Collector name: </span>
        <?php print $fields['collector_name']->content; ?>
      </li>
      <li>
        <span class="list-label">Date collected: </span>
        <?php print $fields['date_collected']->content; ?>
      </li>
      <li>
        <span class="list-label">Earliest date collected: </span>
        <?php print $fields['earliest_date_collected']->content; ?>
      </li>
      <li>
        <span class="list-label">Latest date collected: </span>
        <?php print $fields['latest_date_collected']->content; ?>
      </li>
      <li>
        <span class="list-label">Collection Code: </span>
        <?php print $fields['collection_code']->content; ?> / <?php print $fields['collection_number']->content; ?>
      </li>
    </ul>
    <ul class="two-col-tab-right">
      <li>
        <span class="list-label">Institution Code: </span>
        <?php print $fields['institution_code']->content; ?>
      </li>
      <li>
        <span class="list-label">Cataloge No: </span>
        <?php print $fields['catalog_number']->content; ?>
      </li>
      <li>
        <span class="list-label">Previous Catalouge No: </span>
        <?php print $fields['previous_catalog_number']->content; ?>
      </li>
      <li>
        <span class="list-label">Related catalog item: </span>
        <?php print $fields['related_catalog_item']->content; ?>
      </li>
      <li>
        <span class="list-label">Relationship Type: </span>
        <?php print $fields['relationship_type']->content; ?>
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
        <?php if ($fields['name_2']->content != 'Anonymous' && !empty($fields['name_2']->content)): ?>
        <a href="/profile/<?php print $fields['name_2']->content; ?>">
          <?php print $fields['field_first_name_3']->content; ?>&nbsp;<?php print $fields['field_last_name_3']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
        <?php endif; ?>
      </li>
      <li>
        <span class="list-label">Contributer: </span>
        <?php if ($fields['name_1']->content != 'Anonymous' && !empty($fields['name_1']->content)): ?>
        <a href="/profile/<?php print $fields['name_1']->content; ?>">
          <?php print $fields['field_first_name_1']->content; ?>&nbsp;<?php print $fields['field_last_name_1']->content; ?>
        </a>
        &nbsp;
        <a href="mailto:<?php print $fields['mail_1']->content; ?>"><img src="<?php print $theme_path . '/' ?>images/email.png" alt="Email" border="0" align="absmiddle"/></a>
        <?php endif; ?>
      </li>
      <li>
        <span class="list-label">Date Submitted: </span>
        <?php print $fields['created']->content; ?>
      </li>
      <li>
        <span class="list-label">Last modified date: </span>
        <?php print $fields['changed']->content; ?>
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
        <a href="/bir-api/node/<?php print $fields['standard_image']->content; ?>.jpeg"  target="_blank">Full size</a>
        <a href="/bir-api/node/<?php print $fields['standard_image']->content; ?>.jpg"  target="_blank">Medium size</a>
      </li>
    </ul>
  </div>
</div>

