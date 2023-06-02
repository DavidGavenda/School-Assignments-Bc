package sk.stuba.fei.oop.skuska.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Podvozok.KolesovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;

import java.util.HashMap;
import java.util.Map;

@Service
public class BasicComponentsService implements ComponentsService {
    private Map<Long, KolesovyPodvozok> kolesovyPodvozokMap;
    private Map<Long, PasovyPodvozok> pasovyPodvozokMap;
    private Map<Long, VezaSDelomMalehoKalibru> vezaSDelomMalehoKalibruMap;
    private Map<Long, VezaSDelomVelkehoKalibru> vezaSDelomVelkehoKalibruMap;
    private Map<Long, DeloMalehoKalibru> deloMalehoKalibruMap;
    private Map<Long, DeloVelkehoKalibru> deloVelkehoKalibruMap;

    public BasicComponentsService(){
        kolesovyPodvozokMap = new HashMap<>();
        pasovyPodvozokMap  = new HashMap<>();
        vezaSDelomMalehoKalibruMap  = new HashMap<>();
        vezaSDelomVelkehoKalibruMap  = new HashMap<>();
        deloMalehoKalibruMap = new HashMap<>();
        deloVelkehoKalibruMap = new HashMap<>();
    }

    @Override
    public void addKolesovyPodvozok(KolesovyPodvozok kolesovyPodvozok){
        kolesovyPodvozokMap.put(kolesovyPodvozok.getId(),kolesovyPodvozok);
    }
    @Override
    public void addPasovyPodvozok (PasovyPodvozok pasovyPodvozok){
        pasovyPodvozokMap.put(pasovyPodvozok.getId(),pasovyPodvozok);
    }
    @Override
    public void addVezaSDelomMalehoKalibru(VezaSDelomMalehoKalibru vezaSDelomMalehoKalibru){
        vezaSDelomMalehoKalibruMap.put(vezaSDelomMalehoKalibru.getId(),vezaSDelomMalehoKalibru);
    }
    @Override
    public void addVezaSDelomVelkehoKalibru (VezaSDelomVelkehoKalibru vezaSDelomVelkehoKalibru){
        vezaSDelomVelkehoKalibruMap.put(vezaSDelomVelkehoKalibru.getId(),vezaSDelomVelkehoKalibru);
    }


    @Override
    public KolesovyPodvozok findKolesovyPodvozok(long id){
        return kolesovyPodvozokMap.get(id);
    }

    @Override
    public Map<Long,KolesovyPodvozok> findAllKolesovyPodvozok(){
        return kolesovyPodvozokMap;
    }


    @Override
    public PasovyPodvozok findPasovyPodvozok(long id){
        return pasovyPodvozokMap.get(id);
    }

    @Override
    public Map<Long,PasovyPodvozok> findAllPasovyPodvozok(){
        return pasovyPodvozokMap;
    }

    @Override
    public VezaSDelomMalehoKalibru findVezaSDelomMalehoKalibru(long id){
        return vezaSDelomMalehoKalibruMap.get(id);
    }

    @Override
    public Map<Long,VezaSDelomMalehoKalibru> findAllVezaSDelomMalehoKalibru(){
        return vezaSDelomMalehoKalibruMap;
    }

    @Override
    public VezaSDelomVelkehoKalibru findVezaSDelomVelkehoKalibru(long id){
        return vezaSDelomVelkehoKalibruMap.get(id);
    }

    @Override
    public Map<Long,VezaSDelomVelkehoKalibru> findAllVezaSDelomVelkehoKalibru(){
        return vezaSDelomVelkehoKalibruMap;
    }

    @Override
    public DeloMalehoKalibru findDeloMalehoKalibru(long id){
            return deloMalehoKalibruMap.get(id);
        }

        @Override
    public Map<Long,DeloMalehoKalibru> findAllDeloMalehoKalibru(){
            return deloMalehoKalibruMap;
        }

    @Override
    public DeloVelkehoKalibru findDeloVelkehoKalibru(long id){
        return deloVelkehoKalibruMap.get(id);
    }

    @Override
    public Map<Long,DeloVelkehoKalibru> findAllDeloVelkehoKalibru(){
        return deloVelkehoKalibruMap;
    }

}
