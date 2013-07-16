package org.idiginfo.mapping.dynamicField;

import java.util.List;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Query;
import javax.persistence.Table;
import javax.persistence.Transient;

import org.idiginfo.drupal.config.Config;

@Entity
@Table(name = Config.TABLE_PREFIX + "field_config_instance")
public class FieldConfigInstance {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Integer id;
	@ManyToOne()
	@JoinColumn(name = "field_id")
	FieldConfig config;
	@Column(name = "field_name")
	String fieldName;
	@Column(name = "entity_type")
	String entityType;
	String bundle;
	String data = "";
	Boolean deleted;

	private FieldConfigInstance() {
	}

	FieldConfigInstance(FieldConfig config, String bundle) {
		this.config = config;
		this.fieldName = config.fieldName;
		this.entityType = Config.ENTITY_TYPE;
		this.data = config.data;
		this.bundle = Config.BUNDLE_PREFIX + bundle;
		this.deleted = config.deleted;
	}

	@Transient
	static Query findByNameBundle = null;
	@Transient
	static String findByNameBundleSql = "select f from FieldConfigInstance f "
			+ "where f.fieldName=:name and f.bundle=:bundle";

	private static void init() {
		if (findByNameBundle == null) { // first occurrence
			findByNameBundle = Config.getEntityManager().createQuery(
					findByNameBundleSql);
		}

	}

	static FieldConfigInstance findByNameBundle(String name, String bundle) {
		if (name == null || name.length() == 0) return null;
		init();
		FieldConfigInstance field = null;
		findByNameBundle.setParameter("name", name);
		findByNameBundle.setParameter("bundle", Config.BUNDLE_PREFIX
				+ bundle);
		List result = findByNameBundle.getResultList();
		if (result == null || result.size() == 0) return null;
		return (FieldConfigInstance) result.get(0);
	}

	public FieldConfig getField() {
		return config;
	}

	public void setField(FieldConfig field) {
		this.config = field;
	}

	public String getFieldName() {
		return fieldName;
	}

	public void setFieldName(String fieldName) {
		this.fieldName = fieldName;
	}

	public String getEntityType() {
		return entityType;
	}

	public void setEntityType(String entityType) {
		this.entityType = entityType;
	}

	public String getBundle() {
		return bundle;
	}

	public void setBundle(String bundle) {
		this.bundle = bundle;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
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
}
