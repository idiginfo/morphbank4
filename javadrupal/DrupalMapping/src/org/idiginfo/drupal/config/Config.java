/*******************************************************************************
 * Copyright (c) 2011 Greg Riccardi, Guillaume Jimenez.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the GNU Public License v2.0
 *  which accompanies this distribution, and is available at
 *  http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 *  
 *  Contributors:
 *  	Greg Riccardi - initial API and implementation
 * 	Guillaume Jimenez - initial API and implementation
 ******************************************************************************/
package org.idiginfo.drupal.config;

import java.net.InetSocketAddress;
import java.net.Proxy;
import java.util.List;
import java.util.Set;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Handler;
import java.util.logging.Logger;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;
import javax.persistence.Query;

import org.idiginfo.drupal.Initializer;

import java.util.Iterator;

/**
 * Configuration parameters and standard objects for the data services library
 * 
 * Includes configuration of database and its EJB persistence configurations
 * LSID authority LSID namespaces
 * 
 * This class should be modified to use a Java properties file for the
 * configuration parameters
 * 
 * @author riccardi
 */
public class Config {

	static final String FACTORY_CLASS = "com.biodivimage.object.object.ObjectFactory";

	public static final String PERSISTENCE_LOCALHOST = "localhost";
	public static final String PERSISTENCE_BIRTEST = "bir11";
	public static final String PERSISTENCE_BIRPROD = "bir";
	public static final String PERSISTENCE_BIRDEV = "bir11";
	public static final String PERSISTENCE_DRUPAL = "drupal";
	public static final String PERSISTENCE_MBTEST = "morphbank11";
	public static final String PERSISTENCE_MBPROD = "morphbank";
	public static final String PERSISTENCE_MBDEV = "morphbank11";

	// Constants for Drupal table names and standard values
	public static final String TABLE_PREFIX = "drupal_";
	public static final String ENTITY_TYPE = "node";
	public static final String BUNDLE_PREFIX = "bir_";
	public static final String FIELD_DATA_PREFIX = TABLE_PREFIX + "field_data_";
	public static final String COLLECTION_OBJECT_NAME = "bir_collection_node";
	public static final String CONTRIBUTOR = "contributor";
	public static final String EXTERNAL_LINK_TYPE = "external_link_type";

	// Types for DynamicField.getValue()
	public static final String STRING = "String";
	public static final String INTEGER = "Integer";
	public static final String TEXT = "Text";
	public static final String DOUBLE = "Double";
	public static final String TAXONOMY = "Taxonomy";
	public static final String DATE = "Date";
	public static final String RELATIONSHIP = "Relationship";
	public static final String GROUP = "Group";

	public static final String USER_LOGO_BASE_URL = "http://www.morphbank.net/images/userLogos/";
	public static final String SYSTEM_LOGGER_NAME = "ServicesLogger";
	public static final Logger SYSTEM_LOGGER = Logger
			.getLogger(SYSTEM_LOGGER_NAME);

	protected static ThreadLocal<EntityManager> entityManager = new ThreadLocal<EntityManager>();
	protected static EntityManagerFactory emf;
	protected static ObjectFactory factory;

	protected static String persistenceUnit = PERSISTENCE_LOCALHOST;

	// logging objects
	public static String SYSTEM_LOG_FILE_NAME = "/data/log/tomcat6/service.log";

	public static Proxy PROXY = Proxy.NO_PROXY;

	// public static String FILEPATH = "/data/log/tomcat6/mb3/xmlfiles/";

	public static void createLogHandler(String logname) {
		try {
			String logFileName = logname;
			if (logname == null || logname.length() == 0) {
				logFileName = SYSTEM_LOG_FILE_NAME;
			}
			SYSTEM_LOGGER.addHandler(new FileHandler(logFileName, true));
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("Cannot create logger file");
		}
	}

	public static void init() {
		try {
			SYSTEM_LOG_FILE_NAME = "/data/log/tomcat6/service.log";

			renewEntityManagerFactory();
			// renewEntityManager(); // Retrieve an application managed
			// entity manager
			factory = Initializer.getFactory(FACTORY_CLASS);
		} catch (Throwable e) {
			e.printStackTrace();
		}
	}

	public static void init(ObjectFactory factory) {
		renewEntityManagerFactory();
		Config.factory = factory;
	}

	public static ObjectFactory getFactory() {
		return factory;
	}

	public static EntityManager getEntityManager() {
		EntityManager em = entityManager.get();
		if (em == null || !em.isOpen()) {
			em = emf.createEntityManager();
			entityManager.set(em);
		}
		return em;
	}

	static void closeEntityManager() {
		EntityManager em = entityManager.get();
		entityManager.set(null);
		if (em != null && em.isOpen()) {
			em.close();
		}
	}

	static void closeEntityManagerFactory() {
		if (emf != null) {
			emf.close();
		}
	}

	public static EntityManagerFactory renewEntityManagerFactory() {
		if (emf == null || !emf.isOpen()) {
			emf = Persistence.createEntityManagerFactory(persistenceUnit);
		}
		return emf;
	}

	public static boolean ensureWorkingConnection() {
		boolean working = testConnection();
		if (working) return true;
		closeEntityManager();
		getEntityManager();
		return testConnection();
	}

	static boolean testConnection() {
		try {
			String testSql = "select min(id) from BaseObject";
			EntityManager em = entityManager.get();
			Query q = em.createNativeQuery(testSql);
			Object result = q.getSingleResult();
			return true;
		} catch (Exception e) {
			return false;
		}
	}

	/**
	 * Add keyValue to the table if it is not already included
	 * 
	 * @param tableName
	 * @param keyValue
	 * @return
	 */
	static boolean secondaryTableKeyInsert(String tableName, String keyValue) {
		if (keyValue == null || keyValue.length() == 0) { return false; }
		EntityManager em = getEntityManager();
		String selectStr = "select count(*) from " + tableName
				+ " where name = ?";
		Query selectQuery = em.createNativeQuery(selectStr);
		selectQuery.setParameter(1, keyValue);
		Object result = selectQuery.getSingleResult();
		int count = getIntFromQuery(result);
		if (count > 0) return false;
		boolean createTransaction = false;
		String insertQuery = "insert into " + tableName + " (name) values (?)";
		// attempt insert into table
		try {
			EntityTransaction tx = em.getTransaction();
			if (tx == null) {// no transaction available, unknown reason
				return false;
			} else if (!tx.isActive()) {// new transaction
				createTransaction = true;
				tx.begin();
			}
			Query insert = em.createNativeQuery(insertQuery);
			insert.setParameter(1, keyValue);
			int numresults = insert.executeUpdate();
			if (numresults > 0 && createTransaction) {
				tx.commit();
				return true;
			} else if (createTransaction) { // insert failed, keyValue already
				// present
				tx.rollback();
				return false;
			}
			return false;
		} catch (Exception e) {
			// e.printStackTrace();
			return false;
		}
	}

	// method compensates for lack of consistency in value returned from native
	// query
	// Toplink persistence returns vector from "select id from", hibernate
	// returns Integer or Long
	public static int getIntFromQuery(Object obj) {
		if (obj instanceof List) {
			obj = ((List) obj).get(0);
		}
		if (obj instanceof Integer) {
			return ((Integer) obj).intValue();
		} else if (obj instanceof Long) {
			return ((Long) obj).intValue();
		} else {
			return -1;
		}
	}

	public static boolean setupProxy(String proxyServer, String proxyPort) {
		if (proxyServer == null) return false;
		try {
			int port = Integer.parseInt(proxyPort);
			Config.setProxy(proxyServer, port);
			Config.SYSTEM_LOGGER.info("Proxy configuration: " + proxyServer
					+ " port '" + proxyPort + "' enabled ");
			return true;
		} catch (Exception e) {
			Config.SYSTEM_LOGGER.info("Proxy port '" + proxyPort
					+ "' is not integer ");
			return false;
		}

	}

	public static final String AUTHORITY = "services..net";

	static final String NAMESPACE = "";
	public static final String CLASS_NAME_PREFIX = "";

	public static String getPersistenceUnit() {
		return persistenceUnit;
	}

	public static void setPersistenceUnit(String persistenceUnit) {
		Config.persistenceUnit = persistenceUnit;
	}

	public static String flush() {
		try {
			EntityManager em = getEntityManager();
			em.flush();
			return null;
		} catch (Exception e) {
			return e.getMessage();
		}
	}

	public static Proxy getProxy() {
		return PROXY;
	}

	public static void setProxy(String proxyServer, int port) {
		PROXY = new Proxy(Proxy.Type.HTTP, new InetSocketAddress(proxyServer,
				port));
	}
}
