<?php

/**
 * @file
 * Morphbank Image migration
 */

/**
 * Abstract class as a base for migration classes
 */
abstract class MorphbankImageMigration extends Migration {
  /**
   * Class constructor.
   */
  public function __construct() {
    // Always call the parent constructor first for basic setup.
    parent::__construct(MigrateGroup::getInstance('morphbank'));

    ini_set('auto_detect_line_endings', TRUE);
  }
}

class MorphbankImage extends MorphbankImageMigration {

	/**
	 * Construct.
	 */
  public function __construct() {
    // Because we're derived directly from migrationBase rather than,
    // AdvancedExampleMigration we must specify the group again here.
    parent::__construct();
    $this->dependencies = array('MorphbankSpecimen');
    $this->description = t('Migrate images from MB3 multimedia csv');

    // TIP: delete ", array('header_rows' => 1)" in the next line,
    // if the CSV-file has NO header-line
    $this->source = new MigrateSourceCSV(
        variable_get('bir_migration_image_file'),
        array(),
    		array('header_rows' => 1),
    		array('specimen_id' => 'Id of Specimen')
      );

    // "Machine name" of the image node type.
    $this->destination = new MigrateDestinationNode('bir_image');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'identifier'  => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Field mappings.
    $this->addFieldMapping('identifier', 'identifier');
    $this->addFieldMapping('identifier:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('specimen_id', 'id')->sourceMigration('MorphbankSpecimen');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('creative_commons', 'WebStatement');
    $this->addFieldMapping('creative_commons:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('copyright_text', 'Owner');
    $this->addFieldMapping('copyright_text:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('photographer', 'creator');
    $this->addFieldMapping('photographer:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('image_height', 'bestQualityExtent');
    $this->addFieldMapping('image_width', 'bestQualityExtent');
    $this->addFieldMapping('image_type', 'bestQualityFormat');
    $this->addFieldMapping('image_type:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('specimen_part', 'subjectPart')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('view_angle', 'subjectOrientation')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('imaging_preparation_technique', 'resourceCreationTechnique')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('imaging_technique', 'captureDevice')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('original_image_source', 'bestQualityAccessURI');
    $this->addFieldMapping('original_image_source:language')->defaultValue(LANGUAGE_NONE);

    // Basic mappings needed.
    $this->addFieldMapping('uid')->defaultValue(variable_get('bir_migration_user', 1));
    $this->addFieldMapping('revision_uid')->defaultValue(variable_get('bir_migration_user', 1));

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created')->defaultValue(time());
    $this->addFieldMapping('status', 'available')->defaultValue(variable_get('bir_migration_default_node_status', 1));
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('tnid')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('language')->defaultValue('und');


    // Do not map destination.
    $this->addUnmigratedDestinations(array(
      'log', 'is_new', 'field_image',
      'field_image:file_class', 'field_image:language',
      'field_image:destination_dir', 'field_image:destination_file',
      'field_image:file_replace', 'field_image:preserve_files',
      'field_image:source_dir', 'field_image:alt', 'field_image:title',
      'resolution', 'magnification', 'eol',
      'imaging_technique:source_type', 'imaging_technique:create_term',
      'imaging_technique:ignore_case',
      'imaging_preparation_technique:source_type',
      'imaging_preparation_technique:create_term',
      'imaging_preparation_technique:ignore_case',
      'specimen_part:source_type', 'specimen_part:create_term',
      'specimen_part:ignore_case', 'view_angle:source_type',
      'view_angle:create_term', 'view_angle:ignore_case', 'developmental_stage',
      'developmental_stage:source_type', 'developmental_stage:create_term',
      'developmental_stage:ignore_case', 'sex', 'sex:source_type',
      'sex:create_term', 'sex:ignore_case', 'form', 'form:source_type',
      'form:create_term', 'form:ignore_case', 'image_count',
      'view_id', 'view_title', 'view_title:language',
      'standard_image', 'external_links', 'external_references',
    ));

    // Do not map source.
    $this->addUnmigratedSources(array());


    // Other handlers.
    if (module_exists('path')) {
      $this->addFieldMapping('path')
           ->defaultValue(NULL)
           ->description(t('Path alias'));
    }
    if (module_exists('pathauto')) {
      $this->addFieldMapping('pathauto')
        ->defaultValue(1)
        ->description(t('Perform aliasing (set to 0 to prevent alias generation during migration)'));
    }

  }

  /**
   * Prepare
   */
  public function prepare($entity, stdClass $row) {
    // Remove empty values.
    bir_migrate_remove_empties($this->destination, $entity);
    // Split bestQualityExtent on h x w.
    bir_migrate_split_image_height_width($entity, $row);
  }

  /**
   * Prepare row
   */
  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Check if specimen uuid exists and skip if empty.
    $specimen_id = $this->handleSourceMigration('MorphbankSpecimen', $row->id);
    if (empty($specimen_id)) {
      $message = "No corresponding Specimen UUID for {$row->id}.";
      $this->queueMessage($message, 3);
      return FALSE;
    }

    // Set public or private.
    $row->available = strtotime($row->available) < time() ? 1 : 0;

    // Fix dates.
    bir_migrate_fix_date($row, array('modified'));
  }

  /**
   * Disable image module while importing to avoid hook_node_insert().
   */
  protected function preImport() {
    if (module_exists('bir_image')) {
      module_disable(array('bir_image'));
    }
  }

  /**
   * Enable image module after import.
   * Update search api index with new items.
   */
  protected function postImport() {
    if (!module_exists('bir_image')) {
      module_enable(array('bir_image', 'bir_album'));
    }
    bir_search_api_update_index();
  }
}
