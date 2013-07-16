package org.idiginfo.mapping.dynamicField;

import java.util.Date;

import org.idiginfo.drupal.mapping.DrupalDate;

public class DateDynamicField extends DynamicField {

	protected DateDynamicField(String fieldName, String bundle, int id,
			Object[] row) {
		super(fieldName, "date", bundle, "_value", id, row);
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof Integer) {
				value = new Long((Integer) obj);
			} else if (obj instanceof Long) {
				value = obj;
			}
		}
	}

	public static DateDynamicField getField(String fieldName, String bundle,
			int entityId) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, entityId);
		return new DateDynamicField(fieldName, bundle, entityId, row);
	}

	public Date getValue() {
		Long longValue = (Long) value;
		return DrupalDate.getDate(longValue);
	}

}
