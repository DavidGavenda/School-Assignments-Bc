package sk.stuba.fei.oop.skuska.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Podvozok.KolesovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomMalehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;

import java.util.Map;
@Service
public interface ComponentsService {

    public KolesovyPodvozok findKolesovyPodvozok(long id);

    public Map<Long,KolesovyPodvozok> findAllKolesovyPodvozok();

    public PasovyPodvozok findPasovyPodvozok(long id);

    public Map<Long,PasovyPodvozok> findAllPasovyPodvozok();

    public VezaSDelomMalehoKalibru findVezaSDelomMalehoKalibru(long id);

    public Map<Long,VezaSDelomMalehoKalibru> findAllVezaSDelomMalehoKalibru();

    public VezaSDelomVelkehoKalibru findVezaSDelomVelkehoKalibru(long id);

    public Map<Long,VezaSDelomVelkehoKalibru> findAllVezaSDelomVelkehoKalibru();



    public void addKolesovyPodvozok(KolesovyPodvozok kolesovyPodvozok);

    public void addPasovyPodvozok (PasovyPodvozok pasovyPodvozok);

    public void addVezaSDelomMalehoKalibru(VezaSDelomMalehoKalibru vezaSDelomMalehoKalibru);

    public void addVezaSDelomVelkehoKalibru (VezaSDelomVelkehoKalibru vezaSDelomVelkehoKalibru);

    public DeloMalehoKalibru findDeloMalehoKalibru(long id);

    public Map<Long,DeloMalehoKalibru> findAllDeloMalehoKalibru();

    public DeloVelkehoKalibru findDeloVelkehoKalibru(long id);

    public Map<Long,DeloVelkehoKalibru> findAllDeloVelkehoKalibru();


}
