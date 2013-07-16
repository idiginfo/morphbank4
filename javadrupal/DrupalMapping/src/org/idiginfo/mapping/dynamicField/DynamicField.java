package org.idiginfo.mapping.dynamicField;

import java.util.List;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.Query;

import org.idiginfo.drupal.config.Config;



/**
 * Class to manage values of dynamically created fields Use field_config and
 * field_config_instance to identify and manage field data table Use SQL to
 * manipulate values and specifications Note that the use of SQL implies direct
 * management of all CRUD operations
 * 
 * @author griccardi
 * 
 */
public class DynamicField {

	private String fieldName;
	private String bundle;
	private int entityId;
	Object[] row = null;
	Object value;
	String type;
	String valueExtension;// = "_nid";, "_value", "_tid" , "_gid"

	public Object getValue() {
		return value;
	}

	protected DynamicField(String fieldName, String type, String bundle, String valueExtension,
			int entityId, Object[] row) {
		this.fieldName = fieldName;
		this.bundle = bundle;
		this.entityId = entityId;
		this.row = row;
		this.type = type;
		this.valueExtension = valueExtension;
	}

	protected static DynamicField getField(String type, String fieldName,
			String bundle, int entityId) {
		if (type == null) return null;
		DynamicField field = null;
		// special case
		if (type.equalsIgnoreCase("float")) type = "double";

		if (type.equalsIgnoreCase("string")) {
			field = StringDynamicField.getField(fieldName, bundle, entityId);
		} else if (type.equalsIgnoreCase("integer")) {
			field = IntegerDynamicField.getField(fieldName, bundle, entityId);
		} else if (type.equalsIgnoreCase("date")) {
			field = DateDynamicField.getField(fieldName, bundle, entityId);
		} else if (type.equalsIgnoreCase("double")) {
			field = DoubleDynamicField.getField(fieldName, bundle, entityId);
		} else if (type.equalsIgnoreCase("taxonomy")) {
			field = TaxonomyDynamicField.getField(fieldName, bundle, entityId);
		} else if (type.equalsIgnoreCase("relationship")) {
			field = RelationshipDynamicField.getField(fieldName, bundle,
					entityId);
		} else if (type.equalsIgnoreCase("group")) {
			field = GroupDynamicField.getField(fieldName, bundle, entityId);
		}
		return field;
	}

	public static Object getValue(String type, String fieldName, String bundle,
			int entityId) {
		if (type == null) return null;
		DynamicField field = getField(type, fieldName, bundle, entityId);
		if (field != null) return field.getValue();
		return null;
	}

	public static void setValue(String type, String fieldName, String bundle,
			int entityId, Object value) {
		if (type == null) return;
		DynamicField field = getField(type, fieldName, bundle, entityId);
		if (field != null) field.setValue(value);
	}

	protected static Object[] getFieldRow(String fieldName, String bundle,
			int entityId) {
		try {
			String getFieldSql = "select * from " + Config.FIELD_DATA_PREFIX
					+ fieldName + " where bundle=? and entity_id=?";
			Query getFieldQuery = Config.getEntityManager()
					.createNativeQuery(getFieldSql);
			getFieldQuery.setParameter(1, Config.BUNDLE_PREFIX + bundle);
			getFieldQuery.setParameter(2, entityId);
			List<Object> result = getFieldQuery.getResultList();
			if (result == null || result.size() == 0) return null;
			return (Object[]) result.get(0);
		} catch (Exception e) {
			// problem with sql, maybe no such table
			e.printStackTrace(); // TODO get rid of this line
		}
		return null;
	}
	
	/**
	 * Get all objects that have currentObjectId as target of a relationship
	 * @param fieldName
	 * @param bundle
	 * @param currentObjectId
	 * @param currentObjectFieldName name of the field to use for finding objects, could be entity_id or bir_collection_node_nid
	 * @return
	 */
	protected static List<Object> getListOfObjects(String fieldName, String bundle,
			int currentObjectId, String currentObjectFieldName) {
		try {
			String getFieldSql = "select * from " + Config.FIELD_DATA_PREFIX
					+ fieldName + " where bundle=? and " + currentObjectFieldName +"=?";
			Query getFieldQuery = Config.getEntityManager()
					.createNativeQuery(getFieldSql);
			getFieldQuery.setParameter(1, Config.BUNDLE_PREFIX + bundle);
			getFieldQuery.setParameter(2, currentObjectId);
			List<Object> result = getFieldQuery.getResultList();
			if (result == null || result.size() == 0) return null;
			return result;
		} catch (Exception e) {
			// problem with sql, maybe no such table
			e.printStackTrace(); // TODO get rid of this line
		}
		return null;
	}

	protected static List<Object> getListOfObjects(String fieldName, String bundle,
			String currentObjectId, String currentObjectFieldName) {
		try {
			String getFieldSql = "select * from " + Config.FIELD_DATA_PREFIX
					+ fieldName + " where bundle=? and " + currentObjectFieldName +"=?";
			Query getFieldQuery = Config.getEntityManager()
					.createNativeQuery(getFieldSql);
			getFieldQuery.setParameter(1, Config.BUNDLE_PREFIX + bundle);
			getFieldQuery.setParameter(2, currentObjectId);
			List<Object> result = getFieldQuery.getResultList();
			if (result == null || result.size() == 0) return null;
			return result;
		} catch (Exception e) {
			// problem with sql, maybe no such table
			e.printStackTrace(); // TODO get rid of this line
		}
		return null;
	}
	
	protected Object[] getRow() {
		return row;
	}

	protected void setRow(Object[] row) {
		this.row = row;
	}

	public String getFieldName() {
		return fieldName;
	}

	public String getBundle() {
		return bundle;
	}

	public int getEntityId() {
		return entityId;
	}

	static final String update1 = "update " + Config.FIELD_DATA_PREFIX;
	static final String update2 = " set ";
	static final String update3 = " = ? where entity_id = ?";

	static final String insert1 = "insert into " + Config.FIELD_DATA_PREFIX;
	static final String insert2 = " (entity_type,bundle,entity_id,language,delta, ";
	static final String insert3 = ") values ('" + Config.ENTITY_TYPE
			+ "',?,?,'und',?,?)";

	public void setValue(Object value) {
		// check for instance of field/bundle
		// insert new row
		EntityManager em = Config.getEntityManager();

		// check for unnecessary update
		if (value == null && this.value == null) return;
		if (value != null && this.value != null) {
			// check if values are the same
			if (value.equals(this.value)) return;
		}
		this.value = value;
		EntityTransaction t = em.getTransaction();
		boolean localTransaction = false;
		try {
			if (!t.isActive()) {
				localTransaction = true;
				t.begin();
			}

			// update existing row
			if (row != null) {
				String updateSql = update1 + fieldName + update2 + fieldName
						+ valueExtension + update3;
				Query updateQuery = em.createNativeQuery(updateSql);
				updateQuery.setParameter(1, value);
				updateQuery.setParameter(2, entityId);
				int result = updateQuery.executeUpdate();
				if (result != 1) {
					// no update?
				}
				return;
			}

			// create new row
			// check for existing FieldDataConfig
			FieldConfigInstance configInstance = FieldConfigInstance
					.findByNameBundle(fieldName, bundle);
			if (configInstance == null) {
				// must create new config instance
				FieldConfig config = FieldConfig.findByName(fieldName);
				if (config == null) {
					// TODO create new config
					config = new FieldConfig(fieldName, type);
					// can't do it
					return;
				}
				configInstance = new FieldConfigInstance(config, bundle);
				em.persist(configInstance);
				em.flush();
			}
			// insert row
			String insertSql = insert1 + fieldName + insert2 + fieldName
					+ valueExtension + insert3;
			Query insertQuery = em.createNativeQuery(insertSql);
			insertQuery.setParameter(1, Config.BUNDLE_PREFIX + bundle);// bundle
			insertQuery.setParameter(2, entityId);// entity_id
			insertQuery.setParameter(3, 0);// delta
			insertQuery.setParameter(4, value);// value
			int result = insertQuery.executeUpdate();
			if (result != 1) {
				// no insert?
			}

			if (localTransaction) t.commit();
		} catch (Exception e) {
			e.printStackTrace();
			if (localTransaction) t.rollback();
		}
	}
}

// FieldConfigInstance configInstance =
// FieldConfigInstance.findByNameBundle(fieldName, bundle);
