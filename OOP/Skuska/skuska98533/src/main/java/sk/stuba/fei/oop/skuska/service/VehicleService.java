package sk.stuba.fei.oop.skuska.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.oop.skuska.domain.Podvozok.KolesovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.Delostrelectvo;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.HeavyTank;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.LightTank;

import java.util.Map;

@Service
public interface VehicleService {

    public void addDelostrelectvo(Delostrelectvo delostrelectvo);

    public void addLightTank(LightTank lightTank);

    public void addHeavyTank(HeavyTank heavyTank);



    public Delostrelectvo findDelostrelectvo(long id);

    public Map<Long,Delostrelectvo> findAllDelostrelectvo();

    public HeavyTank findHeavyTank(long id);

    public Map<Long,HeavyTank> findAllHeavyTanks();

    public LightTank findLightTank(long id);

    public Map<Long,LightTank> findAllLightTanks();



}
