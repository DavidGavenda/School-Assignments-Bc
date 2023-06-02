package Zadanie2.NonLifeInsurance.ENUMS;

public enum TypeOfProperty {
    FLAT(1, "Flat"),
    FAMILYHOUSEBRICK(2, "Family House Brick"),
    FAMILYHOUSEWOOD(3, "Family House Wood");

    private int number;
    private String propertyName;

    TypeOfProperty(int number, String propertyName) {
        this.number = number;
        this.propertyName = propertyName;
    }

    public int getNumber() {
        return number;
    }

    public String getPropertyName() {
        return propertyName;
    }
}
