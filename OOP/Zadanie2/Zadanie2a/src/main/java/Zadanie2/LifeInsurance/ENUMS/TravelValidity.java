package Zadanie2.LifeInsurance.ENUMS;

public enum TravelValidity {
    WITHINEU("Withing EU"),
    OUTSIDEEU("Outside of EU");

    private String name;

    TravelValidity(String name){
        this.name = name;
    }
}
