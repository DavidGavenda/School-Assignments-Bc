package Zadanie2;

import Zadanie2.Helpers.API;
import Zadanie2.Helpers.Agreements;
import Zadanie2.Helpers.User;
import Zadanie2.LifeInsurance.AccidentInsurance;
import Zadanie2.LifeInsurance.ENUMS.TerritorialValidity;

public class Main {
    public static void main(String[] args) {
        API api = new API();
        User David = new User("David","Gavenda","123456/7890","gavendadavid@gmail.com","02951","Tapesovo","Tapesovo","123","","","","");
        api.addUser(David);
        Agreements poistenie = new AccidentInsurance(David,3123,13123123,12,TerritorialValidity.WORLD,"22.2.2012","1.1.2013",David,"1.2.2022",1222,122);
        api.addAgreement(poistenie);
        api.getAllUsers();
        api.getAllAgreements();
    }
}
