package org.idiginfo.mapping.dynamicField;

import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Query;
import javax.persistence.Table;
import javax.persistence.Transient;

import org.idiginfo.drupal.config.Config;

@Entity
@Table(name = Config.TABLE_PREFIX + "field_config")
public class FieldConfig {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Integer id;
	@Column(name = "field_name")
	String fieldName;
	String type;
	String module;
	Boolean active = true;
	@Column(name = "storage_type")
	String storageType = "field_sql_storage";
	@Column(name = "storage_module")
	String storageModule = "field_sql_storage";
	@Column(name = "storage_active")
	Boolean storageActive = true;
	Boolean locked = false;
	String data = "BLOB";
	Integer cardinality = 1;
	Boolean translatable = false;
	Boolean deleted = false;

	// a list of all of the field types, included for reference
	@Transient
	static String[] fieldTypes = { "text", "number_float", "number_integer",
			"datestamp", "list_integer", "bir_object_relation",
			"taxonomy_term_reference", "text_long", "text_with_summary" };
	// a list of all of the modules, included for reference
	@Transient
	static String[] modules = { "bir_object", "date", "list", "number",
			"taxonomy", "text" };

	@OneToMany(mappedBy = "config", fetch = FetchType.LAZY)
	List<FieldConfigInstance> instances;

	FieldConfig() {
	}

	FieldConfig(String fieldName, String type) {
		// map type and module from type of value parameter

		if (type == null) return;
		String lcType = type.toLowerCase();
		if (lcType.equalsIgnoreCase("double")) {
			this.type = "number_float";
			this.module = "number";
		} else if (lcType.equalsIgnoreCase("integer")) {
			this.type = "number_integer";
			this.module = "number";
		} else if (lcType.equalsIgnoreCase("string")) {
			this.type = "text_long";
			this.module = "text";
		} else if (lcType.equalsIgnoreCase("date")) {
			this.type = "datestamp";
			this.module = "date";
		} else if (lcType.equalsIgnoreCase("taxonomy")) {
			this.type = "taxonomy_term_reference";
			this.module = "taxonomy";
		} else if (lcType.equalsIgnoreCase("relationship")) {
			this.type = "bir_object_relation";
			this.module = "bir_object";
			// } else if (lcType.equalsIgnoreCase("text_long")){
			// } else if (lcType.equalsIgnoreCase("text_with_summary")){
		}
		// TODO add to database, create tables to hold field data

	}

	static String createTableSql1 = "CREATE TABLE ";
	// table name `PREFIX_FIELD`"
	static String createTableSql2 = " (  `entity_type` varchar(128) NOT NULL DEFAULT '' "
			+ "COMMENT 'The entity type this data is attached to',"
			+ "  `bundle` varchar(128) NOT NULL DEFAULT '' "
			+ "COMMENT 'The field instance bundle to which this row belongs, "
			+ "used when deleting a field instance',  "
			+ "`deleted` tinyint(4) NOT NULL DEFAULT '0' "
			+ "COMMENT 'A boolean indicating whether this data item has been deleted',  "
			+ "`entity_id` int(10) unsigned NOT NULL COMMENT 'The entity id this data is attached to',  "
			+ "`revision_id` int(10) unsigned DEFAULT NULL "
			+ "COMMENT 'The entity revision id this data is attached to, or NULL if the entity type is not versioned',  "
			+ "`language` varchar(32) NOT NULL DEFAULT '' "
			+ "COMMENT 'The language for this data item.',  "
			+ "`delta` int(10) unsigned NOT NULL "
			+ "COMMENT 'The sequence number for this data item, used for multi-value fields', ";

	// field name + " `FIELD_VALUE/TID` type" +
	static String createTableSql3 = "DEFAULT NULL, "
			+ " PRIMARY KEY (`entity_type`,`entity_id`,`deleted`,`delta`,";
	// key for revision table revisionid,
	static String createTableSql4 = "`language`),"
			+ " KEY `entity_type` (`entity_type`), "
			+ " KEY `bundle` (`bundle`), "
			+ " KEY `deleted` (`deleted`), "
			+ " KEY `entity_id` (`entity_id`), "
			+ " KEY `revision_id` (`revision_id`), "
			+ " KEY `language` (`language`)) ENGINE=InnoDB DEFAULT CHARSET=utf8 "
			+ "COMMENT='Data storage for field ";
	// field number
	static String createTableSql5 = " (max_elevation)'";

	@Transient
	static Query findByName = null;
	@Transient
	static String findByNameSql = "select f from FieldConfig f where f.fieldName=:name";

	private static void init() {
		if (findByName == null) { // first occurrence
			findByName = Config.getEntityManager()
					.createQuery(findByNameSql);
		}

	}

	static FieldConfig findByName(String name) {
		if (name == null || name.length() == 0) return null;
		init();
		FieldConfig field = null;
		findByName.setParameter("name", name);
		field = (FieldConfig) findByName.getSingleResult();
		return field;
	}

	public String getFieldName() {
		return fieldName;
	}

	public void setFieldName(String fieldName) {
		this.fieldName = fieldName;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public String getModule() {
		return module;
	}

	public void setModule(String module) {
		this.module = module;
	}

	public Boolean getActive() {
		return active;
	}

	public void setActive(Boolean active) {
		this.active = active;
	}

	public String getStorageType() {
		return storageType;
	}

	public void setStorageType(String storageType) {
		this.storageType = storageType;
	}

	public String getStorageModule() {
		return storageModule;
	}

	public void setStorageModule(String storageModule) {
		this.storageModule = storageModule;
	}

	public Boolean getStorageActive() {
		return storageActive;
	}

	public void setStorageActive(Boolean storageActive) {
		this.storageActive = storageActive;
	}

	public Boolean getLocked() {
		return locked;
	}

	public void setLocked(Boolean locked) {
		this.locked = locked;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public Integer getCardinality() {
		return cardinality;
	}

	public void setCardinality(Integer cardinality) {
		this.cardinality = cardinality;
	}

	public Boolean getTranslatable() {
		return translatable;
	}

	public void setTranslatable(Boolean translatable) {
		this.translatable = translatable;
	}

	public Boolean getDeleted() {
		return deleted;
	}

	public void setDeleted(Boolean deleted) {
		this.deleted = deleted;
	}

	public Integer getId() {
		return id;
	}

	public List<FieldConfigInstance> getInstances() {
		return instances;
	}

	public void addInstance(FieldConfigInstance instance) {
		if (instance != null) {
			instance.setField(this);
		}
	}

	public void removeInstance(FieldConfigInstance instance) {
		if (instance != null && instance.getField() == this) {
			instance.setField(null);
		}
	}
}
