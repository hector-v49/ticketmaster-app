//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_USER_EXAMPLE_H
#define SCHOOL_PROJECTS_USER_EXAMPLE_H
#include <string>
#include <vector>
#include "Ticket_Example.h"

using namespace std;


class User_Example {
public:
    User_Example();
    User_Example(string newName, string newUsername, string newPassword);

    string getUsername() const;

    // store purchased tickets in a vector/array
    void addTicket(const Ticket_Example& Ticket_Example);

    void printTickets() const;

    bool login(string enteredUsername, string enteredPassword) const;

private:
    string name;
    string username;
    string password;
    vector<Ticket_Example> tickets;
};


#endif //SCHOOL_PROJECTS_USER_EXAMPLE_H