package sk.stuba.fei.uim.oop;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.core.io.Resource;
import sk.stuba.fei.uim.oop.eshop.user.service.UserService;

@SpringBootApplication
public class OnlineEshopApplication implements CommandLineRunner {


    private final UserService userService;


    public OnlineEshopApplication(UserService userService) {

        this.userService = userService;
    }

    public static void main(String[] args) {
        SpringApplication.run(OnlineEshopApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
    }


}
