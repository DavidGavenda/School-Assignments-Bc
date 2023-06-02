package sk.stuba.fei.oop.skuska.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import sk.stuba.fei.oop.skuska.domain.Delo.DeloMalehoKalibru;
import sk.stuba.fei.oop.skuska.service.ComponentsService;
import sk.stuba.fei.oop.skuska.service.VehicleService;

@Controller
@RequestMapping("/component")
public class ComponentController {

    private final ComponentsService componentsService;
    private final VehicleService vehicleService;

    @Autowired
    public ComponentController(ComponentsService componentsService,VehicleService vehicleService){
        this.componentsService = componentsService;
        this.vehicleService = vehicleService;
    }

    @GetMapping("/")
    public String all(Model model){
        model.addAttribute("deloMalekoKalibrus",componentsService.findAllDeloMalehoKalibru());
        model.addAttribute("deloVelkehoKalibrus",componentsService.findAllDeloVelkehoKalibru());
        model.addAttribute("kolesovyPodvozoks",componentsService.findAllKolesovyPodvozok());
        model.addAttribute("pasovyPodvozoks",componentsService.findAllPasovyPodvozok());
        model.addAttribute("vezaSDelomMalehoKalibrus",componentsService.findAllVezaSDelomMalehoKalibru());
        model.addAttribute("vezaSDelomVelkehoKalibrus",componentsService.findAllVezaSDelomVelkehoKalibru());
        return "component/all";
    }

    @GetMapping("/detailDeloMaleho/{id}")
    public String detailDeloMaleho(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findDeloMalehoKalibru(id));
        return "component/detailDeloMaleho";
    }

    @GetMapping("/detailKolesovy/{id}")
    public String detailKolesovy(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findKolesovyPodvozok(id));
        return "component/detailKolesovy";
    }

    @GetMapping("/detailPasovy/{id}")
    public String detailPasovy(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findPasovyPodvozok(id));
        return "component/detailPasovy";
    }

    @GetMapping("/detailVelkeho/{id}")
    public String detailVelkeho(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findDeloVelkehoKalibru(id));
        return "component/detailVelkeho";
    }

    @GetMapping("/detailVezaSMalym/{id}")
    public String detailVezaSMalym(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findVezaSDelomMalehoKalibru(id));
        return "component/detailVezaSMalym";
    }

    @GetMapping("/detailVezaSVelkym/{id}")
    public String detailVezaSVelkym(@PathVariable long id, Model model){
        model.addAttribute("component",componentsService.findVezaSDelomVelkehoKalibru(id));
        return "component/detailVezaSVelkym";
    }


}
