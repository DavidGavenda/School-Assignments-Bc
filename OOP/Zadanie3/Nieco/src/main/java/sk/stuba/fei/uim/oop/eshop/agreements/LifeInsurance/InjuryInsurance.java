package sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.ENUMS.TerritorialValidity;

@Data
@NoArgsConstructor
@AllArgsConstructor

public class InjuryInsurance extends Agreement {
    private long insuredId;
    private double persistentEffects;
    private double deathByAccident;
    private double dailyAmends;
    private TerritorialValidity territorialValidity;


}
