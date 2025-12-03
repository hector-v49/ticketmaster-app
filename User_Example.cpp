//
// Created by Shalltell Flores on 12/2/25.
//

#include "User_Example.h"
#include <iostream>

User::User() {

}

User::User(string newName, string newUsername, string newPassword){
    name = newName;
    username = newUsername;
    password = newPassword;
}

string User::getUsername() const {
    return username;
}

void User::addTicket(const Ticket& ticket){
    // add ticket into vector array - see .h
}

void User::printTickets() const {
    // loop through ticket vector array and print each ticket
    // for example
    // Superbowl | Price: $45

    cout << "---- Tickets for " << name << " ----" << endl;
    cout << "--- <<< not yet available --- add it in >>>" << endl;
}

bool User::login(string enteredUsername, string enteredPassword) const{
    return (enteredUsername == username && enteredPassword == password);
}