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

  public function __construct() {
    // Because we're derived directly from migrationBase rather than AdvancedExampleMigration,
    // we must specify the group again here.
    parent::__construct();
    $this->dependencies = array('MorphbankSpecimen');
    $this->description = t('Migrate images from MB3 multimedia csv');

    $columns = array(
      // "Source": ('Fieldname', 'Description')
      0 => array('id', t('Specimen occurence ID')), // specimen furi
      1 => array('bestQualityFurtherInformationURL', t('Information URL')), // not used
      2 => array('title', t('Title')), // drupal: node title
      3 => array('modified', t('Date last modified')), // drupal node: changed
      4 => array('identifier', t('FURI Identifier')), // drupal node: furi
      5 => array('subjectPart', t('Specimen Part')), // drupal: specimen_part tid
      6 => array('description', t('Image description')), // drupal: not used
      7 => array('mediumQualityFormat', t('Medium Quality Format')), // drupal: not used
      8 => array('subjectOrientation', t('Specimen Orientation')), // drupal: view_angle tid
      9 => array('nameAccordingTo', t('Name Source')), // drupal: name_source tid but not used?
      10 => array('WebStatement', t('Creative Commons')), // drupal: creative_commons
      11 => array('attributionLogoURL', t('User Logo')), // drupal: not used
      12 => array('thumbnailFormat', t('Thumbnail Format')), // drupal: not used
      13 => array('metadataCreator', t('Metadata Creator')), // drupal: not used
      14 => array('Owner', t('Copyright Text')), // drupal: copyright_text
      15 => array('associatedSpecimenReference', t('Associated Specimen Reference')), // drupal: not used
      16 => array('bestQualityAccessURI', t('Best Quality Access URI')), // drupal: not used
      17 => array('creator', t('Photographer')), // drupal: photographer
      18 => array('providerID', t('Group URL')), // drupal: not used
      19 => array('bestQualityExtent', t('Image heightand width')), // drupal: image_height & image_height
      20 => array('available', t('Date To Publish')), // drupal: if(available < now(), 1, 0) as public
      21 => array('tag', t('Specimen Part')), // drupal: already set via subjectPart.
      22 => array('resourceCreationTechnique', t('Image Preparation Technique')), // drupal: imaging_preparation_technique tid
      23 => array('rights', t('Rights')), // drupal: not used
      24 => array('bestQualityFormat', t('Best Quality Format')), // drupal: not used
      25 => array('type', t('Image Type')), // drupal: image_type
      26 => array('captureDevice', t('Imaging Technique')), // drupal: imaging_technique tid
      27 => array('providerManagedID', t('URL for image')), // drupal: not used
      28 => array('thumbnailAccessURI', t('Thumbnail URI')), // drupal: not used
      29 => array('metadataProvider', t('Metadata Provider')), // drupal: not used
      30 => array('mediumQualityAccessURI', t('Medium Quality URI')), // drupal: not used
      31 => array('licenseLogoURL', t('License Logo URL')), // drupal: not used
      32 => array('metadataLanguage', t('Metadata Langage')), // drupal: not used
      33 => array('provider', t('URL and Group Id')), // drupal: not used
      34 => array('specimen_id', t('Custom source field')), // drupal: not used
    );

    // TIP: delete ", array('header_rows' => 1)" in the next line, if the CSV-file has NO header-line
    $this->source = new MigrateSourceCSV(
        DRUPAL_ROOT . '/' . drupal_get_path('module', 'bir_migrate') . '/data_sources/multimedia.csv',
        $columns, array('header_rows' => 1)
      );

    // "Machine name" of the image node type.
    $this->destination = new MigrateDestinationNode('bir_image');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id_key'  => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    //$this->addFieldMapping('specimen_id', 'id')->sourceMigration('MorphbankSpecimen');

    // Field mappings
    $this->addFieldMapping('specimen_id', 'specimen_id');
    $this->addFieldMapping('changed', 'modified');
    $this->addFieldMapping('furi', 'identifier');
    $this->addFieldMapping('furi:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('creative_commons', 'WebStatement');
    $this->addFieldMapping('creative_commons:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('copyright_text', 'Owner');
    $this->addFieldMapping('copyright_text:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('photographer', 'creator');
    $this->addFieldMapping('photographer:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('image_height', 'bestQualityExtent'); // split from bestQualityExtent
    $this->addFieldMapping('image_width', 'bestQualityExtent'); // split from bestQualityExtent
    $this->addFieldMapping('image_type', 'type');
    $this->addFieldMapping('image_type:language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('specimen_part', 'subjectPart')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('view_angle', 'subjectOrientation')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('imaging_preparation_technique', 'resourceCreationTechnique')
        ->arguments(array('ignore_case' => true, 'create_term' => true));
    $this->addFieldMapping('imaging_technique', 'captureDevice')
        ->arguments(array('ignore_case' => true, 'create_term' => true));

    // Basic mappings needed
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('revision_uid')->defaultValue(1);

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('created')->defaultValue(time());
    $this->addFieldMapping('status', 'available')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('tnid')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('language')->defaultValue('und');


    // Do not map destination.
    $this->addUnmigratedDestinations(array(
      'log', 'is_new', 'group_content_access', 'field_image',
      'field_image:file_class', 'field_image:language',
      'field_image:destination_dir', 'field_image:destination_file',
      'field_image:file_replace', 'field_image:preserve_files',
      'field_image:source_dir', 'field_image:alt', 'field_image:title',
      'resolution', 'original_file_name', 'original_file_name:language',
      'magnification', 'eol',
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
      'view_id', 'contributor', 'view_title', 'view_title:language',
      'og_group_ref', 'standard_image', 'external_links', 'external_references',
    ));

    // Do not map source.
    $this->addUnmigratedSources(array(
      'id', 'bestQualityFurtherInformationURL', 'description',
      'mediumQualityFormat', 'nameAccordingTo', 'attributionLogoURL',
      'thumbnailFormat', 'metadataCreator', 'associatedSpecimenReference',
      'bestQualityAccessURI', 'providerID', 'bestQualityFormat',
      'providerManagedID', 'thumbnailAccessURI', 'metadataProvider',
      'mediumQualityAccessURI', 'licenseLogoURL', 'metadataLanguage',
      'provider', 'tag', 'rights',
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

  public function prepareKey($source_key, $row) {
    $key = array();
    $row->id_key = $row->id . '_' . $row->identifier;
    $key['id_key'] = $row->id_key;

    return $key;
  }

  /**
   * Prepare
   */
  public function prepare($entity, stdClass $row) {
    // Remove empty values
    bir_migrate_remove_empties($this->destination, $entity);
    // split bestQualityExtent on h x w.
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

    // Check if specimen uuid exists and skip if empty
    $row->specimen_id = $this->handleSourceMigration('MorphbankSpecimen',$row->id);
    if (empty($row->specimen_id)) {
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
