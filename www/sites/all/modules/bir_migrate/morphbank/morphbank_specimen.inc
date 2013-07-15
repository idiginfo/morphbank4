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

    $columns = array(
      // "Source": ('Fieldname', 'Description')
      0 => array('id', t('Occurence ID')), // furi
      1 => array('group', t('Paleogroup')), // not used: Paleogroup
      2 => array('lifeStage', t('Developmental Stage')), // drupal: developmental_stage tid
      3 => array('nomenclaturalStatus', t('Status of nomenclature')), // not used: taxon.status
      4 => array('recordNumber', t('Collection number')), // drupal: collection_number
      5 => array('recordedBy', t('Individual recording occurence')), // drupal: collector_name
      6 => array('fieldNotes', t('Field notes')), // not used: uFN
      7 => array('kingdom', t('Kingdom of occurence')), // Not used: kingdom
      8 => array('minimumElevationInMeters', t('Minimum elevation in meteres')), // drupal: min_elevation
      9 => array('basisOfRecord', t('Basis of record')), // drupal: basis_of_record tid
      10 => array('coordinatePercision', t('Coordinate percision')), // drupal: coordinate_precision
      11 => array('sex', t('Sex of occurence')), // drupal: sex by tid
      12 => array('taxonRank', t('Taxon rank')), // not used
      13 => array('individualCount', t('Individual count of the specimen')), // drupal: individual_count
      14 => array('verbatimEventDate', t('Not used')), // not used: uVED
      15 => array('scientificName', t('Scientific name for occurence')), // drupal: scientific_name by tid
      16 => array('maximumDepthInMeters', t('Maximum depth in meters')), // drupal: max_depth
      17 => array('bed', t('Paleobed')), // not used: Paleobed.
      18 => array('collectionCode', t('Collection code for specimen')), // drupal: collection_code.
      19 => array('preparations', t('Preparation type')), // drupal: preparation_type by tid.
      20 => array('country', t('Country of specimen')), // geolocation.
      21 => array('verbatimLongitude', t('Longitude of specimen')), // geolocation.
      22 => array('identificationRemarks', t('Determination comment')), // drupal: determination_comment.
      23 => array('specimenRemarks', t('Notes about specimen')), // drupal: notes.
      24 => array('member', t('Paleomember')), // not used: Paleomember.
      25 => array('locationID', t('Location of specimen')), // if a locality exists?
      26 => array('locality', t('Name of locality')), // if a locality exists?
      27 => array('continent', t('Continent of specimen')), // drupal: continent_ocean tid.
      28 => array('identifiedBy', t('Individual identifying specimen')), // drupal: individual_name.
      29 => array('language', t('Language of record')), // not used.
      30 => array('institutionCode', t('Institution code')), // drupal: institution_code.
      31 => array('scientificNameAuthorship', t('Author of scientific name')), // not used.
      32 => array('maximumElevationInMeters', t('Maximum elevation in meters')), // drupal: max_elevation.
      33 => array('otherCatalogNumbers', t('Other catalog numbers')), // drupal: previous_catalog_number.
      34 => array('formation', t('Paleoformation')), // not used: Paleoformation.
      35 => array('stateProvince', t('State/Provice of specimen')), // geolocation.
      36 => array('typeStatus', t('Type status of specimen')), // drupal: type_status.
      37 => array('informationWithheld', t('Information withheld')), // not used.
      38 => array('waterBody', t('Ocean associated with specimen')), // continent_ocean tid.
      39 => array('catalogNumber', t('Specimen catalog number')), // drupal: catalog_number.
      40 => array('minimumDepthInMeters', t('Minimum depth in meters')), // drupal: min_depth.
      41 => array('dateIdentified', t('Date identified')), // drupal: date_identified.
      42 => array('verbatimLatitude', t('Locality latitude')), // drupal: latitude.
      43 => array('type', t('Speciment type (collection)')), // not used: collection is default.
      44 => array('eventDate', t('Date specimen collected')), // drupal: date_collected.
      45 => array('county', t('County of location')), // geolocation.
      46 => array('modified', t('Date last modified')), // drupal node: changed.
    );

    // TIP: delete ", array('header_rows' => 1)" in the next line,
    // if the CSV-file has NO header-line.
    $this->source = new MigrateSourceCSV(
        DRUPAL_ROOT . '/' . drupal_get_path('module', 'bir_migrate') . '/data_sources/occurrence.csv',
        $columns, array('header_rows' => 1)
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
    $this->addFieldMapping('furi', 'id');
    $this->addFieldMapping('furi:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('developmental_stage', 'lifeStage')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('collection_number', 'recordNumber');
    $this->addFieldMapping('collection_number:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('collector_name', 'recordedBy');
    $this->addFieldMapping('collector_name:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('min_elevation', 'minimumElevationInMeters')->defaultValue(NULL);
    $this->addFieldMapping('basis_of_record', 'basisOfRecord')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('coordinate_precision', 'coordinatePercision');
    $this->addFieldMapping('sex', 'sex')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('individual_count', 'individualCount');
    $this->addFieldMapping('scientific_name', 'scientificName')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('max_depth', 'maximumDepthInMeters');
    $this->addFieldMapping('collection_code', 'collectionCode');
    $this->addFieldMapping('collection_code:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('preparation_type', 'preparations')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('preparation_type:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('determination_comment', 'identificationRemarks');
    $this->addFieldMapping('determination_comment:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('notes', 'specimenRemarks');
    $this->addFieldMapping('notes:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('continent_ocean', 'continent')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
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

    // Basic mappings needed.
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('revision_uid')->defaultValue(1);

    $this->addFieldMapping('title', 'scientificName')->defaultValue('');
    $this->addFieldMapping('created')->defaultValue(time());
    $this->addFieldMapping('status')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('tnid')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('language')->defaultValue('und');

    // Do not map destination.
    $this->addUnmigratedDestinations(array(
      'log', 'is_new', 'group_content_access', 'basis_of_record:source_type',
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
      'latest_date_collected', 'taxon_author_id', 'publication_id', 'taxon_hierarchy',
      'taxon_hierarchy:language', 'continent_ocean:source_type', 'continent_ocean:create_term',
      'continent_ocean:ignore_case', 'image_count', 'locality_id', 'contributor',
      'locality_title', 'locality_title:language', 'og_group_ref', 'standard_image',
      'geolocation', 'external_links', 'external_references',
    ));

    // Do not map source.
    $this->addUnmigratedSources(array(
      'group', 'nomenclaturalStatus', 'fieldNotes', 'kingdom', 'taxonRank',
      'verbatimEventDate', 'bed', 'country', 'verbatimLongitude', 'member',
      'locationID', 'locality', 'language', 'scientificNameAuthorship',
      'formation', 'stateProvince', 'informationWithheld', 'waterBody',
      'verbatimLatitude', 'type', 'county',
    ));

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
    // Remove empty values
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
