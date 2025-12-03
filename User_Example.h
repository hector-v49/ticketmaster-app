//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_USER_EXAMPLE_H
#define SCHOOL_PROJECTS_USER_EXAMPLE_H
#include <string>
#include <vector>
#include "Ticket_Example.h"

using namespace std;


class User {
public:
    User();
    User(string newName, string newUsername, string newPassword);

    string getUsername() const;

    // store purchased tickets in a vector/array
    void addTicket(const Ticket& ticket);

    void printTickets() const;

    bool login(string enteredUsername, string enteredPassword) const;

private:
    string name;
    string username;
    string password;
    vector<Ticket> tickets;
};


#endif //SCHOOL_PROJECTS_USER_EXAMPLE_H