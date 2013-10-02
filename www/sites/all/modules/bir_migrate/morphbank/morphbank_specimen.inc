<?php

/**
 * @file
 * Morphbank Specimen migration
 */

/**
 * Abstract class as a base for migration classes
 */
abstract class MorphbankSpecimenMigration extends Migration {
  /**
   * Class constructor.
   */
  public function __construct() {
    // Always call the parent constructor first for basic setup.
    parent::__construct(MigrateGroup::getInstance('morphbank'));

    ini_set('auto_detect_line_endings', TRUE);
  }
}

class MorphbankSpecimen extends MorphbankSpecimenMigration {
  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate specimens from MB3 occurrence csv');

    // TIP: delete ", array('header_rows' => 1)" in the next line,
    // if the CSV-file has NO header-line.
    $this->source = new MigrateSourceCSV(
      variable_get('bir_migration_specimen_file'),
      array(),
      array('header_rows' => 1)
    );

    // "Machine name" of the specimen node type.
    $this->destination = new MigrateDestinationNode('bir_specimen');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id'  => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Field mappings.
    $this->addFieldMapping('identifier', 'id');
    $this->addFieldMapping('identifier:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('developmental_stage', 'lifeStage')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('collection_number', 'recordNumber');
    $this->addFieldMapping('collection_number:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('collector_name', 'recordedBy');
    $this->addFieldMapping('collector_name:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('min_elevation', 'minimumElevationInMeters')->defaultValue(NULL);
    $this->addFieldMapping('basis_of_record', 'basisOfRecord')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('coordinate_precision', 'coordinatePrecision');
    $this->addFieldMapping('sex', 'sex')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('individual_count', 'individualCount');
    $this->addFieldMapping('scientific_name', 'scientificName')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('max_depth', 'maximumDepthInMeters');
    $this->addFieldMapping('collection_code', 'collectionCode');
    $this->addFieldMapping('collection_code:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('preparation_type', 'preparations')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('preparation_type:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('determination_comment', 'identificationRemarks');
    $this->addFieldMapping('determination_comment:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('notes', 'occurrenceRemarks');
    $this->addFieldMapping('notes:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('continent_ocean', 'continent')
        ->arguments(array('ignore_case' => TRUE, 'create_term' => TRUE));
    $this->addFieldMapping('individual_name', 'identifiedBy');
    $this->addFieldMapping('individual_name:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('institution_code', 'institutionCode');
    $this->addFieldMapping('institution_code:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('max_elevation', 'maximumElevationInMeters');
    $this->addFieldMapping('previous_catalog_number', 'otherCatalogNumbers');
    $this->addFieldMapping('previous_catalog_number:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('type_status', 'typeStatus');
    $this->addFieldMapping('catalog_number', 'catalogNumber');
    $this->addFieldMapping('catalog_number:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('min_depth', 'minimumDepthInMeters');
    $this->addFieldMapping('date_identified', 'dateIdentified');
    $this->addFieldMapping('date_collected', 'eventDate');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('taxon_hierarchy', 'higherClassification');
    $this->addFieldMapping('taxon_hierarchy:language')->defaultValue(LANGUAGE_NONE);

    // Basic mappings needed.
    $this->addFieldMapping('uid')->defaultValue(variable_get('bir_migration_user', 1));
    $this->addFieldMapping('revision_uid')->defaultValue(variable_get('bir_migration_user', 1));

    $this->addFieldMapping('title', 'scientificName');
    $this->addFieldMapping('created')->defaultValue(time());
    $this->addFieldMapping('status')->defaultValue(variable_get('bir_migration_default_node_status', 1));
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('tnid')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('language')->defaultValue('und');

    // Do not map destination.
    $this->addUnmigratedDestinations(array(
      'log', 'is_new', 'basis_of_record:source_type',
      'basis_of_record:create_term', 'basis_of_record:ignore_case','sex:source_type',
      'sex:create_term', 'sex:ignore_case', 'form', 'form:source_type',
      'form:create_term', 'form:ignore_case', 'developmental_stage:source_type',
      'developmental_stage:create_term', 'developmental_stage:ignore_case',
      'type_status:source_type', 'type_status:create_term', 'type_status:ignore_case',
      'scientific_name:source_type', 'scientific_name:create_term', 'scientific_name:ignore_case',
      'name_source', 'name_source:source_type', 'name_source:create_term', 'name_source:ignore_case',
      'name_source_tmp', 'name_source_tmp:language', 'external_id', 'external_id:language', 'citation',
      'citation:language', 'related_catalog_item', 'related_catalog_item:language',
      'relationship_type', 'relationship_type:language', 'earliest_date_collected',
      'latest_date_collected', 'taxon_author_id', 'publication_id',
      'continent_ocean:source_type', 'continent_ocean:create_term',
      'continent_ocean:ignore_case', 'image_count', 'locality_id',
      'locality_title', 'locality_title:language', 'standard_image',
      'geolocation', 'external_links', 'external_references',
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
   * Prepare row.
   */
  public function prepare($entity, stdClass $row) {
    // Get specimen geolocation.
    bir_migrate_geolocation($entity, $row);
    // Remove empty values.
    bir_migrate_remove_empties($this->destination, $entity);
  }

  /**
   * Prepare row.
   */
  public function prepareRow($row) {
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->continent = !empty($row->continent) ?
        $row->continent : (!empty($row->waterBody) ? $row->waterBody : '');

    // Fix dates.
    bir_migrate_fix_date($row, array('dateIdentified', 'eventDate', 'modified'));
  }

  /**
   * Update search api index with new items.
   */
  protected function postImport() {
    bir_search_api_update_index();
  }
}
