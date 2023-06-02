package sk.stuba.fei.uim.oop.eshop.user.domain;

import lombok.*;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import java.util.Set;

@Data
@NoArgsConstructor

public class User extends Entity {

    @NotEmpty
    private String name;
    @NotEmpty
    private String surname ;
    @NotEmpty
    private String birthNumber;
    @NotEmpty
    @Email
    private String email;
    @NotNull
    private Address address;
    private Address mailingAddress;
    protected Set<Agreement> agreements;

    public User(String name, String surname, String birthNumber, String email, Address address, Address mailingAddress) throws IllegalArgumentException {
        this.name = name;
        this.surname = surname;
        this.birthNumber = birthNumber;
        this.email = email;
        this.address = address;
        this.mailingAddress = mailingAddress;
    }

    public User(String name, String surname, String birthNumber, String email, Address address)throws IllegalArgumentException {
        this(name,surname,birthNumber,email,address,address);
    }
}
