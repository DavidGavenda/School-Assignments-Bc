package sk.stuba.fei.oop.skuska.domain.Podvozok;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class KolesovyPodvozok extends Podvozok {
    protected int pocetKolies;

    public KolesovyPodvozok(double nosnost, double rychlostOtacania, double maximalnaRychlost, int pocetKolies) {
        super(nosnost, rychlostOtacania, maximalnaRychlost);
        this.pocetKolies = pocetKolies;
    }
}
