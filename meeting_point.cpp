//
// Created by Jason on 12/27/2017.
//


#include "transport.cpp"


//this class defines a specific point on the map
class meeting_point {
    //TODO id should be coordinates , GETTERS + SETTERS if needed
private:
    int id;
    String description;
    vector<String> keywords;
public:
    meeting_point(int id,String description,vector<String> keywords){}
    meeting_point() {};
};
//this class is a group of meeting points
class route {
private:
    double duration;
    meeting_point starting_point, final_point;
    //vector consisting of all the points in the route or only by their ids I am not sure yet
    vector<meeting_point> complete_route;
    //TODO SETTERS + GETTERS if needed
public:
    route(){};
    route(meeting_point starting_point,meeting_point final_point,vector<meeting_point> complete_route){};
};
//this class is a group of meeting points at a given date booked by 1+ users using 1+ transports
class transfer{
private:
    int date;
    route route;
    // a vector of all transports serving this transfer
    vector<transport> serving_transports;
    vector <user> users;
public:
    transfer(int date,route route,vector<transport>transports,vector<user>users){};
    transfer(){};
    //TODO SETTERS + GETTERS if needed


};

//check if transport is the small / large bus as it can pass through many meeting points
//motobikes/bikes/cars can go to a meeting point only if they declared that they can, can fully do the transfer on a route that starts from the starting point