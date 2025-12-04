//  User.h
//  User//
//  Created by Sandra Robles
#ifndef User_h
#define User_h

#include <iostream>
#include <string>
#include "Event.h"
using namespace std;

class User
{
// Admins won't buy tickets
private:
    bool purchaseTickets(Event& event, int amountToBuy);

protected:
    string name;
    string username;
    string password;
   
public:
    User();
    User(string newName, string newUsername, string newPassword);
    
    void setName(string newName);
    void setUsername(string newUsername);
    void setPassword(string newPassword);
    
    string getName() const;
    string getUsername() const;
    string getPassword() const;
    
    bool login(string enteredUsername, string enteredPassword) const;
    
    
};
#endif /* User_h */
