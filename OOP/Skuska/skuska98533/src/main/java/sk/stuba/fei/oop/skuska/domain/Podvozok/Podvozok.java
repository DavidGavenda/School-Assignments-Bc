package sk.stuba.fei.oop.skuska.domain.Podvozok;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Entity;

@Data
@AllArgsConstructor
@NoArgsConstructor
public abstract class Podvozok extends Entity {
    protected double nosnost;
    protected double rychlostOtacania;
    protected double maximalnaRychlost;
}
