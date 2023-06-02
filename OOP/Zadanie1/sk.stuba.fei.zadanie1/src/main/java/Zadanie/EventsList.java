package Zadanie;

import java.util.ArrayList;

public class EventsList {
    private ArrayList<Events> eventsArrayList = new ArrayList<Events>();

    EventsList() {
        this.eventsArrayList.add(new Events("Deceleration","Home quarantine",0.0,0.0));
        this.eventsArrayList.add(new Events("Deceleration","Social distancing",0.0,0.0));
        this.eventsArrayList.add(new Events("Deceleration","Mandatory masks",0.0,0.0));
        this.eventsArrayList.add(new Events("Deceleration","Vaccine",0.0,0.0));
        this.eventsArrayList.add(new Events("Deceleration","Lockdown",0.0,0.0));
        this.eventsArrayList.add(new Events("Deceleration","National Emergency",0.0,0.0));

        this.eventsArrayList.add(new Events("Acceleration","5G conspiracy",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Protests",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Toilet paper shortage",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Alien attack",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Natural disaster",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Civil war",0.0,0.0));
        this.eventsArrayList.add(new Events("Acceleration","Mutation",0.0,0.0));
    }

    public Events getEventById(int id) {
        return this.eventsArrayList.get(id);
    }
}
