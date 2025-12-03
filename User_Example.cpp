//
// Created by Shalltell Flores on 12/2/25.
//

#include "User_Example.h"
#include <iostream>

User_Example::User_Example() {

}

User_Example::User_Example(string newName, string newUsername, string newPassword){
    name = newName;
    username = newUsername;
    password = newPassword;
}

string User_Example::getUsername() const {
    return username;
}

void User_Example::addTicket(const Ticket_Example& Ticket_Example){
    // add Ticket_Example into vector array - see .h
}

void User_Example::printTickets() const {
    // loop through Ticket_Example vector array and print each Ticket_Example
    // for example
    // Superbowl | Price: $45

    cout << "---- Tickets for " << name << " ----" << endl;
    cout << "--- <<< not yet available --- add it in >>>" << endl;
}

bool User_Example::login(string enteredUsername, string enteredPassword) const{
    return (enteredUsername == username && enteredPassword == password);
}