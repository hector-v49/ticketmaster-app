//
// Created by Shalltell Flores on 11/10/25.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "User_Example.h"
#include "Admin_Example.h"
#include "Event_Example.h"
#include "Ticket_Example.h"

using namespace std;

void clearInput(){
    string mystring;
    getline(cin, mystring);
}

void printEvents(const vector<Event_Example>& events) {
    cout << endl << "##### Available Events #####" << endl;
    for (size_t i = 0; i < events.size(); i++){
        cout << i+1 << ". " << events[i].getName()
             << " | Date: " << events[i].getDate()
             << " | Venue: " << events[i].getVenue()
             << " | Tickets Left: " << events[i].getAvailableTickets()
             << " | Price: $" << events[i].getTicketPrice()
             << endl;
    }
    cout << "----------------------------" << endl << endl;
}

void userMenu(User_Example& user, vector<Event_Example>& events)
{
    int choice;

    do {
        cout << endl << "===== USER MENU =====" << endl;
        cout << "1. View Events" << endl;
        cout << "2. Purchase Ticket" << endl;
        cout << "3. View Purchased Tickets" << endl;
        cout << "4. Logout" << endl;
        cout << "Select: ";
        cin >> choice;

        if (!cin) { clearInput(); continue; }


        switch (choice) {
            case 1:
                printEvents(events);
                break;

            case 2:
            {
                printEvents(events);
                cout << "Enter event number: ";
                int event_number;
                cin >> event_number;

                if (!cin || event_number < 1 || event_number > (int)events.size())
                {
                    clearInput();
                    cout << "Invalid." << endl;
                    break;
                }

                Event_Example& ev = events[event_number - 1];

                if (ev.getAvailableTickets() <= 0) {
                    cout << "No tickets left." << endl;
                    break;
                }

                cout << "How many tickets? ";
                int qty;
                cin >> qty;

                if (!cin || qty < 1 || qty > ev.getAvailableTickets()) {
                    clearInput();
                    cout << "Invalid." << endl;
                    break;
                }

                for (int i = 0; i < qty; i++) {
                    Ticket_Example t(ev.getTicketPrice(), ev.getName());
                    user.addTicket(t);
                    ev.decreaseAvailableTickets(1);
                }

                cout << "Purchase successful." << endl;
                break;
            }

            case 3:
                user.printTickets();
                break;

            case 4:
                cout << "Logging out..." << endl;
                break;

            default:
                cout << "Invalid." << endl;
        }

    } while (choice != 4);
}

void adminMenu(Admin_Example& admin, vector<Event_Example>& events) {
    int choice;

    do {
        cout << endl << "===== ADMIN MENU =====" << endl;
        cout << "1. View Events" << endl;
        cout << "2. Add Event" << endl;
        cout << "3. Delete Event" << endl;
        cout << "4. Edit Event" << endl;
        cout << "5. View Inventory" << endl;
        cout << "6. View Total Sales" << endl;
        cout << "7. Logout" << endl;
        cout << "Select: ";
        cin >> choice;

        if (!cin) { clearInput(); continue; }

        switch (choice) {
            case 1:
                printEvents(events);
                break;

            case 2:
            {
                string name, date, venue;
                int qty, capacity;
                double price;

                clearInput();
                cout << "Name: ";
                getline(cin, name);
                cout << "Date: ";
                getline(cin, date);
                cout << "Venue: ";
                getline(cin, venue);

                cout << "Ticket Quantity: ";
                cin >> qty;
                cout << "Price: ";
                cin >> price;

                cout << "Max Capacity: ";
                cin >> capacity;



                Event_Example e(name, date, venue, qty, price, capacity);
                admin.addEvent(events, e);

                cout << "Event added." << endl;
                break;
            }

            case 3: {
                printEvents(events);
                cout << "Event number: ";
                int n;
                cin >> n;

                if (!cin || n < 1 || n > (int)events.size())
                {
                    clearInput();
                    cout << "Invalid." << endl;
                    break;
                }

                admin.deleteEvent(events, n - 1);
                cout << "Deleted." << endl;
                break;
            }

            case 4: {
                printEvents(events);
                cout << "Event number: ";
                int n;
                cin >> n;

                if (!cin || n < 1 || n > (int)events.size())
                {
                    clearInput();
                    cout << "Invalid." << endl;
                    break;
                }

                admin.editEvent(events[n - 1]);
                break;
            }

            case 5:
                admin.viewInventory(events);
                break;

            case 6:
                admin.printTotalSales(events);
                break;

            case 7:
                cout << "You're logged out!" << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 7);
}

int findUser(const string& username, const vector<User_Example>& users) {
    for (int i = 0; i < users.size(); i++){
        if (users[i].getUsername() == username){
            return i;
        }
    }
    return -1;

}


int main(){
    vector<Event_Example> events;
    vector<User_Example> users;

    // load initial events from file
    ifstream file("./events.txt");

    Event_Example temp;
    while (file >> temp)
        events.push_back(temp);

    file.close();


    cout << "********************************************" << endl;
    cout << "**********   EVENT SALES SYSTEM   **********" << endl;
    cout << "********************************************" << endl;
    cout << "Get tickets to your next event! Sign up or " << endl << "sign in to your existing account. " << endl;
    cout << "Admins: Sign in as 'admin' and any password." << endl;

    while (true)
    {
        int choice;
        cout << endl << "1. Login" << endl << "2. Sign Up" << endl << "3. Exit" << endl << "Select: ";
        cin >> choice;

        if (!cin) { clearInput(); continue; }

        if (choice == 3) {
            cout << "Thanks for visiting, goodbye!" << endl;
            break;
        }

        if (choice == 2) {
            string name;
            string username;
            string password;

            cout << "Enter your name: ";
            cin >> name;

            cout << "Choose a username: ";
            cin >> username;

            if (findUser(username, users) != -1) {
                cout << "Username already exists." << endl;
                continue;
            }

            cout << "Choose a password: ";
            cin >> password;

            users.push_back(User_Example(name, username, password));
            cout << "Signup complete. You can login now." << endl;
            continue;
        }

        if (choice == 1) {
            string username;
            string password;

            cout << "Username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            if (username == "admin") {
                Admin_Example admin("admin");
                adminMenu(admin, events);
                continue;
            }

            int user = findUser(username, users);
            if (user == -1) {
                cout << "User not found. Please sign up instead!" << endl;
                continue;
            } else {
                if (users[user].login(username, password))
                {
                    cout << "Login successful." << endl;
                    userMenu(users[user], events);
                }
                else
                {
                    cout << "Wrong password." << endl;
                }
            }

        }
    }

    return 0;
}