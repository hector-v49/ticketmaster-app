//  main.cpp
//  User
//  Created by Sandra Robles on 12/1/25.


#include <iostream>
#include <string>
#include "User.h"
#include "Ticket.h"

using namespace std;

int main()
{
    string name, username, password;

    cout << "========== TicketMaster ==========\n\n";
    cout << "---- Create Account ----" << endl;

    cout << "Please Enter Your Name: ";
    getline(cin, name);

    cout << "Choose a Username: ";
    getline(cin, username);

    cout << "Choose a Password: ";
    getline(cin, password);

    User user(name, username, password);
    cout << endl;

    cout << "---- Login Step ----" << endl;

    string enteredUsername, enteredPassword;

    cout << "Username: ";
    getline(cin, enteredUsername);

    cout << "Password: ";
    getline(cin, enteredPassword);

    if (user.login(enteredUsername, enteredPassword))
    {
        cout << "Login successful! Welcome, " << user.getName() << "!" << endl;

    
        Ticket vip("VIP Concert", 250.00, 1, 1);
        Ticket floor("Floor Concert", 150.00, 2, 3);

        user.addToHistory(vip);
        user.addToHistory(floor);

        cout << endl;
        user.printHistory();
    }
    else
    {
        cout << "Login failed. Incorrect username or password." << endl;
    }

    return 0;
}

