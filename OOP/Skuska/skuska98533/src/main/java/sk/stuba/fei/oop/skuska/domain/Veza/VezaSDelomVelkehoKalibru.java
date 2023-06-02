package sk.stuba.fei.oop.skuska.domain.Veza;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloVelkehoKalibru;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class VezaSDelomVelkehoKalibru extends Veza {
    protected DeloVelkehoKalibru deloVelkehoKalibru;

    public VezaSDelomVelkehoKalibru(double rychlostOtacania, double dohlad, DeloVelkehoKalibru deloVelkehoKalibru) {
        super(rychlostOtacania, dohlad);
        this.deloVelkehoKalibru = deloVelkehoKalibru;
    }
}
