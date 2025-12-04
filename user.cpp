//  User.cpp
//  User
//  Created by Sandra Robles
#include "User.h"

User::User()
{
    name = "";
    username = "";
    password = "";
}

User::User(string newName, string newUsername, string newPassword)
{
    name = newName;
    username = newUsername;
    password = newPassword;
}

void User::setName(string newName)
{
    name = newName;
}

void User::setUsername(string newUsername)
{
    username = newUsername;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

string User::getName() const
{
    return name;
}

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

bool User::login(string enteredUsername, string enteredPassword) const
{
    return (enteredUsername == username && enteredPassword == password);
}

bool User::purchaseTickets(Event& event, int amountToBuy)
{
    if (amountToBuy > event.getAmountOfAvailableTickets())
    {
        cout << "Ticket purchase amount greater than available tickets!\n";
        return false;
    }

    event.setAmountOfAvailableTickets(event.getAmountOfAvailableTickets() - amountToBuy);
    cout << "Purchase successful!\n";
    return true;
}