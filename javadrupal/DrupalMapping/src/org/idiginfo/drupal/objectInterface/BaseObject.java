/**
 * 
 */
package org.idiginfo.drupal.objectInterface;

import java.util.Date;
import java.util.List;
import java.util.Map;

/**
 * @author riccardi
 * 
 */

public interface BaseObject extends IdObject {
	public void updateDateLastModified();

	public boolean persist();

	public boolean validate();

	public void setModified();

	public String getClassName();

	public String getFullClassName();

	public String getUrl();

	public void setUrl(String url);

	public int getId();

	public void setId(int id);

	public Date getDateCreated();

	public void setDateCreated(Date dateCreated);

	public Date getDateLastModified();

	public void setDateLastModified(Date dateLastModified);

	public String getObjectTypeIdStr();

	public User getUser();

	public int getUserId();

	public void setUser(User user);

	public User getSubmittedBy();

	public void setSubmittedBy(User submittedBy);

	public Group getGroup();

	void updateRelatedObject(BaseObject oldObj, BaseObject newObj);

	void updateDateLastModified(Date dateLastModified);

	int getGroupId();

}
