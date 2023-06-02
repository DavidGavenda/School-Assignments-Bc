package Zadanie2.LifeInsurance.ENUMS;

public enum TravelPurpose {
    WORK(1,"Work"),
    RECRATION(2,"Recreation"),
    SPORT(3,"Sport"),
    ETC(4,"Et cetera");

    private int number;
    private String name;

    TravelPurpose(int number, String name) {
        this.number = number;
        this.name = name;
    }

    public int getNumber() {
        return number;
    }

    public String getName() {
        return name;
    }
}
