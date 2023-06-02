package sk.stuba.fei.oop.skuska.domain.Vozidlo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.ENUMS.Nationality;
import sk.stuba.fei.oop.skuska.domain.Entity;
@Data
@AllArgsConstructor
@NoArgsConstructor
public abstract class Vehicle extends Entity {
    protected double price;
    protected Nationality nationality;

    @Override
    public String toString() {
        return "Vehicle{" +
                "price=" + price +
                ", nationality=" + nationality +
                ", id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
