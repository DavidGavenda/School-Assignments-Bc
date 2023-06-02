package sk.stuba.fei.oop.skuska.domain.Vozidlo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.ENUMS.Nationality;
import sk.stuba.fei.oop.skuska.domain.Podvozok.KolesovyPodvozok;
import sk.stuba.fei.oop.skuska.domain.Veza.VezaSDelomMalehoKalibru;
@Data
@AllArgsConstructor
@NoArgsConstructor
public class LightTank extends Vehicle {
    protected KolesovyPodvozok kolesovyPodvozok;
    protected VezaSDelomMalehoKalibru vezaSDelomMalehoKalibru;

    @Override
    public String toString() {
        return "LightTank{" +
                "kolesovyPodvozok=" + kolesovyPodvozok +
                ", vezaSDelomMalehoKalibru=" + vezaSDelomMalehoKalibru +
                ", price=" + price +
                ", nationality=" + nationality +
                ", id=" + id +
                ", name='" + name + '\'' +
                '}';
    }

    public LightTank(double price, Nationality nationality, KolesovyPodvozok kolesovyPodvozok, VezaSDelomMalehoKalibru vezaSDelomMalehoKalibru) {
        super(price, nationality);
        this.kolesovyPodvozok = kolesovyPodvozok;
        this.vezaSDelomMalehoKalibru = vezaSDelomMalehoKalibru;
    }
}
