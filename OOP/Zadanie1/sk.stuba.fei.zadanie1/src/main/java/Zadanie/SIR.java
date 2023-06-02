package Zadanie;

import java.util.ArrayList;

public class SIR extends DisPar{
    private DisPar disPar;
    private EventsList eventsList;
    private ArrayList<DisPar> disParArrayList = new ArrayList<DisPar>();


    //SIR s f

    SIR (Diseases disease,double f, double Beta, double Gamma,int Susceptible, int Infectious,int Recovered) {

        super(disease,f,Beta,Gamma, (int)(Susceptible * (1 - f)), Infectious, (int) (Recovered * (1 + f)));
        eventsList = new EventsList();
    }

    //SIR bez f

    SIR (Diseases disease, double Beta, double Gamma,int Susceptible, int Infectious,int Recovered) {

        super(disease,0,Beta,Gamma, Susceptible, Infectious,Recovered);
        eventsList = new EventsList();
    }

    public void NextDay(){
        this.disParArrayList.add(disPar);
        double newInfected = (this.getBeta()*((this.getSusceptible()*this.getInfectious()) / this.getPopNum()));
        double newRecovered = (this.getGamma()*this.getInfectious());
        this.setSusceptible(this.getSusceptible()-(int)newInfected);
        this.setInfectious(this.getInfectious()+(int)newInfected-(int)newRecovered );
        this.setRecovered(this.getRecovered()+(int)newRecovered);

    }
}
