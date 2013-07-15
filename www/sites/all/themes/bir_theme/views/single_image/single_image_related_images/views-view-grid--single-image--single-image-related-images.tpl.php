<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="single-node">
  <h2 class="single-node-title">Related Images</h2>
  <table class="<?php print $class; ?>"<?php print $attributes; ?>>
    <tbody>
      <?php foreach ($rows as $row_number => $columns): ?>
        <tr class="<?php print $row_classes[$row_number]; ?>">
          <?php foreach ($columns as $column_number => $item): ?>
            <td class="<?php print $column_classes[$row_number][$column_number]; ?>">
              <?php print $item; ?>
            </td>
          <?php endforeach; ?>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
</div>