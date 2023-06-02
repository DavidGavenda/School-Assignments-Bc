package sk.stuba.fei.uim.oop.eshop.user.domain;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotEmpty;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Address {

    @NotEmpty
    private String psc;
    @NotEmpty
    private String town;
    @NotEmpty
    private String street;
    @NotEmpty
    private String number;

    /////////OPRAV TO, NEJDE TO AKO BY MALO PRI VALIDACII
}
