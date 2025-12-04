//  User.h
//  User//
//  Created by Sandra Robles


#ifndef User_h
#define User_h


#include <string>
#include <vector>
#include "Ticket.h"
using namespace std;

class User
{
private:
    string name;
    string username;
    string password;
    
    vector<Ticket> purchaseHistory;
    
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
    
    void addTicket(const Ticket& newTicket);
    void printHistory() const;
    
};
#endif /* User_h */
