package sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.ENUMS.TravelPurpose;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.ENUMS.TravelValidity;
import sk.stuba.fei.uim.oop.eshop.user.domain.User;


@Data
@AllArgsConstructor
@NoArgsConstructor
public class TravelInsurance extends Agreement {
    private long insuredId;
    private TravelValidity travelValidity;
    private TravelPurpose travelPurpose;

}
