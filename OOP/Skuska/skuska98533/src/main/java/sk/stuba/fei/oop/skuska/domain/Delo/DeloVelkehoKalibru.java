package sk.stuba.fei.oop.skuska.domain.Delo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.oop.skuska.domain.Delo.Delo;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class DeloVelkehoKalibru extends Delo {
    protected double polomerVybuchu;

    public DeloVelkehoKalibru(double kaliber, double kadencia, double rozptyl, double polomerVybuchu) {
        super(kaliber, kadencia, rozptyl);
        this.polomerVybuchu = polomerVybuchu;
    }
}
