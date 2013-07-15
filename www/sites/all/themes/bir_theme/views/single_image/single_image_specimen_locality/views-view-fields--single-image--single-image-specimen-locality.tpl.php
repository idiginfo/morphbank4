<h2 class="single-node-title">Locality</h2>
<ul class="two-col-tab-left">
  <li>
    <span class="list-label">Locality Template Title: </span>
    <?php print $fields['locality_title']->content; ?>
  </li>
  <li>
    <span class="list-label">Continent/Ocean: </span>
    <?php print $fields['continent_ocean']->content; ?>
  </li>
  <li>
    <span class="list-label">Country: </span>
    <?php print $fields['country']->content; ?>
  </li>
  <li>
    <span class="list-label">State/Province/County:</span>
    <?php print $fields['province']->content; ?>
  </li>
  <li>
    <span class="list-label">Latitude:</span>
    <?php print $fields['latitude']->content; ?>
  </li>
  <li>
    <span class="list-label">Longitude:</span>
    <?php print $fields['longitude']->content; ?>
  </li>
  <li>
    <span class="list-label">Lat/Lng Precision:</span>
    <?php print $fields['coordinate_precision']->content; ?>
  </li>
  <li>
    <span class="list-label">Depth:</span>
    <?php print $fields['max_depth']->content; ?> - <?php print $fields['min_depth']->content; ?>
  </li>
  <li>
    <span class="list-label">Elevation:</span>
    <?php print $fields['max_elevation']->content; ?><?php print $fields['min_elevation']->content; ?>
  </li>
</ul>