package sk.stuba.fei.oop.skuska.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.oop.skuska.domain.Delo.Delo;
import sk.stuba.fei.oop.skuska.domain.Podvozok.KolesovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.Delostrelectvo;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.HeavyTank;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.LightTank;

import java.util.HashMap;
import java.util.Map;

@Service
public class BasicVehicleService implements VehicleService {
    private Map<Long, Delostrelectvo> delostrelectvoMap;
    private Map<Long, HeavyTank> heavyTankMap;
    private Map<Long, LightTank> lightTankMap;


    public BasicVehicleService(){
        delostrelectvoMap = new HashMap<>();
        heavyTankMap = new HashMap<>();
        lightTankMap = new HashMap<>();
    }

    @Override
    public void addDelostrelectvo(Delostrelectvo delostrelectvo){
        delostrelectvoMap.put(delostrelectvo.getId(),delostrelectvo);
    }
    @Override
    public void addLightTank(LightTank lightTank){
        lightTankMap.put(lightTank.getId(),lightTank);
    }
    @Override
    public void addHeavyTank(HeavyTank heavyTank){
        heavyTankMap.put(heavyTank.getId(),heavyTank);
    }



    @Override
    public Delostrelectvo findDelostrelectvo(long id){
        return delostrelectvoMap.get(id);
    }

    @Override
    public Map<Long,Delostrelectvo> findAllDelostrelectvo(){
        return delostrelectvoMap;
    }


    @Override
    public HeavyTank findHeavyTank(long id){
        return heavyTankMap.get(id);
    }

    @Override
    public Map<Long,HeavyTank> findAllHeavyTanks(){
        return heavyTankMap;
    }

    @Override
    public LightTank findLightTank(long id){
        return lightTankMap.get(id);
    }

    @Override
    public Map<Long,LightTank> findAllLightTanks(){
        return lightTankMap;
    }





}
