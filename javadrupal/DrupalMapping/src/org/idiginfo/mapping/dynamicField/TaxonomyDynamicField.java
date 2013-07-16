package org.idiginfo.mapping.dynamicField;

import java.util.List;

import org.idiginfo.drupal.taxonomy.TaxonomyTermData;

public class TaxonomyDynamicField extends DynamicField {

	TaxonomyTermData datum;

	TaxonomyDynamicField(String fieldName, String bundle, int id, Object[] row) {
		super(fieldName, "taxonomy", bundle, "_tid", id, row);
		int tid = 0;
		if (row != null) {
			Object obj = row[7];
			if (obj instanceof Integer) {
				tid = (Integer) (obj);
			} else if (obj instanceof Long) {
				tid = Integer.valueOf(((Long) obj).intValue());
			}
		}
		datum = TaxonomyTermData.findTerm(tid);
	}

	
	public static DynamicField getField(String fieldName, String bundle,
			int entityId) {
		Object[] row = DynamicField.getFieldRow(fieldName, bundle, entityId);
		return new TaxonomyDynamicField(fieldName, bundle, entityId, row);
	}

	public TaxonomyTermData getDatum() {
		return datum;
	}

	@Override
	public String getValue() {
		if (datum == null) return null;
		return datum.getName();
	}

	@Override
	public void setValue(Object value) {
		if (value == null || !(value instanceof String)) return;
		String name = (String) value;
		if (datum != null && value.equals(datum.getName())){
			// no change in value
			return;
		}
		// use name to find new taxonomy term data
		String vocabularyName =  getFieldName();
		datum = TaxonomyTermData.findTerm((String)value,vocabularyName);
		if (datum ==null){
			// create new term data
			//TODO what if no such vocabulary
			datum = new TaxonomyTermData(name, vocabularyName);
			datum.createObject();
		}
		super.setValue(Integer.valueOf(datum.getTid()));
		// 
		
	}

}
