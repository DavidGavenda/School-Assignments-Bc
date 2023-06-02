package sk.stuba.fei.uim.oop.eshop.agreements;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;
import sk.stuba.fei.uim.oop.eshop.user.domain.Entity;

import javax.validation.constraints.*;
import java.time.LocalDate;
import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
public abstract class Agreement extends Entity {

    //ZACAL SOM ROBIT TIE VALIDACIE ALE VACSINOU SOM ICH ODSTRANIL
    //PRI ENUMOCH SA MYSLIM ZE ANI NULL VYBRAT NEDA,KEDZE NIE JE V MOZNOSTIACH
    @PastOrPresent //Akoze fakt netusim preco vyhodi chybu a nie ze mi ju pekne vypise
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate creationDate;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate validitySince;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate validityTill;
    @NotNull
    private long insurerId;
    @Min(0)
    private double insuranceAmount;
    @Min(0)
    private double monthlyPayment;

}
