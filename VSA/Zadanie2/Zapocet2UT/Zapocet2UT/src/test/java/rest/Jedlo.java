package rest;

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
public class Jedlo {
    private Double cena;
    private String nazov;

    public Jedlo() {
    }

    public Jedlo(Double cena, String nazov) {
        this.cena = cena;
        this.nazov = nazov;
    }

    public Double getCena() {
        return cena;
    }

    public void setCena(Double cena) {
        this.cena = cena;
    }

    public String getNazov() {
        return nazov;
    }

    public void setNazov(String nazov) {
        this.nazov = nazov;
    }
    
           
}
