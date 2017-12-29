//
// Created by Jason on 12/23/2017.
//

#ifndef TRANSITPROGRAM_USERS_H
#define TRANSITPROGRAM_USERS_H


#include "transport.h"

//a class defining the address of a user
class address{
private:
    String street;
    int nmbr,tk;

public:
    //TODO GETTERS+SETTERS if needed
    address(){};
    address(String street, int nmbr, int tk);

};
//a class defining the personal info of a user
class personal_info {
private:
    String name,surname;
    address(street,nmbr,tk);
public:
    //TODO GETTERS+SETTERS if needed
    //personal_info(){};
    personal_info(String name,String surname,address addr);

};
//a class defining a user
class user{
private:

    personal_info info(String name, String surname ,address addr);
    String username;
    String password;

public:
    //TODO GETTERS+SETTERS if needed

    //validates the user and provides access to the platform,returns 0 when access is denied , 1 when is successful
    //if this is the first user entering the platform , initiliaze using the last saved state(from one or more files)
    int login (String username, String password){}
    //manages most-least favorite transportation means
    //functionallity:
    //Insert data, View data, delete data
    void manage_favorites(){}
    //find and choose route
    //1) choose from existing meeting points (show,choose) or search,choose using keywords ,not case sensitive
    //2) define and choose a new meeting point(insert that point to the meeting point vector,making sure the system adds a unique identifier to it)
    //3) the user must choose cost(min=ask for a free ride , max=cost is irrelevant)
    route choose_route(){}
    //find transport for a route
    //choose route using choose_route()
    void find_transportation_for_route(){}
    //declare interest of finding transportation for specific route????????
    //choose route using choose_route()
    //the route must be either one of the user's interested ones or a new
    //if its a new one the route is added to the interested routes ,adding an irrelevant cost
    //passenger must be able to set the max cost of this transfer,which can be different from the cost of the selected route
    //if the passenger doesnt set the max cost , then the cost is considered the routes' default
    void declare_interest_for_transfer(int date){}

    //find the transport for a specific route and day
    //choose route using choose_route()
    //the route must be either one of the user's interested ones or a new
    //if its a new route.its added to the interested routes ,adding an irrelevant cost
    //if its a new transfer, its added to the interested transfers ,without adding cost
    //search based on user's favorites, least favorites transportation means shouldnt be included in the available transportation
    //only routes that dont exceed the max money that the user defined shall be presented
    //if there not any favorite transportation means(including walking),other transportation option shall be presented
    //the result of the search will be the transport's info of the specific transfer
    //check availability of seats
    transport find_transport_for_transfer(int date){}
    //book seats for transfer on a specific transport
    void book_seat(){}

    //view routes interested by the user
    void view_interested_routes(){}

    //view transfer's of the user
    //1)active transfers ,planned for the future
    //2)pending transfers ,not planned
    //3)completed transfers, planned
    void view_transfers(){}

    //print seat of a user for a transfer
    void print_seat(){}

    //cancel seat of a user for a transfer
    void cancel_seat(){}

    //view /rate / comment successful transfers
    //rating must be 0-100
    void view_rate_comment(){}

    //terminate program and save current state
    void terminate(){}

    //log out user , without terminating the program , so that a new user can log in
    void log_out(){}
    //function that exits the program
    //save current state to file
    //load state from file
};

class passenger::user{

};

//class defining the driver
class driver::user{
private:
    //vector holding which transports the user is an owner and which he is a driver
    vector<transport> owner,driver;
    //flag to check if the driver is currently driving ,to deal with overlaps
    bool driving;
    //vector holding the transfers that the driver serves
    vector<transfer> serving_transfers;
public:
    //gets the available seats for each transport either for transports he owns , or drives
    void check_for_free_seats_on_available_transpots(transport){}

    //plate_number / type / seats /owner / driver
    void add_new_transport(){

    };
};

#endif //TRANSITPROGRAM_USERS_H
