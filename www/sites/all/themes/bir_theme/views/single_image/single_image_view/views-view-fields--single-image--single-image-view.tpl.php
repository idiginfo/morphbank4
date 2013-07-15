<div class="single-node">
  <h2 class="single-node-title">View</h2>
  <h4>View Information</h4>
  <ul class="one-col">
    <li>
      <span class="list-label">View Title: </span>
      <?php print $fields['view_title']->content; ?>
    </li>
  </ul>
  <ul class="two-col-tab-left">
    <li>
      <span class="list-label">Specimen part: </span>
      <?php print $fields['specimen_part']->content; ?>
    </li>
    <li>
      <span class="list-label">Sex:</span>
      <?php print $fields['sex']->content; ?>
    </li>
    <li>
      <span class="list-label">Development stage: </span>
      <?php print $fields['developmental_stage']->content; ?>
    </li>
    <li>
      <span class="list-label">Form: </span>
      <?php print $fields['form']->content; ?>
    </li>
  </ul>
  <ul class="two-col-tab-right">
    <li>
      <span class="list-label">Characters: </span>
      <br />
      Examples<br />
      Eyes black<br />
      Tail black<br />
      Beak black<br />
      Beak curved<br />
      Back olive<br />
      Breast yellow<br />
    </li>
  </ul>
  <div class="clearfix"></div>
  <h4>Image Preparation</h4>
  <ul class="two-col-tab-left">
    <li>
      <span>Imaging technique: </span>
      <?php print $fields['imaging_technique']->content; ?>
    </li>
    <li>
      <span class="list-label">Preparation technique: </span>
      <?php print $fields['imaging_preparation_technique']->content; ?>
    </li>
    <li>
      <span class="list-label">View angle: </span>
      <?php print $fields['view_angle']->content; ?>
    </li>
  </ul>
</div>

