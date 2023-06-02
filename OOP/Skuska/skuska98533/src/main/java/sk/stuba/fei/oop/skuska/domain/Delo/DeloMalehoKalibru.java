package sk.stuba.fei.oop.skuska.domain.Delo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Delo.Delo;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class DeloMalehoKalibru extends Delo {
    protected int pocetNabojovVZasobniku;

    public DeloMalehoKalibru(double kaliber, double kadencia, double rozptyl, int pocetNabojovVZasobniku) {
        super(kaliber, kadencia, rozptyl);
        this.pocetNabojovVZasobniku = pocetNabojovVZasobniku;
    }
}
