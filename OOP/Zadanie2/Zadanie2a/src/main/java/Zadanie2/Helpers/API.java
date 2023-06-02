package Zadanie2.Helpers;

import java.util.Map;

public class API extends InsuranceSystem {

    public API() {
    }

    public void addUser(User user){
        user.setID(newUserID);
        userMap.put(newUserID,user);
        this.newUserID ++;
    }

    public void getAllUsers(){
        for(Map.Entry<Long,User> entry : userMap.entrySet()) {
            System.out.println(entry.getValue().toString());
        }
    }

    public void getUsersAgreements(long ID){
        this.userMap.get(ID).getUserAgreementsList();
    }

    public void getUsersInfo(long ID){
        this.userMap.get(ID).getAllInfo();
    }




    public void addAgreement(Agreements agreements){
        agreements.setID(this.newAgreementID);
        this.agreementsMap.put(this.newAgreementID,agreements);
        this.userMap.get(agreements.getInsurer().getID()).setNewAgreement(agreements);
        this.newAgreementID++;
    }

    public void getAllAgreements(){
        for(Map.Entry<Long,Agreements> entry : agreementsMap.entrySet()){
            System.out.println(entry.getValue().toString());
        }
    }





}
