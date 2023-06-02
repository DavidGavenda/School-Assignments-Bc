package Zadanie2.NonLifeInsurance;

import Zadanie2.Helpers.Address;
import Zadanie2.Helpers.User;
import Zadanie2.NonLifeInsurance.ENUMS.TypeOfProperty;

public class HouseOrFlatInsurance extends NonLifeAgreements {

    private boolean garageInsurance;

    public HouseOrFlatInsurance(User insurer,
                                String insuranceSince,
                                String insuranceTill,
                                String creationDate,
                                double indemnity,
                                double monthlyPayment,
                                TypeOfProperty typeOfProperty,
                                Address address,
                                double propertyValue,
                                boolean garageInsurance)throws IllegalArgumentException {
        super(insurer, insuranceSince, insuranceTill, creationDate, indemnity, monthlyPayment, typeOfProperty, address, propertyValue);
        this.garageInsurance = garageInsurance;
    }
}
