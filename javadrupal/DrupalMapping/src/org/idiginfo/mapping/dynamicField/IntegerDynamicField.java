package org.idiginfo.mapping.dynamicField;

public class IntegerDynamicField extends DynamicField {

	protected IntegerDynamicField(String fieldName, String bundle, int id,
			Object[] row) {
		super(fieldName, "Integer", bundle, "_value", id, row);
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof Integer) {
				value = (Integer) (obj);
			} else if (obj instanceof Long){
				value = Integer.valueOf(((Long)obj).intValue());
			}
		}
	}

	static IntegerDynamicField getField(String fieldName, String bundle,
			int entityId) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, entityId);
		return new IntegerDynamicField(fieldName, bundle, entityId, row);
	}

	public Integer getValue() {
		return (Integer) value;
	}

}
