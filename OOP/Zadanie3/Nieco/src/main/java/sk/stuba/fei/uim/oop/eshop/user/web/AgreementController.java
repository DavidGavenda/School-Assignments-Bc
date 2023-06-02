package sk.stuba.fei.uim.oop.eshop.user.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import sk.stuba.fei.uim.oop.eshop.agreements.Agreement;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.InjuryInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.LifeInsurance.TravelInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HomeInsurance;
import sk.stuba.fei.uim.oop.eshop.agreements.NonLifeInsurance.HouseOrFlatInsurance;
import sk.stuba.fei.uim.oop.eshop.user.domain.User;
import sk.stuba.fei.uim.oop.eshop.user.service.UserService;

import javax.validation.Valid;
import java.util.Optional;


@Controller
public class AgreementController {
    private final UserService userService;


    @Autowired
    public AgreementController(UserService userService){
        this.userService = userService;

    }



    @GetMapping("/add_Injury")
    public String addInjuryAgreement(Model model,User user){
        model.addAttribute("agreement",new InjuryInsurance());
        model.addAttribute("user",userService.findUserById(user.getId()));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/addInjury";
    }

    @PostMapping("/add_Injury")
    public String agreementAddSubmit(@ModelAttribute @Valid InjuryInsurance agreement, @ModelAttribute User user, BindingResult bindingResult) {
        if(bindingResult.hasErrors()){
            return"agreement/addInjury";
        }
        userService.addInjuryAgreement(agreement);
        return "redirect:/user/";
    }


    @GetMapping("/add_Travel")
    public String addTravelAgreement(Model model,User user){
        model.addAttribute("agreement",new TravelInsurance());
        model.addAttribute("user",userService.findUserById(user.getId()));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/addTravel";
    }

    @PostMapping("/add_Travel")
    public String agreementAddSubmit(@ModelAttribute TravelInsurance agreement,@ModelAttribute User user) {
        userService.addTravelAgreement(agreement);
        return "redirect:/user/";
    }

    @GetMapping("/add_Home")
    public String addHomeAgreement(Model model,User user){
        model.addAttribute("agreement",new HomeInsurance());
        model.addAttribute("user",userService.findUserById(user.getId()));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/addHome";
    }

    @PostMapping("/add_Home")
    public String agreementAddSubmit(@ModelAttribute HomeInsurance agreement,@ModelAttribute User user) {
        userService.addHomeAgreement(agreement);
        return "redirect:/user/";
    }

    @GetMapping("/add_HouseOrFlat")
    public String addHouseOrFlatAgreement(Model model,User user){
        model.addAttribute("agreement",new HouseOrFlatInsurance());
        model.addAttribute("user",userService.findUserById(user.getId()));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/addHouseOrFlat";
    }

    @PostMapping("/add_HouseOrFlat")
    public String agreementAddSubmit(@ModelAttribute HouseOrFlatInsurance agreement,@ModelAttribute User user) {
        userService.addHouseOrFlatAgreement(agreement);
        return "redirect:/user/";
    }


    @GetMapping("/detail_Injury/{id}")
    public String detailInjury(@PathVariable long id,Model model){
        model.addAttribute("agreement",userService.findInjuryAgreementById(id));
        return "agreement/oneInjury";
    }

    @GetMapping("/detail_Travel/{id}")
    public String detailTravel(@PathVariable long id,Model model){
        model.addAttribute("agreement",userService.findTravelAgreementById(id));
        return "agreement/oneTravel";
    }

    @GetMapping("/detail_Home/{id}")
    public String detailHome(@PathVariable long id,Model model){
        model.addAttribute("agreement",userService.findHomeAgreementById(id));
        return "agreement/oneHome";
    }

    @GetMapping("/detail_HouseOrFlat/{id}")
    public String detailHouseOrFlat(@PathVariable long id,Model model){
        model.addAttribute("agreement",userService.findHouseOrFlatAgreementById(id));
        return "agreement/oneHouseOrFlat";
    }



    @GetMapping("/update_Home/{id}")
    public String updateHome(@PathVariable long id, Model model){
        model.addAttribute("agreement",userService.findHomeAgreementById(id));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/updateHome";
    }

    @PostMapping("/update_Home")
    public String updateSubmit(@ModelAttribute HomeInsurance insurance) {
        userService.addHomeAgreement(insurance);
        return "redirect:/user/";
    }

    @GetMapping("/update_HouseOrFlat/{id}")
    public String updateHouseOrFlat(@PathVariable long id, Model model){
        model.addAttribute("agreement",userService.findHouseOrFlatAgreementById(id));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/updateHouseOrFlat";
    }

    @PostMapping("/update_HouseOrFlat")
    public String updateSubmit(@ModelAttribute HouseOrFlatInsurance insurance) {
        userService.addHouseOrFlatAgreement(insurance);
        return "redirect:/user/";
    }



    @GetMapping("/update_Injury/{id}")
    public String updateInjury(@PathVariable long id, Model model){
        model.addAttribute("agreement",userService.findInjuryAgreementById(id));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/updateInjury";
    }

    @PostMapping("/update_Injury")
    public String updateSubmit(@ModelAttribute InjuryInsurance insurance) {
        userService.addInjuryAgreement(insurance);
        return "redirect:/user/";
    }



    @GetMapping("/update_Travel/{id}")
    public String updateTravel(@PathVariable long id, Model model){
        model.addAttribute("agreement",userService.findTravelAgreementById(id));
        model.addAttribute("users",userService.findAllUsers());
        return "agreement/updateTravel";
    }

    @PostMapping("/update_Travel")
    public String updateSubmit(@ModelAttribute TravelInsurance insurance) {
        userService.addTravelAgreement(insurance);
        return "redirect:/user/";
    }





}
