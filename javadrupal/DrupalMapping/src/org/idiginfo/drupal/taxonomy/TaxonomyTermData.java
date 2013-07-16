package org.idiginfo.drupal.taxonomy;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Query;
import javax.persistence.Table;

import org.idiginfo.drupal.config.Config;



/**
 * Class to expose Drupal Taxonomy table that stores term values and mapping
 * from value to field (vid)
 * 
 * @author griccardi
 * 
 */
@Entity
@Table(name = Config.TABLE_PREFIX + "taxonomy_term_data")
public class TaxonomyTermData {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Integer tid;
	@ManyToOne(fetch = FetchType.LAZY, cascade = CascadeType.PERSIST)
	@JoinColumn(name = "vid")
	TaxonomyTermVocabulary vocabulary;

	String name;
	String description = null;
	String format = "plain_text";
	Integer weight = 0;

	TaxonomyTermData() {
	}

	public TaxonomyTermData(String name, String vocabularyName) {
		this.vocabulary = TaxonomyTermVocabulary.findVocabulary(vocabularyName);
		if (vocabulary == null) return;
		this.name = name;
	}
	
	// Methods specific to BIR

	public static TaxonomyTermData findTaxonomyTermData(int tid) {
		return findTerm(tid);
	}

	public static TaxonomyTermVocabulary findVocabulary(String name) {
		return TaxonomyTermVocabulary.findVocabulary(name);
	}

	public static TaxonomyTermData findTaxonomyTermData(String name,
			String vocabularyName) {
		return findTerm(name, vocabularyName);
	}

	public static TaxonomyTermData findTaxonomyTermData(String name, int vid) {
		return findTerm(name, vid);
	}

	public static TaxonomyTermData findTerm(int tid) {
		TaxonomyTermData datum;
		EntityManager em = Config.getEntityManager();
		if (em == null) { return null; }
		try {
			datum = (TaxonomyTermData) em.find(TaxonomyTermData.class, tid);
			return datum;
		} catch (Exception e) {
			// em is not active, try again
			e.printStackTrace();
		}
		return null;
	}

	public static final String TERM_DATA_VOCAB_QUERY = "select d from TaxonomyTermData d where d.name=:name and d.vocabulary.machineName=:vocabName";

	public static TaxonomyTermData findTerm(String name, String vocabularyName) {
		if (name == null || vocabularyName == null) return null;
		EntityManager em = Config.getEntityManager();
		Query query = em.createQuery(TERM_DATA_VOCAB_QUERY);
		query.setParameter("name", name);
		query.setParameter("vocabName", vocabularyName);
		try {
			return (TaxonomyTermData) query.getSingleResult();
		} catch (Exception e) {
			return null;
		}
	}

	public static final String TERM_DATA_QUERY = "select d from TaxonomyTermData d where d.name=:name and d.vocabulary.vid=:vid";

	public static TaxonomyTermData findTerm(String name, Integer vid) {
		if (name == null) return null;
		EntityManager em = Config.getEntityManager();
		Query query = em.createQuery(TERM_DATA_QUERY);
		query.setParameter("name", name);
		query.setParameter("vid", vid);
		try {
			return (TaxonomyTermData) query.getSingleResult();
		} catch (Exception e) {
			return null;
		}
	}
	
	public int createObject() {
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
			return this.getTid();
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

	public Integer getTid() {
		return tid;
	}

	public void setTid(Integer tid) {
		this.tid = tid;
	}

	public TaxonomyTermVocabulary getTerm() {
		return vocabulary;
	}

	public void setTerm(TaxonomyTermVocabulary term) {
		this.vocabulary = term;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getFormat() {
		return format;
	}

	public void setFormat(String format) {
		this.format = format;
	}

	public Integer getWeight() {
		return weight;
	}

	public void setWeight(Integer weight) {
		this.weight = weight;
	}

}
