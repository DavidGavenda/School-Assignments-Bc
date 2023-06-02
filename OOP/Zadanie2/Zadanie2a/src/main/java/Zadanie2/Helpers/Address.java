package Zadanie2.Helpers;

public class Address {
    private String addressPSC;
    private String addressTownName;
    private String addressStreetName;
    private String addressHouseNumber;

    public Address(){};



    public Address(String addressPSC, String addressTownName, String addressStreetName, String addressHouseNumber) throws IllegalArgumentException {
        setAddressPSC(addressPSC);
        setAddressTownName(addressTownName);
        setAddressStreetName(addressStreetName);
        setAddressHouseNumber(addressHouseNumber);
    }

    public void setAddressPSC(String addressPSC){
        if (addressPSC == null) { //mal som toto  || addressPSC.trim().isEmpty() a nejako chyby hadzalo pri vsetkych styroch
            throw new IllegalArgumentException("AddressPSC is required");
        }
        this.addressPSC = addressPSC;
    }

    public void setAddressTownName(String addressTownName){
        if (addressTownName == null) {
            throw new IllegalArgumentException("AddressTownName is required");
        }
        this.addressTownName = addressTownName;
    }

    public void setAddressStreetName(String addressStreetName){
        if (addressStreetName == null) {
            throw new IllegalArgumentException("AddressStreetName is required");
        }
        this.addressStreetName = addressStreetName;
    }

    public void setAddressHouseNumber(String addressHouseNumber){
        if (addressHouseNumber == null) {
            throw new IllegalArgumentException("AddressHouseNumber is required");
        }
        this.addressHouseNumber = addressHouseNumber;
    }

    public String getAddressPSC() {
        return addressPSC;
    }

    public String getAddressTownName() {
        return addressTownName;
    }

    public String getAddressStreetName() {
        return addressStreetName;
    }

    public String getAddressHouseNumber() {
        return addressHouseNumber;
    }
}
