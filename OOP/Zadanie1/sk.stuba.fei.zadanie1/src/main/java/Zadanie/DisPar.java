package Zadanie;

import Zadanie.Diseases;

public abstract class DisPar {
    protected final Diseases disease;
    private final double f;
    private final int PopNum;
    private double Beta,Gamma;
    private int Susceptible,Infectious,Recovered;

    public DisPar(Diseases disease, double f, double beta, double gamma, int susceptible, int infectious, int recovered) {
        this.disease = disease;
        this.f = f;
        Beta = beta;
        Gamma = gamma;
        Susceptible = susceptible;
        Infectious = infectious;
        Recovered = recovered;
        this.PopNum = Susceptible + Infectious + Recovered;
    }

    public Diseases getDisease() {
        return disease;
    }

    public double getBeta() {
        return Beta;
    }

    public double getGamma() {
        return Gamma;
    }

    public int getSusceptible() {
        return Susceptible;
    }

    public int getInfectious() {
        return Infectious;
    }

    public int getRecovered() {
        return Recovered;
    }

    public void setBeta(double beta) {
        Beta = beta;
    }

    public void setGamma(double gamma) {
        Gamma = gamma;
    }

    public void setSusceptible(int susceptible) {
        Susceptible = susceptible;
    }

    public void setInfectious(int infectious) {
        Infectious = infectious;
    }

    public void setRecovered(int recovered) {
        Recovered = recovered;
    }

    public int getPopNum() {
        return PopNum;
    }
}
