package org.idiginfo.drupal.mapping;

import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.Id;
import javax.persistence.Query;
import javax.persistence.Table;

import org.idiginfo.drupal.config.Config;
import org.idiginfo.drupal.objectInterface.Group;
import org.idiginfo.drupal.objectInterface.User;


@Entity
@Table(name = Config.TABLE_PREFIX + "og")
public class DrupalGroup implements Group {

	private static final long serialVersionUID = 1L;
	@Id
	int gid;
	String label;
	
	public DrupalGroup() {
	}
	
	public DrupalGroup(int id, String name, User user, User submitter, Group group) {
		//TODO super(this.id, name, user, submitter, group);
	}

	@Override
	public User getGroupManager() {
		// TODO Auto-generated method stub
		//uid in drupal_node table ?
		return null;
	}

	@Override
	public void setGroupManager(User groupManager) {
		// TODO Auto-generated method stub
	}

	@Override
	public String getGroupName() {
		return label;
	}

	@Override
	public void setGroupName(String groupName) {
		this.label = groupName;

	}

	@Override
	public int getId() {
		return gid;
	}

	@Override
	public String getObjectTypeIdStr() {
		return getClassName();
	}

	@Override
	public boolean persist() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean validate() {
		if (label == null)
			return false;
		return true;
	}

	public static Group getGroupById(int groupId) {
		if (groupId == 0) return null;
		EntityManager em = Config.getEntityManager();
		DrupalGroup drupalGroup = em.find(DrupalGroup.class, groupId);
		return drupalGroup;
	}
	
	public static Group getGroupByName(String groupName) {
		if (groupName == null) return null;
		EntityManager em = Config.getEntityManager();
		String select = "select b from DrupalGroup b where b.label = :groupName";
		Query query = em.createQuery(select);
		query.setParameter("groupName", groupName);
		Object object = query.getSingleResult();
		if (object instanceof Group) {
			return (Group) object;
		}
		return null;
	}
	
	public String getClassName() {
		String className = getClass().getSimpleName();
		return className.substring(Config.CLASS_NAME_PREFIX.length());
	}

}
