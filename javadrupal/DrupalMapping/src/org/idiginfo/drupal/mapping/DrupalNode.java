/**
 * 
 */
package org.idiginfo.drupal.mapping;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.DiscriminatorColumn;
import javax.persistence.DiscriminatorType;
import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Query;
import javax.persistence.Table;
import javax.persistence.Transient;

import org.idiginfo.drupal.Initializer;
import org.idiginfo.drupal.config.Config;
import org.idiginfo.drupal.objectInterface.*;
import org.idiginfo.mapping.dynamicField.DynamicField;



/**
 * @author riccardi
 * 
 */
@Entity
@Table(name = Config.TABLE_PREFIX + "node")
@Inheritance(strategy = InheritanceType.SINGLE_TABLE)
@DiscriminatorColumn(name = "type", discriminatorType = DiscriminatorType.STRING)
public abstract class DrupalNode implements BaseObject, java.io.Serializable {
	static final long serialVersionUID = 1;

	static final String PACKAGE_NAME = "com.biodivimage.object.";

	// object fields
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "nid")
	protected int id;

	Integer vid;
	// type is the discriminator
	String language = "und";
	@Column(name = "type")
	String title = "";
	Integer status = 1;
	Long created;
	Long changed = (long) 0;
	Integer comment = 1;
	Integer promote = 0;
	Integer sticky = 0;
	Integer tnid = 0;
	Integer translate = 0;

	@ManyToOne
	@JoinColumn(name = "uid")
	User owner;
	
	// Constructors
	protected DrupalNode() {
	}


	public DrupalNode(int id, String name, String ownerId,
			String submitterId, String groupId) {
		User owner;
		User submitter;
		Group group;
		try {
			int uid = Integer.parseInt(ownerId);
			owner = (User) Initializer.getFactory().getUserByUid(uid);
		} catch (Exception e) {
			owner = (User) Initializer.getFactory().getUserByUserId(ownerId);
		}
		try {
			int uid = Integer.parseInt(submitterId);
			submitter = (User) Initializer.getFactory().getUserByUid(uid);
		} catch (Exception e) {
			submitter = (User) Initializer.getFactory().getUserByUserId(
					ownerId);
		}
		try {
			int gid = Integer.parseInt(groupId);
			group = (Group) Initializer.getFactory().getGroupById(gid);
		} catch (Exception e) {
			group = (Group) Initializer.getFactory().getGroupByName(groupId);
		}
		init(0, name, owner, submitter, group);
	}

	public DrupalNode(int id, String name, User owner, Group group) {
		this(id, name, owner, owner, group);
	}

	public DrupalNode(int id, String name, User owner, User submitter,
			Group group) {
		try {
			init(id, name, (User) owner, (User) submitter,
					(Group) group);
		} catch (Exception e) {
			// TODO log the error in conversion
		}
	}

	public int init(int id, String name, User owner, User submitter,
			Group group) {
		// TODO persist the instance! cannot work with objects that aren't
		// persistent
		// open transaction
		boolean createTransaction = false;
		EntityTransaction tx = Config.getEntityManager().getTransaction();
		if (tx == null) return 0;// no transaction available, unknown reason

		if (!tx.isActive()) {
			createTransaction = true;
			tx.begin();
		}
		try {
			setId(id);
			setSubmittedBy(submitter);
			Calendar today = Calendar.getInstance();
			setDateCreated(today.getTime());
			setModified();
			Calendar nextYear = Calendar.getInstance();
			nextYear.add(Calendar.YEAR, 1);
//			setDateToPublish(nextYear.getTime());
			createObject();

			if (createTransaction) {// method created its own transaction
				tx.commit();
			}
			return this.getId();
		} catch (Exception e) {
			System.out.println("object save failed for some reason");
			e.printStackTrace();
			// System.out.println("Exception in createObject");
		}

		// create object failed, reset id of object and rollback the tx, if new
		// tx created
		if (createTransaction) {
			tx.rollback();
		}
		return 0;
	}


	@Override
	public String getObjectTypeIdStr() {
		return getClassName();
	}

	@Override
	public boolean validate() {
		return true;
	}

	public static DrupalNode getObject(String idStr) {
		int id;
		try {
			id = Integer.parseInt(idStr);
			return getObject(id);
		} catch (Exception e) {
			// not an integer
		}
		// maybe external id
		//DrupalNode obj = getObjectByExternalId(idStr);
		// if (obj != null) return obj;
		// otherwise?
		return null;
	}


	public static DrupalNode getObject(int localId) {
		DrupalNode base;
		EntityManager em = Config.getEntityManager();
		if (em == null) { return null; }
		try {
			base = (DrupalNode) em.find(DrupalNode.class, localId);
			return base;
		} catch (Exception e) {
			// em is not active, try again
			e.printStackTrace();
		}
		return null;
	}


	public static BaseObject getObjectByExternalId(List<String> extIdList) {
		if (extIdList == null) { return null; }
		Iterator<String> extIds = extIdList.iterator();
		while (extIds.hasNext()) {
			BaseObject obj = getObjectByExternalId(extIds.next());
			if (obj != null) { return obj; }
		}
		return null;
	}

	public static final String EXTERNAL_LINK_QUERY = "select i.nid from ExternalId i where i.external_id=:externalId";
	
	public  static BaseObject getObjectByExternalId(String externalId) {
		// ExternalLinkObject obj = ExternalLinkObject
		// .getExternalLinkObject(externalId);
		// if (obj != null) return (BaseObject) obj.getObject();
		if (externalId == null || externalId.length() == 0) return null;
		EntityManager em = Config.getEntityManager();
		Query query = em.createQuery(EXTERNAL_LINK_QUERY);
		query.setParameter("externalId", externalId);
		try {
			BaseObject base = (BaseObject) query.getSingleResult();
			return base;
		} catch (Exception e) {
			return null;
		}
	}

	/**
	 * Converting from Java dates (millisecs) to/from Drupal dates (secs)
	 * requires factor of 1000
	 * 
	 * @return
	 */
	public Date getDateCreated() {
		return DrupalDate.getDate(getCreated());
	}

	public void setDateCreated(Date date) {
		setCreated(DrupalDate.getDate(date));
		setChanged(getCreated());
	}

	// Utility methods
	public boolean persist() {
		if (!validate()) return false;
		int id = createObject();
		vid = id;
		return id > 0;
	}

	// getters and setters

	private Long getCreated() {
		return created;
	}

	private void setCreated(Long created) {
		this.created = created;
	}

	public Long getChanged() {
		return changed;
	}


	public void setChanged(Long changed) {
		this.changed = changed;
	}


	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
		this.vid = id;
	}

	public int getUserId() {
		return getUser().getUid();
	}

//	public void setUser(User birUser) {
//		this.contributor.setContributor(birUser);
//	}

	/**
	 * Make the object persistent: assign an id and save into the database Use
	 * the existing transaction if open, create and commit a new transaction
	 * otherwise
	 * 
	 * @return id of the new persistent object, return 0 if save fails
	 */
	public int createObject() {
		 if (getId() != 0) { // not new object
		 System.out.println("attempt to create new object with non-zero id");
		 return getId();
		 }
		boolean createTransaction = false;
		EntityTransaction tx = Config.getEntityManager().getTransaction();
		if (tx == null) return 0;// no transaction available, unknown reason

		if (!tx.isActive()) {
			createTransaction = true;
			tx.begin();
		}
		try {// MorphbankConfig.getEntityManager().merge(this);
			Config.getEntityManager().persist(this);
			Config.getEntityManager().flush();
			if (createTransaction) {// method created its own transaction
				tx.commit();
			}
			return this.getId();
		} catch (Exception e) {
			System.out.println("object save failed for some reason");
			e.printStackTrace();
			// System.out.println("Exception in createObject");
		}

		// create object failed, reset id of object and rollback the tx, if new
		// tx created
		if (createTransaction) {
			tx.rollback();
		}
		return 0;
	}


	@Override
	public void setModified() {
		setDateLastModified(Calendar.getInstance().getTime());
	}

	@Override
	public String getClassName() {
		String className = getClass().getSimpleName();
		return className.substring(Config.CLASS_NAME_PREFIX.length());
	}

	@Override
	public String getFullClassName() {
		return getClass().getName();
	}

	@Override
	public Date getDateLastModified() {
		return DrupalDate.getDate(getChanged());
	}

	@Override
	public void setDateLastModified(Date dateLastModified) {
		setCreated(DrupalDate.getDate(dateLastModified));
	}


	public void setGroup(Group group) {
		DynamicField.setValue(Config.GROUP, "group_audience", this.getBundleName(), this.getId(), group.getId());
	}

	@Override
	public void updateDateLastModified() {
		Calendar today = Calendar.getInstance();
		setDateLastModified(today.getTime());
	}
	
	@Override
	public void updateDateLastModified(Date dateLastModified) {
		if (dateLastModified == null) {
			updateDateLastModified();
		} else if (this.getDateLastModified() == null
				|| this.getDateLastModified().before(dateLastModified)) {
			this.setDateLastModified(dateLastModified);
		}
		// otherwise, the date last modifieds are inconsistent!
		// this.dateLastModified = dateLastModified;
	}


	@Override
	public Group getGroup() {
		return DrupalGroup.getGroupById(getGroupId());
	}

	@Override
	public int getGroupId() {
		Object object = DynamicField.getValue(Config.DOUBLE, "group_audience", this.getBundleName(), this.getId());
		Integer gid = ((Double) object).intValue();
		return gid;
	}
	
	
	public abstract String getBundleName();
	

}
