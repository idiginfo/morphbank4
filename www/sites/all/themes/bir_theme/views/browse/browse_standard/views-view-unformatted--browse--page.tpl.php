<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<style type="text/css">
<!--

-->

.tb1 tr:nth-of-type(odd) {
  background-color:#E9E9E9;
} 

</style>


<?php if (!empty($title)): ?>
  <!--<h3><?php print $title; ?></h3>-->
<?php endif; ?>

<table border="0" width="100%" id="tb1" class="tb1" cellpadding="4" cellspacing="0">

<?php foreach ($rows as $id => $row): ?>

    <?php print $row; ?>

<?php endforeach; ?>
</table>
