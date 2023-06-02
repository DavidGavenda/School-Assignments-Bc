package sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance;


import lombok.Data;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.ENUMS.TypeOfProperty;
import sk.stuba.fei.uim.oop.eshop.user.domain.Address;

@Data
public abstract class NonLifeAgreement extends Agreement {
    private TypeOfProperty typeOfProperty;
    private Address address;
    private double propertyValue;

}
