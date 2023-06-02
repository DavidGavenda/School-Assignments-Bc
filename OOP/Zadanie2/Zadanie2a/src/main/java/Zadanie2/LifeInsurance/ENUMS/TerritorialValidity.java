package Zadanie2.LifeInsurance.ENUMS;

public enum TerritorialValidity {
    SLOVAKIA(1,"Slovakia"),
    WORLD(2,"World"),
    WORLDANDSLOVAKIA(3,"World and Slovakia");

    private int number;
    private String name;

    TerritorialValidity(int number, String name) {
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
