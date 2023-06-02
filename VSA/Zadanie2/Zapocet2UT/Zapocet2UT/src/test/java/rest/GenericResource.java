/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rest;

import java.util.ArrayList;
import java.util.List;
import javax.inject.Singleton;
import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author David
 */
@Path("menu")
@Singleton

public class GenericResource {
    
    private List<Ponuka> ponuky = new ArrayList<>();
    private List<Jedlo> jedla = new ArrayList<>();

    @Context
    private UriInfo context;

    public GenericResource() {
        
        Jedlo gulas = new Jedlo(3.5,"gulas");
        jedla.add(gulas);
        
        ponuky.add(new Ponuka("pondelok", jedla));
        ponuky.add(new Ponuka("utorok", new ArrayList<Jedlo>()));
        ponuky.add(new Ponuka("streda", new ArrayList<Jedlo>()));
        ponuky.add(new Ponuka("stvrtok", new ArrayList<Jedlo>()));
        ponuky.add(new Ponuka("piatok", new ArrayList<Jedlo>()));
        ponuky.add(new Ponuka("sobota", new ArrayList<Jedlo>()));
        ponuky.add(new Ponuka("nedela", new ArrayList<Jedlo>()));          
    }
    
    
    @GET
    @Path("{den}")
    @Produces(MediaType.TEXT_PLAIN)
    public int getPocetDen(@PathParam("den") String den) {
        for (int i=0; i<ponuky.size(); i++){
            if (ponuky.get(i).getDen().equals(den)){
                return ponuky.get(i).getJedlo().size();
            }
        }
        return 0;
    }
    
    @GET
    @Path("{den}")
    @Produces(MediaType.APPLICATION_XML)
    public Ponuka getPonuka(@PathParam("den") String den) {
        for (int i=0; i<ponuky.size(); i++){
            if (ponuky.get(i).getDen().equals(den)){
                return ponuky.get(i);
            }
        }
        return null;
    }
       
    @POST
    @Path("{den}")
    @Consumes(MediaType.APPLICATION_XML)
    public int addJedlo(@PathParam("den") String den, Jedlo content) {
        for (int i=0; i<ponuky.size(); i++){
            if (ponuky.get(i).getDen().equals(den)){
                for (int j=0; j<ponuky.get(i).getJedlo().size(); j++){
                    if (ponuky.get(i).getJedlo().get(j).getNazov().equals(content.getNazov())){
                        return 0;
                    }
                }
                List<Jedlo> tmp = ponuky.get(i).getJedlo();
                tmp.add(content);
                ponuky.get(i).setJedlo(tmp);
                return ponuky.get(i).getJedlo().size();
            }
        }
        return 0;
    }
    
    @GET
    @Path("{den}/{n}")
    @Produces(MediaType.APPLICATION_XML)
    public Jedlo getPonukaJedlo(@PathParam("den") String den, @PathParam("n") int n) {
        for (int i=0; i<ponuky.size(); i++){
            if (ponuky.get(i).getDen().equals(den)){
                if (0 <= n-1 && n-1 < ponuky.get(i).getJedlo().size()){
                    return ponuky.get(i).getJedlo().get(n-1);
                }
            }
        }
        return null;
    }
    
    @DELETE
    @Path("{den}/{n}")
    public void odstranJedlo(@PathParam("den") String den, @PathParam("n") int n) {
        for (int i=0; i<ponuky.size(); i++){
            if (ponuky.get(i).getDen().equals(den)){
                if (0 <= n-1 && n-1 < ponuky.get(i).getJedlo().size()){
                    List<Jedlo> tmp = ponuky.get(i).getJedlo();
                    tmp.remove(n-1);
                    ponuky.get(i).setJedlo(tmp);
                }
            }
        }
    }
    
    @GET
    @Produces(MediaType.TEXT_PLAIN)
    public String getDen(@QueryParam("nazov") String name) {
        String text = "";
        for (int i=0; i<ponuky.size(); i++){
            for (int j=0; j<ponuky.get(i).getJedlo().size(); j++){
                if (ponuky.get(i).getJedlo().get(j).getNazov().equals(name)){
                    text = text + ponuky.get(i).getDen() + " ";
                }
            }
        }
        if (text.isEmpty()){
            return "NEMAME";
        }
        else {
            return text;
        }
    }
}