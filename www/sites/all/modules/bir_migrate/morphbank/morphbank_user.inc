<?php
/**
 * @file
 * Morphbank User migration
 */

/**
 * Abstract class as a base for migration classes
 */
abstract class MorphbankUserMigration extends Migration {
  /**
   * Class constructor.
   */
  public function __construct() {
    // Always call the parent constructor first for basic setup.
    parent::__construct(MigrateGroup::getInstance('morphbank'));

    ini_set('auto_detect_line_endings', TRUE);
  }
}

/**
 * Migration class.
 */
class MorphbankUser extends MorphbankUserMigration {

  /**
   * Class constructor.
   */
  public function __construct() {
    parent::__construct();
    $this->description = t('Migrate groups from MB3 database Group table');

    $this->destination = new MigrateDestinationUser();

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id'  => array(
          'type' => 'int',
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = Database::getConnection('default', 'mb32')->select('User', 'u');
    $query->leftJoin('BaseObject', 'bo', 'bo.userId = u.id');
    $query->fields('u', array('id', '', 'groupManagerId', 'status'))
      ->condition('g.id', 2, '!=')
      ->addExpression('UNIX_TIMESTAMP(bo.dateCreated)', 'created');

    $this->source = new MigrateSourceSQL($query, array(), NULL, array('map_joinable' => FALSE));

    // Connecting the group to the user:
    $this->addFieldMapping('uid', 'groupManagerId')->sourceMigration('MorphbankUser');

    $this->addFieldMapping('title', 'groupName')->defaultValue('');
    $this->addFieldMapping('group_group')->defaultValue(1);
    $this->addFieldMapping('group_access')->defaultValue(0);
    $this->addFieldMapping('created', 'created')->defaultValue(time());
    $this->addFieldMapping('status', 'status')->defaultValue(0);
    $this->addFieldMapping('comment')->defaultValue(0);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('tnid')->defaultValue(0);
    $this->addFieldMapping('translate')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(TRUE);
    $this->addFieldMapping('language')->defaultValue('und');

    // Do not map destination.
    $this->addUnmigratedDestinations(array(
      'changed',
      'log',
      'revision_uid',
      'is_new',
      'oldgid',
    ));

    // Do not map source.
    $this->addUnmigratedSources(array(
      'id',
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
   * Set correct value for group public/private.
   *
   * Morphbank: public = 1, private = 0.
   * OG: public = 0, private = 1.
   */
  public function prepareRow($row) {
    switch ($row->status) {
      case $row->status == 0:
        $row->status = 1;
        return;

      default:
        $row->status = 0;
        return;
    }
  }
}
