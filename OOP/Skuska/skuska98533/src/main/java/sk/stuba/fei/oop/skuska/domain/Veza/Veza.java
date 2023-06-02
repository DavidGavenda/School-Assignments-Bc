package sk.stuba.fei.oop.skuska.domain.Veza;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Entity;

@Data
@AllArgsConstructor
@NoArgsConstructor
public abstract class Veza extends Entity {
    protected double rychlostOtacania;
    protected double dohlad;

}
