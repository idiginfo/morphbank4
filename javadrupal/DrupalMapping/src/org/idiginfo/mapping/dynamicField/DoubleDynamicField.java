package org.idiginfo.mapping.dynamicField;

import java.util.List;

public class DoubleDynamicField extends DynamicField {

	protected DoubleDynamicField(String fieldName, String bundle, int id,
			Object[] row) {
		super(fieldName, "double", bundle, "_value", id, row);
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof Double) {
				value = (Double) (obj);
			} else if (obj instanceof Float) {
				value = Double.valueOf(((Float) obj).doubleValue());
			}
		}
	}

	public static DoubleDynamicField getField(String fieldName, String bundle,
			int id) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, id);
		return new DoubleDynamicField(fieldName, bundle, id, row);
	}

	public Double getValue() {
		return (Double) value;
	}
	
}
