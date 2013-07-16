package org.idiginfo.drupal.mapping;

import java.util.List;

import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Query;
import javax.persistence.Table;
import javax.persistence.Transient;

import org.idiginfo.drupal.config.Config;
import org.idiginfo.drupal.objectInterface.*;



@Entity
@Table(name = Config.TABLE_PREFIX +"users")
public class DrupalUser implements User {

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Integer uid;
	String name;
	String pass;
	String mail;
	@OneToMany(mappedBy = "submittedBy")
	List<BaseObject> ownedObjects;
	//@OneToMany(mappedBy = "submittedBy")
	@Transient
	List<BaseObject> submittedObjects;

	public DrupalUser() {
	}

	public DrupalUser(String name, String pass, String mail) {
		this.name = name;
		this.pass = pass;
		this.mail = mail;
	}

	public DrupalUser(int id, String name, User user, User submitter,
			Group group, String userName, String uin, String pin) {
		// TODO Auto-generated constructor stub
	}

	public static final String USER_QUERY = "select u from DrupalUser u where u.name=:name";

	public static DrupalUser getUserByUserId(String userId) {
		if (userId == null || userId.length() == 0) return null;
		DrupalUser user = getUserByName(userId);
		if (user != null) return user;
		int objectId;
		try {
			objectId = Integer.parseInt(userId);
			return getUserByUid(objectId);
		} catch (Exception e) {
		}
		return null;
	}


	public static DrupalUser getUserByName(String name) {
		if (name == null || name.length() == 0) return null;
		EntityManager em = Config.getEntityManager();
		Query query = em.createQuery(USER_QUERY);
		query.setParameter("name", name);
		try {
			return (DrupalUser) query.getSingleResult();
		} catch (Exception e) {
			return null;
		}
	}

	public static DrupalUser getUserByUid(int uid) {
		if (uid == 0) return null;
		EntityManager em = Config.getEntityManager();
		DrupalUser drupalUser = em.find(DrupalUser.class, uid);
		return drupalUser;
	}

	public Integer getUid() {
		return uid;
	}

	public void setUid(Integer uid) {
		this.uid = uid;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPass() {
		return pass;
	}

	public void setPass(String pass) {
		this.pass = pass;
	}

	public String getMail() {
		return mail;
	}

	public void setMail(String mail) {
		this.mail = mail;
	}

	@Override
	public String getFirstName() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getLastName() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int getId() {
		return getUid();
	}

	@Override
	public String getObjectTypeIdStr() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean persist() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean validate() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String getUin() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void setUin(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setPin(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setUserName(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setEmail(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setAffiliation(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setAddress(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setLastName(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setFirstName(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setSuffix(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setMiddleInit(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setStreet1(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setStreet2(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setCity(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setCountry(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setState(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setZipcode(String value) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void setStatus(String value) {
		// TODO Auto-generated method stub
		
	}


	@Override
	public String getPin() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getUserName() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getEmail() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getAffiliation() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getAddress() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getSuffix() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getMiddleInit() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getStreet1() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getStreet2() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getState() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getZipcode() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getStatus() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getUserLogo() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getLogoURL() {
		// TODO Auto-generated method stub
		return null;
	}

}
