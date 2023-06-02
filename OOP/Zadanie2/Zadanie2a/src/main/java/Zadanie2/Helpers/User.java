package Zadanie2.Helpers;

import Zadanie2.Helpers.Address;
import Zadanie2.Helpers.Agreements;

import java.util.ArrayList;


public class User  {

    private long ID = -1 ;
    private static long idUserCounter = 0;
    private String name;
    private String surname;
    private String personalIdentificationNumber;
    private String email;
    private Address address;
    private Address mailingAddress;
    private ArrayList<Agreements> userAgreementsList = new ArrayList<Agreements>(); //??


    public static synchronized String createID(){
        return String.valueOf(idUserCounter++);
    }


    public User(String name, String surname, String personalIdentificationNumber, String email,
                String PSC, String townName, String streetName, String houseNumber, String mailingPSC, String mailingTownName,
                String mailingStreetName, String mailingHouseNumber) throws IllegalArgumentException {
        setName(name);
        setSurname(surname);
        setPersonalIdentificationNumber(personalIdentificationNumber);
        setEmail(email);
        address = new Address(PSC,townName,streetName,houseNumber) {};
        if (PSC == null || PSC.trim().isEmpty() || townName == null || townName.trim().isEmpty() || streetName == null || streetName.trim().isEmpty() || houseNumber == null || houseNumber.trim().isEmpty()){
            mailingAddress = new Address(PSC,townName,streetName,houseNumber) {};
        }
        else mailingAddress = new Address (mailingPSC,mailingTownName,mailingStreetName,mailingHouseNumber) {};
    }


    public String getFullName(){
        return name + " " + surname;
    }

    public String getFullAddress(){
        return address.getAddressPSC()+ " " + address.getAddressTownName() + " " + address.getAddressStreetName() + " " + address.getAddressHouseNumber();
    }

    public String getFullMailingAddress(){
        return mailingAddress.getAddressPSC()+ " " + mailingAddress.getAddressTownName() + " " + mailingAddress.getAddressStreetName() + " " + mailingAddress.getAddressHouseNumber();
    }

    public String getAllInfo(){
        return (this.ID + " " + getFullName() + " " + getFullAddress() + " " + getEmail() + " " + getPersonalIdentificationNumber()) ;
    }


    public String getPersonalIdentificationNumber() {
        return personalIdentificationNumber;
    }

    public String getEmail() {
        return email;
    }

    public long getID() { //TU JE LEN GET
        return ID;
    }





    public void setID(long ID){
        if(ID != -1){
            this.ID = ID;
        } else {
            throw new RuntimeException("ID is already taken");
        }
    }


    public void setName(String name){
        if (name == null || name.trim().isEmpty()) {
            throw new IllegalArgumentException("Name is required");
        }
        this.name = name;
    }

    public void setSurname(String surname){
        if (surname == null || surname.trim().isEmpty()) {
            throw new IllegalArgumentException("Surname is required");
        }
        this.surname = surname;
    }

    public void setPersonalIdentificationNumber(String personalIdentificationNumber){
        if (personalIdentificationNumber == null || personalIdentificationNumber.trim().isEmpty()) {
            throw new IllegalArgumentException("PersonalIdentificationNumber is required");
        }
        this.personalIdentificationNumber = personalIdentificationNumber;
    }

    public void setEmail(String email){
        if (email == null || email.trim().isEmpty()) {
            throw new IllegalArgumentException("Email is required");
        }
        this.email = email;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void setMailingAddress(Address address) {
        this.mailingAddress = address;
    }

    public void setNewAgreement (Agreements agreement){
        this.userAgreementsList.add(agreement);
    }

    public ArrayList<Agreements> getUserAgreementsList(){
        return this.userAgreementsList;
    }

    public void printInfo(){
        System.out.println("ID : " + this.ID);
        System.out.println("NAME : " + getFullName());
        System.out.println("ADDRESS : " + getFullAddress());
        System.out.println("MAILING ADDRESS : " + getFullMailingAddress());
        System.out.println("EMAIL : " + this.email);
        System.out.println("PERSONAL IDENTIFICATION NUMBER : " + this.personalIdentificationNumber);
    }

    @Override
    public String toString() {
        return "Contract ID : " + this.ID + " / Name : " + getFullName();
    }

}
