package sk.stuba.fei.oop.skuska.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import sk.stuba.fei.oop.skuska.service.ComponentsService;
import sk.stuba.fei.oop.skuska.service.VehicleService;

@Controller
@RequestMapping("/vehicle")
public class VehicleController {

    private final VehicleService vehicleService;
    private final ComponentsService componentsService;

    @Autowired
    public VehicleController(VehicleService vehicleService,ComponentsService componentsService){
        this.vehicleService = vehicleService;
        this.componentsService = componentsService;
    }

    @GetMapping("/")
    public String all(Model model){
        model.addAttribute("lightTanks",vehicleService.findAllLightTanks());
        model.addAttribute("heavyTanks",vehicleService.findAllHeavyTanks());
        model.addAttribute("delostrelectvos",vehicleService.findAllDelostrelectvo());
        return "vehicle/all";
    }

    @GetMapping("/detailDelostrelectvo/{id}")
    public String detailDelostrelectvo(@PathVariable long id, Model model){
        model.addAttribute("vehicle",vehicleService.findDelostrelectvo(id));
        return "component/detailDelostrelectvo";
    }

    @GetMapping("/detailLightTank/{id}")
    public String detailLightTank(@PathVariable long id, Model model){
        model.addAttribute("vehicle",vehicleService.findLightTank(id));
        return "component/detailLightTank";
    }

    @GetMapping("/detailHeavyTank/{id}")
    public String detailHeavyTank(@PathVariable long id, Model model){
        model.addAttribute("vehicle",vehicleService.findHeavyTank(id));
        return "component/detailHeavyTank";
    }


}
