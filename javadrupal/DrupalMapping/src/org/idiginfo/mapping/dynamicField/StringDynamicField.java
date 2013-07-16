package org.idiginfo.mapping.dynamicField;

import java.util.List;

public class StringDynamicField extends DynamicField {

	String format = null;

	protected StringDynamicField(String fieldName, String bundle, int id,
			Object[] row) {
		super(fieldName, "string", bundle, "_value", id, row);
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof String) {
				value = (String) (obj);
				format = (String) row[8];
			}
		}
	}

	public static StringDynamicField getField(String fieldName, String bundle,
			int entityId) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, entityId);
		return new StringDynamicField(fieldName, bundle, entityId, row);
	}

	public String getValue() {
		return (String) value;
	}

	public String getFormat() {
		return format;
	}

	public void setFormat(String format) {
		// TODO save in database
		this.format = format;
	}

}
