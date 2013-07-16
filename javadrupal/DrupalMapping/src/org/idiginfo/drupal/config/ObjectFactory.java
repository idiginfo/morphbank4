package org.idiginfo.drupal.config;

import java.util.List;

import javax.persistence.EntityManager;

import org.idiginfo.drupal.objectInterface.BaseObject;
import org.idiginfo.drupal.objectInterface.Group;
import org.idiginfo.drupal.objectInterface.User;

public interface ObjectFactory {
	public BaseObject getObject(String idStr);

	public BaseObject getObject(int localId);

	public BaseObject getObjectByExternalId(List<String> extIdList);

	public BaseObject getObjectByExternalId(String externalId);

	public User getUserByName(String name);

	public User getUserByUid(int uid);

	public User getUserByUserId(String uid);

	public EntityManager getEntityManager();

	public Group createGroup(int id, String name, User user, User user2,
			Group group);

	public User createUser(int id, String name, User user, User submitter,
			Group group, String userName, String uin, String pin);

	public String getPassword(int n);

	public String newKey(User user, Group group);

	// static methods for
	// User---------------------------------------------------------------------------

	public User getUserByUIN(String uin);

	// static methods for Group

	public Group getGroupById(int groupId);

	public Group getGroupByGroupId(String groupId);

	public Group getGroupByName(String groupName);

}
