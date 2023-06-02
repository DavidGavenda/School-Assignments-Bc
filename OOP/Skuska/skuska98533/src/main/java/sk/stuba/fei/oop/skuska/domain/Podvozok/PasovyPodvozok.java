package sk.stuba.fei.oop.skuska.domain.Podvozok;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data

@NoArgsConstructor
public class PasovyPodvozok extends Podvozok {
    protected double sirkaPasu;

    public PasovyPodvozok(double nosnost, double rychlostOtacania, double maximalnaRychlost, double sirkaPasu) {
        super(nosnost, rychlostOtacania, maximalnaRychlost);
        this.sirkaPasu = sirkaPasu;
    }

    public PasovyPodvozok(double sirkaPasu) {
        this.sirkaPasu = sirkaPasu;
    }
}
