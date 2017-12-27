//
// Created by Jason on 12/27/2017.
//

#ifndef TRANSITPROGRAM_MEETINGPOINTS_H
#define TRANSITPROGRAM_MEETINGPOINTS_H



class meeting_point {
    //TODO id should be coordinates
    int id;
    String description;
    vector<String> keywords;

};
class route{
    meeting_point starting_point, final_point;
    //vector consisting of all the points in the route
    vector<meeting_point> complete_route;
    //set starting point
    //set final point
};
class transfer::route{
    int date;
    route route;
    transport transport;
    user user;
    //set date
    //set user
    //set transport
    //set route
};
//check if transport is the small / large bus as it can pass through many meeting points
//motobikes/bikes/cars can go to a meeting point only if they declared that they can, can fully do the transfer on a route that starts from the starting point


#endif //TRANSITPROGRAM_MEETINGPOINTS_H
