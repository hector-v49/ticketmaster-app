//  User.cpp
//  User
//  Created by Sandra Robles

#include "User.h"
#include <iostream>
using namespace std;

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

