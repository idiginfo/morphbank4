package org.idiginfo.drupal.objectInterface;

public interface Group extends IdObject {

	public static final String GROUP_QUERY = "select g from Group g where g.groupName = :groupName";

	public abstract User getGroupManager();

	public abstract void setGroupManager(User groupManager);

	public abstract String getGroupName();

	public abstract void setGroupName(String groupName);

}