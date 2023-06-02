package sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.ENUMS.GarageInsurance;

@Data
@NoArgsConstructor
@AllArgsConstructor

public class HouseOrFlatInsurance extends NonLifeAgreement {
    private GarageInsurance garageInsurance;
}
