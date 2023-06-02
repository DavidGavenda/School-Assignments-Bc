package rest;


import java.util.List;
import javax.xml.bind.annotation.XmlRootElement;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
@XmlRootElement
public class Ponuka {
    
    private String den;
    private List<Jedlo> jedlo;

    public Ponuka(String den, List<Jedlo> jedlo) {
        this.den = den;
        this.jedlo = jedlo;
    }

    public Ponuka() {
    }

    public String getDen() {
        return den;
    }

    public void setDen(String den) {
        this.den = den;
    }

    public List<Jedlo> getJedlo() {
        return jedlo;
    }

    public void setJedlo(List<Jedlo> jedlo) {
        this.jedlo = jedlo;
    }


    
   
}

