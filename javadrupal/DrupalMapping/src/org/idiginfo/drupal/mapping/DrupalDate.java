package org.idiginfo.drupal.mapping;

import java.util.Date;

/** 
 * Convert Drupal date, as long in seconds to/from Java Date, in milliseconds
 * @author griccardi
 *
 */
public class DrupalDate {
	public static Date getDate(Long date) {
		if (date==null) return null;
		return new Date(date*1000);
	}

	public static Long getDate(Date date) {
		if (date == null ) return null;
		long drupalDateValue = date.getTime()/1000;
		return drupalDateValue;
	}
}
