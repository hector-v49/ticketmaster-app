//  User.h
//  User//
//  Created by Sandra Robles


#ifndef User_h
#define User_h


#include <string>
using namespace std;

class User
{
private:
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
