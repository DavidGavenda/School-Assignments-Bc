package sk.stuba.fei.oop.skuska.domain.Vozidlo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloVelkehoKalibru;
import sk.stuba.fei.oop.skuska.domain.ENUMS.Nationality;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Delostrelectvo extends Vehicle {
    protected PasovyPodvozok pasovyPodvozok;
    protected DeloVelkehoKalibru deloVelkehoKalibru;

    @Override
    public String toString() {
        return "Delostrelectvo{" +
                "pasovyPodvozok=" + pasovyPodvozok +
                ", deloVelkehoKalibru=" + deloVelkehoKalibru +
                ", price=" + price +
                ", nationality=" + nationality +
                ", id=" + id +
                ", name='" + name + '\'' +
                '}';
    }

    public Delostrelectvo(double price, Nationality nationality, PasovyPodvozok pasovyPodvozok, DeloVelkehoKalibru deloVelkehoKalibru) {
        super(price, nationality);
        this.pasovyPodvozok = pasovyPodvozok;
        this.deloVelkehoKalibru = deloVelkehoKalibru;
    }
}
