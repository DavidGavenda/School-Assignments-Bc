package Zadanie;

public class Events {
    private String type,name = "EMPTY";
    private boolean active;
    private double betta,gamma;

    public Events(String type, String name, double betta, double gamma) {
        this.type = type;
        this.name = name;
        this.active = false;
        this.betta = betta;
        this.gamma = gamma;
    }

    public String getType() {
        return type;
    }

    public String getName() {
        return name;
    }

    public boolean isActive() {
        return active;
    }

    public double getBetta() {
        return betta;
    }

    public double getGamma() {
        return gamma;
    }

    public void setActive(boolean active) {
        this.active = active;
    }


}
