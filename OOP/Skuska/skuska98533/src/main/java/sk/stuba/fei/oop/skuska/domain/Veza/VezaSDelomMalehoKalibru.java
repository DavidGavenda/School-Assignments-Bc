package sk.stuba.fei.oop.skuska.domain.Veza;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloMalehoKalibru;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class VezaSDelomMalehoKalibru extends Veza {
    protected DeloMalehoKalibru deloMalehoKalibru;

    public VezaSDelomMalehoKalibru(double rychlostOtacania, double dohlad, DeloMalehoKalibru deloMalehoKalibru) {
        super(rychlostOtacania, dohlad);
        this.deloMalehoKalibru = deloMalehoKalibru;
    }
}
