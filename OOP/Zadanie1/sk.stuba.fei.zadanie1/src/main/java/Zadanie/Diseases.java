package Zadanie;

public enum Diseases {
    MEASLES(95, "Measles"),
    PEERTUSSIS(92,"Pertussis"),
    DIPHTHERIA(86,"Diphteria"),
    RUBELLA(83,"Rubella"),
    SMALLPOX(80,"Smallpox"),
    POLIO(80,"Polio"),
    MUMPS(75,"Mumps"),
    SARS(50,"Sars"),
    COVID(74,"Covid"), //stale nie iste,velky rozptyl
    EBOLA(60,"Ebola"),
    INFLUENZA(44,"Influenza");

    private int BorderOfCollectiveImmunity;
    private String Name;

    Diseases(int BorderOfCollectiveImmunity,String Name){
        this.BorderOfCollectiveImmunity = BorderOfCollectiveImmunity;
        this.Name=Name;
    }

    public int getBorderOfCollectiveImmunity() {
        return BorderOfCollectiveImmunity;
    }

    public String getName() {
        return Name;
    }
}

//zdroj https://en.wikipedia.org/wiki/Herd_immunity
