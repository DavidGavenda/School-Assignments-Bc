package Zadanie2.Helpers;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;


public abstract class Agreements {
    protected long ID = -1;
    protected  String creationDate ;
    protected User insurer;
    protected String insuranceSince;
    protected String insuranceTill;
    protected double indemnity;
    protected double monthlyPayment;



    private String getDateTime(){
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = new Date();
        return dateFormat.format(date);
    }

    public Agreements() {
    }

    protected Agreements(String creationDate, User insurer, String insuranceSince, String insuranceTill, double indemnity, double monthlyPayment) {
        this.creationDate = creationDate;
        this.insurer = insurer;
        this.insuranceSince = insuranceSince;
        this.insuranceTill = insuranceTill;
        this.indemnity = indemnity;
        this.monthlyPayment = monthlyPayment;
    }

    public Agreements(User insurer, String insuranceSince, String insuranceTill, double indemnity, double monthlyPayment) {
        this.creationDate = getDateTime();
        this.insurer = insurer;
        this.insuranceSince = insuranceSince;
        this.insuranceTill = insuranceTill;
        this.indemnity = indemnity;
        this.monthlyPayment = monthlyPayment;
    }

    public void setID(long ID){
        if(ID != -1){
            this.ID = ID;
        } else {
            throw new RuntimeException("ID is already taken");
        }
    }

    public User getInsurer(){
        return this.insurer;
    }

    public long getID() {
        return ID;
    }

    public void setInsuranceSince(String insuranceSince) {
        this.insuranceSince = insuranceSince;
    }

    public void setInsuranceTill(String insuranceTill) {
        this.insuranceTill = insuranceTill;
    }

    public void setIndemnity(double indemnity) {
        this.indemnity = indemnity;
    }

    public void setMonthlyPayment(double monthlyPayment) {
        this.monthlyPayment = monthlyPayment;
    }

    @Override
    public String toString() {
        return "Contract ID : " + this.ID + " / Created : " + this.creationDate;
    }
}
