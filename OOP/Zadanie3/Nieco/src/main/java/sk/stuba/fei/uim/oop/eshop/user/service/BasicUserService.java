package sk.stuba.fei.uim.oop.eshop.user.service;

import org.springframework.stereotype.Service;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.InjuryInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.TravelInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HomeInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HouseOrFlatInsurance;
import sk.stuba.fei.uim.oop.eshop.user.domain.User;

import java.util.*;

@Service
public class BasicUserService implements UserService {

    private Map<Long, User> users;
    private Map<Long,Agreement> agreements;
    private Map<Long,InjuryInsurance> injuryAgreements;
    private Map<Long,TravelInsurance> travelAgreements;
    private Map<Long,HomeInsurance> homeAgreements;
    private Map<Long,HouseOrFlatInsurance> houseOrFlatAgreements;

    public BasicUserService() {
        users = new HashMap<>();
        agreements = new HashMap<>();
        injuryAgreements = new HashMap<>();
        travelAgreements = new HashMap<>();
        homeAgreements = new HashMap<>();
        houseOrFlatAgreements = new HashMap<>();
    }

    @Override
    public void addUser(User user) {
        users.put(user.getId(), user);
    }

    @Override
    public Map<Long, User> findAllUsers() {
        return users;
    }

    @Override
    public Optional<User> findUserById(long id) {
        return Optional.ofNullable(users.get(id));
    }

    @Override
    public InjuryInsurance findInjuryAgreementById(long id) {return injuryAgreements.get(id);}

    @Override
    public TravelInsurance findTravelAgreementById(long id) {return travelAgreements.get(id); }

    @Override
    public HomeInsurance findHomeAgreementById(long id) {return homeAgreements.get(id); }

    @Override
    public HouseOrFlatInsurance findHouseOrFlatAgreementById(long id) {return houseOrFlatAgreements.get(id); }



    @Override
    public Map<Long,InjuryInsurance> findInjuryAgreementsById(long id){
        Map<Long,InjuryInsurance> send = new HashMap<>();
        for(Map.Entry<Long,InjuryInsurance> i : injuryAgreements.entrySet()){
            if(i.getValue().getInsurerId()==id){
                send.put(i.getValue().getId(),i.getValue());
            }
        }
        return send;
    }

    @Override
    public Map<Long,TravelInsurance> findTravelAgreementsById(long id){
        Map<Long,TravelInsurance> send = new HashMap<>();
        for(Map.Entry<Long,TravelInsurance> i : travelAgreements.entrySet()){
            if(i.getValue().getInsurerId()==id){
                send.put(i.getValue().getId(),i.getValue());
            }
        }
        return send;
    }

    @Override
    public Map<Long,HomeInsurance> findHomeAgreementsById(long id){
        Map<Long,HomeInsurance> send = new HashMap<>();
        for(Map.Entry<Long,HomeInsurance> i : homeAgreements.entrySet()){
            if(i.getValue().getInsurerId()==id){
                send.put(i.getValue().getId(),i.getValue());
            }
        }
        return send;
    }

    @Override
    public Map<Long,HouseOrFlatInsurance> findHouseOrFlatAgreementsById(long id){
        Map<Long,HouseOrFlatInsurance> send = new HashMap<>();
        for(Map.Entry<Long,HouseOrFlatInsurance> i : houseOrFlatAgreements.entrySet()){
            if(i.getValue().getInsurerId()==id){
                send.put(i.getValue().getId(),i.getValue());
            }
        }
        return send;
    }


    public void addInjuryAgreement(InjuryInsurance insurance){
        injuryAgreements.put(insurance.getId(),insurance);
    }

    public void addTravelAgreement(TravelInsurance insurance){
        travelAgreements.put(insurance.getId(),insurance);
    }

    public void addHomeAgreement(HomeInsurance insurance){
        homeAgreements.put(insurance.getId(),insurance);
    }

    public void addHouseOrFlatAgreement(HouseOrFlatInsurance insurance){
        houseOrFlatAgreements.put(insurance.getId(),insurance);
    }


}
