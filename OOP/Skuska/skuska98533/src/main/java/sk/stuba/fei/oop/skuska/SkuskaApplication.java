package sk.stuba.fei.oop.skuska;

import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import sk.stuba.fei.oop.skuska.domain.Delo.Delo;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Entity;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.Vozidlo.HeavyTank;
import sk.stuba.fei.oop.skuska.service.ComponentsService;
import sk.stuba.fei.oop.skuska.service.VehicleService;

@SpringBootApplication
public class SkuskaApplication implements CommandLineRunner {

    private final VehicleService vehicleService;
    private final ComponentsService componentsService;

    public SkuskaApplication(VehicleService vehicleService,ComponentsService componentsService){
        this.vehicleService = vehicleService;
        this.componentsService = componentsService;
    }

    public static void main(String[] args) {
        SpringApplication.run(SkuskaApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception{
        PasovyPodvozok IS = new PasovyPodvozok(2020,10,120,50);
        DeloVelkehoKalibru MM = new DeloVelkehoKalibru(24,32,12,32);
        VezaSDelomVelkehoKalibru BL = new VezaSDelomVelkehoKalibru(21,12,MM);
        HeavyTank Jozko = new HeavyTank(IS,BL);
        componentsService.addPasovyPodvozok(IS);
        componentsService.addVezaSDelomVelkehoKalibru(BL);
        vehicleService.addHeavyTank(Jozko);
    }
}
