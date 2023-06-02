/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projekt;

import entities.Book;
import java.util.Map;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

/**
 *
 * @author David
 */
public class Projekt {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

    }
    
    public boolean bookUpdate (String isbn, String name, Double price){
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("projektPU");
        EntityManager em = emf.createEntityManager();
        
        Book kniha = (Book) em.find(Book.class, isbn);

        if(kniha == null){
            Book k = new Book(isbn,name,price);
            em.persist(k);
            em.getTransaction().begin();
            em.getTransaction().commit();
            return true;
        }
               
        else {

            if(name!=null && kniha.getName()==null){
                kniha.setName(name);
            }
            
            if(name!=null && !(name.equals(kniha.getName()))){
                return false;
            }
            
            if(price!=null){
                kniha.setPrice(price);
            }
            
            em.getTransaction().begin();
            em.getTransaction().commit();
        }
        return true;
                 
    }

    public void priceListUpdate(Map<String,Double> priceList){
        
        if(priceList!=null){
            priceList.entrySet().stream().forEach((entry) -> {
                bookUpdate(entry.getKey(),null,entry.getValue());   
            });
        }

    }


    
    

    public static void persist(Object object) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("projektPU");
        EntityManager em = emf.createEntityManager();
        em.getTransaction().begin();
        try {
            em.persist(object);
            em.getTransaction().commit();
        } catch (Exception e) {
            e.printStackTrace();
            em.getTransaction().rollback();
        } finally {
            em.close();
        }
    }
    
    
    
}
