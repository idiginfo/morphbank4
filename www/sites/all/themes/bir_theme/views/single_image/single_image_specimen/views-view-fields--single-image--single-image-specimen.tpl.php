<div class="single-node">
  <h2 class="single-node-title">Specimen</h2>
  <h4>Specimen Information</h4>
  <ul class="three-col-tab">
    <li>
      <span class="list-label">Specimen Record</span>
      <?php print $fields['specimen_id']->content; ?>
    </li>
    <li>
      <span class="list-label">Basis of Record:</span>
      <?php print $fields['basis_of_record']->content; ?>
    </li>
    <li>
      <span class="list-label">Sex:</span>
      <?php print $fields['sex']->content; ?>
    </li>
  </ul>
  <ul class="three-col-tab">
    <li>
      <span class="list-label">Type status:</span>
      <?php print $fields['type_status']->content; ?>
    </li>
    <li>
      <span class="list-label">Development stage:</span>
      <?php print $fields['developmental_stage']->content; ?>
    </li>
    <li>
      <span class="list-label">No of Individuals:</span>
      <?php print $fields['individual_count']->content; ?>
    </li>
  </ul>
  <ul class="three-col-tab">
    <li>
      <span class="list-label">Form:</span>
      <?php print $fields['form']->content; ?>
    </li>
    <li>
      <span class="list-label">Preparation type:</span>
      <?php print $fields['preparation_type']->content; ?>
    </li>
  </ul>
  <div class="clearfix"></div>
  
  <h4>Names & Determinations</h4>
  <ul class="three-col-tab">
    <li>
      <span class="list-label">Determination scientific name: </span>
      <?php print $fields['scientific_name']->content; ?>
    </li>
    <li>
      <span class="list-label">Determination name source: </span>
      <?php print $fields['name_source']->content; ?>
    </li>
    <li>
      <span class="list-label">Determiner comment: </span>
      <?php print $fields['determination_comment']->content; ?>
    </li>
  </ul>
  <ul class="three-col-tab">
    <li>
      <span class="list-label">Determined by: </span>
      <?php print $fields['individual_name']->content; ?>
    </li>
    <li>
      <span class="list-label">Date determined: </span>
      <?php print $fields['date_identified']->content; ?>
    </li>
    <li>
      <span class="list-label">Citation: </span>
      <a href="#"><img src="<?php print base_path() . path_to_theme() . '/' ?>images/comment.png" alt="Annoate" border="0"/></a>
      <?php print $fields['citation']->content; ?>
    </li>
  </ul>
  <ul class="three-col-tab">
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
</div>

