package sk.stuba.fei.oop.skuska.domain.Vozidlo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.ENUMS.Nationality;
import sk.stuba.fei.oop.skuska.domain.Podvozok.PasovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomVelkehoKalibru;

@Data

@NoArgsConstructor
public class HeavyTank extends Vehicle {
    protected PasovyPodvozok pasovyPodvozok;
    protected VezaSDelomVelkehoKalibru vezaSDelomVelkehoKalibru;

    @Override
    public String toString() {
        return "HeavyTank{" +
                "pasovyPodvozok=" + pasovyPodvozok +
                ", vezaSDelomVelkehoKalibru=" + vezaSDelomVelkehoKalibru +
                ", price=" + price +
                ", nationality=" + nationality +
                ", id=" + id +
                ", name='" + name + '\'' +
                '}';
    }

    public HeavyTank(double price, Nationality nationality, PasovyPodvozok pasovyPodvozok, VezaSDelomVelkehoKalibru vezaSDelomVelkehoKalibru) {
        super(price, nationality);
        this.pasovyPodvozok = pasovyPodvozok;
        this.vezaSDelomVelkehoKalibru = vezaSDelomVelkehoKalibru;
    }

    public HeavyTank(PasovyPodvozok pasovyPodvozok, VezaSDelomVelkehoKalibru vezaSDelomVelkehoKalibru) {
        this.pasovyPodvozok = pasovyPodvozok;
        this.vezaSDelomVelkehoKalibru = vezaSDelomVelkehoKalibru;
    }


}
