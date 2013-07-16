package org.idiginfo.drupal;

import org.idiginfo.drupal.config.ObjectFactory;

public class Initializer {
	// get name of objectfactory class
	static String objectFactoryClass = null;
	static ObjectFactory factory = null;
	private static final String sciNameQueryString = "select t from Taxon t "
			+ "where t.scientificName = :sciName order by t.tsn";
	private static final String sciNameAuthorQueryString = "select t from Taxon t "
			+ "where t.scientificName = :sciName and t.taxonAuthor.name = :authorName";

	static void init() {
		try {
			Class factoryClass = Class.forName(objectFactoryClass);
			factory = (ObjectFactory) factoryClass.newInstance();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		}
	}

	public static ObjectFactory getFactory() {
		if (factory == null) init();
		return factory;
	}

	public static ObjectFactory getFactory(String className) {
		if (objectFactoryClass == null || !objectFactoryClass.equals(className)) {
			objectFactoryClass = className;
			init();
		} else {
			getFactory();
		}
		return factory;
	}
}
