package org.idiginfo.drupal.objectInterface;

import java.util.List;

import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Query;
import javax.persistence.Table;


public interface User extends IdObject {

	public static final String USER_QUERY = "select u from User u where u.name=:name";

	public Integer getUid();

	public void setUid(Integer uid);

	public String getName();

	public void setName(String name);

	public String getPass();

	public void setPass(String pass);

	public String getMail();

	public void setMail(String mail);

	public String getFirstName();

	public String getLastName();

	public String getUin();

	public void setUin(String value);

	public void setPin(String value);

	public void setUserName(String value);

	public void setEmail(String value);

	public void setAffiliation(String value);

	public void setAddress(String value);

	public void setLastName(String value);

	public void setFirstName(String value);

	public void setSuffix(String value);

	public void setMiddleInit(String value);

	public void setStreet1(String value);

	public void setStreet2(String value);

	public void setCity(String value);

	public void setCountry(String value);

	public void setState(String value);

	public void setZipcode(String value);

	public void setStatus(String value);

	public String getPin();

	public String getUserName();

	public String getEmail();

	public String getAffiliation();

	public String getAddress();

	public String getSuffix();

	public String getMiddleInit();

	public String getStreet1();

	public String getStreet2();

	public String getState();

	public String getZipcode();

	public String getStatus();

	public String getUserLogo();

	public String getLogoURL();
}
