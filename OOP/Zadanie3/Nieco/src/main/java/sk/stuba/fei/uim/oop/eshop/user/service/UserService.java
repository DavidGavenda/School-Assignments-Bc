package sk.stuba.fei.uim.oop.eshop.user.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.InjuryInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.TravelInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HomeInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HouseOrFlatInsurance;
import sk.stuba.fei.uim.oop.eshop.user.domain.User;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

@Service
public interface UserService {

    void addUser(User item);

    Map<Long, User> findAllUsers();

    Optional<User> findUserById(long id);




    public InjuryInsurance findInjuryAgreementById(long id);

    public TravelInsurance findTravelAgreementById(long id);

    public HomeInsurance findHomeAgreementById(long id);

    public HouseOrFlatInsurance findHouseOrFlatAgreementById(long id);




    public void addInjuryAgreement(InjuryInsurance insurance);

    public void addTravelAgreement(TravelInsurance insurance);

    public void addHomeAgreement(HomeInsurance insurance);

    public void addHouseOrFlatAgreement(HouseOrFlatInsurance insurance);




    public Map<Long,InjuryInsurance> findInjuryAgreementsById(long id);

    public Map<Long,TravelInsurance> findTravelAgreementsById(long id);

    public Map<Long,HomeInsurance> findHomeAgreementsById(long id);

    public Map<Long,HouseOrFlatInsurance> findHouseOrFlatAgreementsById(long id);;
}
