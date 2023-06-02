package Zadanie2.LifeInsurance;

import Zadanie2.Helpers.Agreements;
import Zadanie2.Helpers.User;
import Zadanie2.LifeInsurance.ENUMS.TerritorialValidity;

public class AccidentInsurance extends Agreements {

    private User insured;
    private double persistentEffects;
    private double deathCausedByAccident;
    private double dailyAmends;
    private TerritorialValidity territorialValidity;

    public AccidentInsurance (User insured,
                              double persistentEffects,
                              double deathCausedByAccident,
                              double dailyAmends,
                              TerritorialValidity territorialValidity,
                              String creationDate,
                              String insuranceSince,
                              User insurer,
                              String insuranceTill,
                              double indemnity,
                              double monthlyPayment) throws IllegalArgumentException{
        super(creationDate,insurer,insuranceSince,insuranceTill,indemnity,monthlyPayment);
        this.insured = insured;
        this.persistentEffects=persistentEffects;
        this.deathCausedByAccident=deathCausedByAccident;
        this.dailyAmends=dailyAmends;
        this.territorialValidity= territorialValidity;
    }
}
