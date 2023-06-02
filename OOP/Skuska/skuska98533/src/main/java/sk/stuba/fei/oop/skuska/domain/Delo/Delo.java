package sk.stuba.fei.oop.skuska.domain.Delo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Entity;

@Data
@AllArgsConstructor
@NoArgsConstructor
public abstract class Delo extends Entity {
    protected double kaliber;
    protected double kadencia;
    protected double rozptyl;
}
