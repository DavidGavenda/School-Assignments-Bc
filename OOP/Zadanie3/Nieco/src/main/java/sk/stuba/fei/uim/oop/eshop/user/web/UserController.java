package sk.stuba.fei.uim.oop.eshop.user.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;
import sk.stuba.fei.uim.oop.eshop.user.domain.User;
import sk.stuba.fei.uim.oop.eshop.user.service.UserService;

import javax.validation.Valid;
import java.util.Optional;

@Controller
@RequestMapping("/user")
public class UserController {

    private final UserService userService;


    @Autowired
    public UserController(UserService userService) {
        this.userService = userService;

    }

    @GetMapping("/")
    public String all(Model model) {
        model.addAttribute("users", userService.findAllUsers());
        return "user/all";
    }

    @GetMapping("/{id}")
    public String byId(@PathVariable long id, Model model) {
        Optional<User> userById = userService.findUserById(id);
        if (userById.isPresent()) {
            User user = userById.get();
            model.addAttribute("user", user);
            model.addAttribute("injuryAgreements",userService.findInjuryAgreementsById(id));
            model.addAttribute("travelAgreements",userService.findTravelAgreementsById(id));
            model.addAttribute("homeAgreements",userService.findHomeAgreementsById(id));
            model.addAttribute("houseOrFlatAgreements",userService.findHouseOrFlatAgreementsById(id));
        }
        return "user/one";
    }

    @GetMapping("/add")
    public String addForm(Model model) {
        model.addAttribute("user", new User());
        return "user/add";
    }

    @PostMapping("/add")
    public String addSubmit(@ModelAttribute  @Valid User user, BindingResult bindingResult) {
        if(bindingResult.hasErrors()){
            return "user/add";
        }
        userService.addUser(user);
        return "redirect:/user/";
    }




    /////NOVE

    @GetMapping("/update/{id}")
    public String update(@PathVariable long id, Model model){
        Optional<User> userById = userService.findUserById(id);
        if(userById.isPresent()){
            User user = userById.get();
            model.addAttribute("user",user);
        }
        return "user/update";
    }

    @PostMapping("/update")
    public String updateSubmit(@ModelAttribute User user) {
        userService.addUser(user);
        return "redirect:/user/";
    }

    @GetMapping("addAgreement/{id}")
    public String addAgreement(){
        return "/user/addAgreement";
    }



}