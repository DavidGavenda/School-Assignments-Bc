package Zadanie2.LifeInsurance;

import Zadanie2.Helpers.Agreements;
import Zadanie2.Helpers.User;
import Zadanie2.LifeInsurance.ENUMS.TravelPurpose;
import Zadanie2.LifeInsurance.ENUMS.TravelValidity;

public class TravelInsurance extends Agreements {
        private User insured;
        private TravelValidity travelValidity;
        private TravelPurpose travelPurpose;

        public TravelInsurance(User insurer,
                               String insuranceSince,
                               String insuranceTill,
                               double indemnity,
                               String creationDate,
                               double monthlyPayment,
                               User insured,
                               TravelValidity travelValidity,
                               TravelPurpose travelPurpose)throws IllegalArgumentException {
                super(creationDate,insurer, insuranceSince, insuranceTill, indemnity, monthlyPayment);
                this.insured = insured;
                this.travelValidity = travelValidity;
                this.travelPurpose = travelPurpose;
        }
}
