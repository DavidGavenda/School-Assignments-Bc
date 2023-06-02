package Zadanie2.NonLifeInsurance;

import Zadanie2.Helpers.Address;
import Zadanie2.Helpers.User;
import Zadanie2.NonLifeInsurance.ENUMS.TypeOfProperty;

public class HomeInsurance extends NonLifeAgreements {

    private double propertyEquipmentValue;

    public HomeInsurance(User insurer,
                         String insuranceSince,
                         String insuranceTill,
                         String creationDate,
                         double indemnity,
                         double monthlyPayment,
                         TypeOfProperty typeOfProperty,
                         Address address,
                         double propertyValue,
                         double propertyEquipmentValue)throws IllegalArgumentException {
        super(insurer, insuranceSince, insuranceTill, creationDate, indemnity, monthlyPayment, typeOfProperty, address, propertyValue);
        this.propertyEquipmentValue = propertyEquipmentValue;
    }
}
