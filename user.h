//
// Created by Jason on 12/23/2017.
//

#ifndef TRANSITPROGRAM_USERS_H
#define TRANSITPROGRAM_USERS_H

class address{
    String street;
    int nmbr,tk;
    address(String street, int nmbr, int tk);

};

class personal_info{
    String name,username,password;
    address(street,nmbr,tk);
    personal_info(String name,String username,String password,address addr);

};

class user {
private:
public:
    personal_info( name, username, password, addr);

    void login (){}
    void manage_favorites(){}
    void transport_route(){}
    void transport_transfer(){}


    //function that exits the program
    //save current state to file
    //load state from file
};


#endif //TRANSITPROGRAM_USERS_H
