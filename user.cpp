//
// Created by Jason on 12/23/2017.
//

#include "std_lib_facilities.h"
#include "meeting_point.cpp"

//a class defining the address of a user
class address{
private:
    String street;
    int nmbr,tk;

public:
    //TODO GETTERS+SETTERS if needed
    address(){};
    address(String street, int nmbr, int tk);

   address set_address(String str,int nmbr,int tk){
      return address(str, nmbr, tk);

   };
};
//a class defining the personal info of a user
class personal_info :: a{
private:
    String name,surname;
    address addr.set_address( str, nmbr, tk);
public:
    //TODO GETTERS+SETTERS if needed
    personal_info(){};
    personal_info(String name,String surname,address addr);

};
//a class defining a user and his functions
class user{
private:

    personal_info info(String name, String surname ,address addr);
    String username;
    String password;
    //TODO GETTERS+SETTERS if needed

};

//class defining a passenger and his functions
class passenger::user{
private:

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

//class defining a driver and his functions
class driver::passenger{
private:
    //vector holding which transports the user is an owner and which he is a driver
    vector<transport> owner,driver;

    //flag to check if the driver is currently driving ,to deal with overlaps
    bool driving;

    //vector holding the transfers that the driver serves
    vector<transfer> serving_transfers;

    //tuple containing date and availability of the driver
    tuple<int,bool> timetable {0,false};

public:
    //gets the available seats for each transport either for transports he owns , or drives
    void check_for_free_seats_on_available_transpots(transport){}

    //parameters needed: plate_number,type,seats,driver,owner
    //returns a transport with the specific above
    transport add_new_transport(){};

    //parameters needed: transport, date, cost, duration
    //declares serving transfer, then we can add it to the serving_transfers
    //using choose_route we choose the route
    //set that date true on the timetable tuple
    //make sure the transport belongs to the driver
    //make sure he is free on the timetable
    transfer declare_serving_transfer(){};

    //search for passengers that are interested on transfering on the specific date and routes that the driver serves
    //the driver must be able to choose and notify the passengers
    void search_for_passenger(){};

    //prints passenger list for specific transfer
    void print_passenger_list_for_transfer(){};

    //prints passenger list for all programmed transfers
    void print_passenger_list_for_programmed_transfers(){};

    //prints passenger list for all successful transfers
    void print_passenger_list_for_successful_transfers(){};

};
//class defining the user admin
class admin::driver{
private:

public:
    //initialize system from file using operation='init'
    //save current state in file using operation='save'
    void sys_control(String operation){};

    //create user depending on the role, different constructor for each role
    void create_usr_acc(String role){};

    //demote,promote a user
    //if a user is demoted to passenger then we need to do the neccessary changes the system files
    //1)cancel passenger seats  on all driver's transfers
    //2)notify passengers, the next time they interact with the program
    void change_role(){};

    //makes sure that this meeting_point gets a unique identification
    void define_meeting_point(){};

    //defines walking duration for a route
    void define_duration_for_route(){};

    //view list of routes that dont have a walking duration
    void view_not_defined_routes(){};

    //overview of meeting points added by users
    //update elements ???
    //clustering of the names

    //returns the top 10 drivers according to rating
    void top(){}

    //returns the worst 10 drivers  according to rating
    void worst(){}

    //returns the 10 most satisfied passengers
    void satisfied(){}

    //returns the 10 most desatisfied passengers
    void disatisfied(){}

    //returns a list with all available transportation means, along with any relevant information
    void view_transports(){}

    //returns a list of all meeting points, along with any relevant information
    void view_meeting_points(){}

    void view_users(){}
    //returns a list of all users
    //for passengers, prints: successful transfers,  summary of cost and average satisfaction
    //for driver, prints: same as passenger, transports that he drives/owns and average satisfaction of his clients

    //increase current day by 1
    void change_date(){}

};


