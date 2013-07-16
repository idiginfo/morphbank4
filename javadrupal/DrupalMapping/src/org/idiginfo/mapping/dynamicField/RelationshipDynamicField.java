package org.idiginfo.mapping.dynamicField;

import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;

import javax.persistence.EntityManager;
import javax.persistence.EntityNotFoundException;
import javax.persistence.EntityTransaction;

import org.idiginfo.drupal.config.Config;
import org.idiginfo.drupal.objectInterface.BaseObject;



public class RelationshipDynamicField extends DynamicField {
	
	private static String valueExtension = "_nid";

	protected RelationshipDynamicField(String fieldName, String bundle, int id,
			Object[] row) {
		super(fieldName, "Integer", bundle, valueExtension, id, row);
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof Integer) {
				value = (Integer) (obj);
			} else if (obj instanceof Long) {
				value = Integer.valueOf(((Long) obj).intValue());
			}
		}
	}

	public static RelationshipDynamicField getField(String fieldName, String bundle,
			int entityId) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, entityId);
		return new RelationshipDynamicField(fieldName, bundle, entityId, row);
	}

	public static void setValue(String type, String fieldName, String bundle,
			int entityId, BaseObject relatedObject, Class objectClass) {
		if (relatedObject != null
				&& !objectClass.isInstance(relatedObject))
			throw new ClassCastException(
			"Object of type xxx cannot be cast to yyy");
		DynamicField.setValue(type, fieldName, bundle, entityId, relatedObject);
	}

	public BaseObject getValue() {
		if (value == null) {
			return null;
		}
		int localId = (Integer) value;
		Object relatedObject = Config.getFactory().getObject(localId);
		return (BaseObject) relatedObject;
	}

	@Override
	public void setValue(Object relatedObject) {
		if (relatedObject instanceof BaseObject) {
			super.setValue(((BaseObject) relatedObject).getId());
		} else if (relatedObject == null) {
			super.setValue(null);
		} else {
			throw new ClassCastException("not a baseobject");
		}
	}

	public static Object getValue(String fieldName, String bundle,
			int entityId, Class objectClass) {
		try {
		RelationshipDynamicField field = (RelationshipDynamicField) getField("Relationship", fieldName, bundle, entityId);
		Object relatedObject = field.getValue();
		if (relatedObject == null) {
			throw new javax.persistence.EntityNotFoundException(
				"No object of bundle " + bundle + " with entityId " + field.value ); 
		}
		if (relatedObject == null || objectClass.isInstance(relatedObject))
			return relatedObject;
		throw new ClassCastException("related object is of the wrong type");
		} catch(EntityNotFoundException e) {
			return null;
		}
	}
	
	/**
	 * getting objects that point to currentObjectId
	 * used for many direction of one-to-many relationship and the target-to-source direction of many-to-many relationships
	 * @param fieldName
	 * @param bundle
	 * @param currentObjectId
	 * @param objectClass
	 * @return
	 */
	public static Set<Object> getSourceValues(String fieldName, String bundle,
			int currentObjectId, Class objectClass) {
		Set<Object> set = new HashSet<Object>();
		List<Object> list = getListOfObjects(fieldName, bundle, currentObjectId, fieldName + valueExtension);
		if (list == null) return set;
		Iterator<Object> it = list.iterator();
		while (it.hasNext()) {
			Object[] row = (Object[]) it.next();
			int entity_id = Integer.valueOf(row[3].toString());
			Object relatedObject = Config.getFactory().getObject(entity_id);
			if (relatedObject != null && objectClass.isInstance(relatedObject)) {
				set.add(Config.getFactory().getObject(entity_id));
			}
			else {
				throw new ClassCastException("related object is of the wrong type");
			}
		}
		return set;
//		RelationshipDynamicField field = (RelationshipDynamicField) getField("Relationship", fieldName, bundle, entityId);
//		Object relatedObject = field.getValue();
//		if (relatedObject == null) {
//			throw new javax.persistence.EntityNotFoundException(
//				"No object of bundle " + bundle + " with entityId " + field.value ); }
//		if (relatedObject == null || objectClass.isInstance(relatedObject))
//			return relatedObject;
//		throw new ClassCastException("related object is of the wrong type");
	}
	
	public static Set<Object> getSourceValues(String fieldName, String bundle,
			String currentObjectId, Class objectClass) {
		Set<Object> set = new HashSet<Object>();
		List<Object> list = getListOfObjects(fieldName, bundle, currentObjectId, fieldName + "_value");
		if (list == null) {
			return null;
		}
		Iterator<Object> it = list.iterator();
		while (it.hasNext()) {
			Object[] row = (Object[]) it.next();
			int entity_id = Integer.valueOf(row[3].toString());
			Object relatedObject = Config.getFactory().getObject(entity_id);
			if (relatedObject != null && objectClass.isInstance(relatedObject)) {
				set.add(Config.getFactory().getObject(entity_id));
			}
			else {
				throw new ClassCastException("related object is of the wrong type");
			}
		}
		return set;
	}
	
	public static Set<Object> getSourceValues(String fieldName, String bundle,
			int currentObjectId, Class objectClass, String valueExtension) {
		Set<Object> set = new HashSet<Object>();
		List<Object> list = getListOfObjects(fieldName, bundle, currentObjectId, fieldName + valueExtension);
		if (list == null) return set;
		Iterator<Object> it = list.iterator();
		while (it.hasNext()) {
			Object[] row = (Object[]) it.next();
			int entity_id = Integer.valueOf(row[3].toString());
			Object relatedObject = Config.getFactory().getObject(entity_id);
			if (relatedObject != null && objectClass.isInstance(relatedObject)) {
				set.add(Config.getFactory().getObject(entity_id));
			}
			else {
				throw new ClassCastException("related object is of the wrong type");
			}
		}
		return set;
	}
	
	/**
	 * getting objects that point to currentObjectId
	 * used for source-to-target direction of many-to-many relationship
	 * @param fieldName
	 * @param bundle
	 * @param currentObjectId
	 * @param objectClass
	 * @return
	 */
	public static Set<Object> getTargetValues(String fieldName, String bundle,
			int currentObjectId, Class objectClass) {
		Set<Object> set = new HashSet<Object>();
		List<Object> list = getListOfObjects(fieldName, bundle, currentObjectId, "entity_id");
		Iterator<Object> it = list.iterator();
		while (it.hasNext()) {
			Object[] row = (Object[]) it.next();
			int entity_id = Integer.valueOf(row[7].toString());
			Object relatedObject = Config.getFactory().getObject(entity_id);
			if (relatedObject == null || objectClass.isInstance(relatedObject)) {
				set.add(Config.getFactory().getObject(entity_id));
			}
			else {
				throw new ClassCastException("related object is of the wrong type");
			}
		}
		return set;
//		RelationshipDynamicField field = (RelationshipDynamicField) getField("Relationship", fieldName, bundle, entityId);
//		Object relatedObject = field.getValue();
//		if (relatedObject == null) {
//			throw new javax.persistence.EntityNotFoundException(
//				"No object of bundle " + bundle + " with entityId " + field.value ); }
//		if (relatedObject == null || objectClass.isInstance(relatedObject))
//			return relatedObject;
//		throw new ClassCastException("related object is of the wrong type");
	}
	
	//TODO addRelationship, updateRelationship, removeRelationship
	


}
