package sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;


@Data
@NoArgsConstructor
@AllArgsConstructor
public class HomeInsurance extends NonLifeAgreement {
    private double propertyEquipmentValue;
}
