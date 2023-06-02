package Zadanie2.NonLifeInsurance;

import Zadanie2.Helpers.Address;
import Zadanie2.Helpers.Agreements;
import Zadanie2.Helpers.User;
import Zadanie2.NonLifeInsurance.ENUMS.TypeOfProperty;

public abstract class NonLifeAgreements extends Agreements {
    private final TypeOfProperty typeOfProperty;
    private final Address address;
    private double propertyValue;

    public NonLifeAgreements(User insurer,
                             String insuranceSince,
                             String insuranceTill,
                             String creationDate,
                             double indemnity,
                             double monthlyPayment,
                             TypeOfProperty typeOfProperty,
                             Address address,
                             double propertyValue) {
        super(creationDate,insurer, insuranceSince, insuranceTill, indemnity, monthlyPayment);
        this.typeOfProperty = typeOfProperty;
        this.address = address;
        this.propertyValue = propertyValue;
    }
}
