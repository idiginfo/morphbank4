package org.idiginfo.drupal.taxonomy;

import java.util.List;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Query;
import javax.persistence.Table;

import org.idiginfo.drupal.config.Config;

@Entity
@Table(name = Config.TABLE_PREFIX + "taxonomy_vocabulary")
public class TaxonomyTermVocabulary {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Integer vid;
	String name;
	@Column(name = "machine_name")
	String machineName;
	String description;
	Integer hierarchy;
	String module;
	Integer weight;

	@OneToMany(mappedBy = "vocabulary", fetch = FetchType.LAZY)
	List<TaxonomyTermData> termData;

	public List<TaxonomyTermData> getTermData() {
		return termData;
	}

	public TaxonomyTermVocabulary() {
		// TODO Auto-generated constructor stub
	}

	public static final String VOCAB_QUERY = "select v from TaxonomyTermVocabulary v where v.machineName=:name";

	public static TaxonomyTermVocabulary findVocabulary(String name) {
		if (name == null) return null;
		EntityManager em = Config.getEntityManager();
		Query query = em.createQuery(VOCAB_QUERY);
		query.setParameter("name", name);
		try {
			return (TaxonomyTermVocabulary) query.getSingleResult();
		} catch (Exception e) {
			return null;
		}
	}

	public TaxonomyTermData getTermData(String name){
		return TaxonomyTermData.findTerm(name, getVid());
	}
	
	public Integer getVid() {
		return vid;
	}

	public void setVid(Integer vid) {
		this.vid = vid;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getMachineName() {
		return machineName;
	}

	public void setMachineName(String machineName) {
		this.machineName = machineName;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public Integer getHierarchy() {
		return hierarchy;
	}

	public void setHierarchy(Integer hierarchy) {
		this.hierarchy = hierarchy;
	}

	public String getModule() {
		return module;
	}

	public void setModule(String module) {
		this.module = module;
	}

	public Integer getWeight() {
		return weight;
	}

	public void setWeight(Integer weight) {
		this.weight = weight;
	}
}
