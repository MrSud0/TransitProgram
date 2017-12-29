//
// Created by Jason on 12/23/2017.
//


#include "user.cpp"


class transport {
private:
    String plate_number,description;
    int seats,free_seats;
    user onwer,driver;
    //if the trasport is a large/small bus it can go through plenty
    //vector<meeting_point> meeting_points or route bus_route

    //a car or bike or motobike can only go to a meeting point if it has declared that it can ???
    // private void check_availabity();
public:

    //constructor
    transport(String plate_number, const char *description, int seats){}

    //TODO complete and test the functions and find a way to fix that drivers can only drive one transport per given moment
    transport add_bike(String plate_number,user owner){
        //takes plate number and creates a object transport with the attributes of a bike and assigns it to the user as owner
        return transport (plate_number,"Bike",1);
    };

    transport add_motobike(String plate_number,int seats,user any){
        //check that seats are >= 1 and <=2
        //takes plate number and creates a object transport with the attributes of a motobike and assigns it to the user as owner or driver
        //if user is driver available seats must be 1 else  2
        return transport  (plate_number,"Motobike",seats);

    };
    transport add_car(String plate_number,user driver){
        //takes plate number and creates a object transport with the attributes of a car and and assigns it to the user as driver
        return transport  (plate_number,"Car",5);

    };
    transport add_smallBus(String plate_number,int seats,user driver){
        //check that seats are >= 10 and <=20
        //takes plate number and creates a object transport with the attributes of a small bus and and assigns it to the user as driver
        return transport (plate_number,"Small City Bus",seats);

    };
    transport add_largeBus(String plate_number,int seats,user driver){
        //check that seats are >= 20 and <=40
        //takes plate number and creates a object transport with the attributes of a large bus and and assigns it to the user as driver
        return transport (plate_number,"Large city Bus",seats);

    };
    transport walk(){
        //no restrictions , no owner . no driver
    };
    //TODO GETTER AND SETTERS if  needed
};
