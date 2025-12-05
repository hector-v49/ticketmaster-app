//
// Created by Shalltell Flores on 11/10/25.
// Group Members: Shalltell Flores, Sandra Robles, Stefan Wilson, David Delgado, and Hector Verduzco Rayo
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "User.h"
#include "Admin.h"
#include "Event.h"
#include "Ticket.h"

using namespace std;

void clearInput(){
    string mystring;
    getline(cin, mystring);
}

void printEvents(const vector<Event>& events) {
    if (events.size() > 0 ) {
        cout << endl << "##### Available Events #####" << endl;
        for (size_t i = 0; i < events.size(); i++){
            cout << i+1 << ". " << events[i].getName()
                 << " | Date: " << events[i].getDate()
                 << " | Venue: " << events[i].getVenue()
                 << " | Tickets Left: " << events[i].getAmountOfAvailableTickets()
                 << " | Price: $" << events[i].getTicketPrice()
                 << endl;
        }
        cout << "----------------------------" << endl << endl;
    } else {
        cout << endl << "No events available." << endl;
    }

}

void userMenu(User& user, vector<Event>& events)
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
                    cout << "That's more tickets than we have. Please try again." << endl;
                    break;
                }

                Event& ev = events[event_number - 1];

                if (ev.getAmountOfAvailableTickets() <= 0) {
                    cout << "No tickets left." << endl;
                    break;
                }

                cout << "How many tickets? ";
                int qty;
                cin >> qty;

                if (!cin || qty < 1 || qty > ev.getAmountOfAvailableTickets()) {
                    clearInput();
                    cout << "Invalid." << endl;
                    break;
                }

                for (int i = 0; i < qty; i++) {
                    Ticket t(ev.getName(), ev.getTicketPrice(), "FLOOR", qty);
                    user.addTicket(t);
                    ev.purchaseTickets(1);
                }

                cout << "Purchase successful." << endl;
                break;
            }

            case 3:
                user.printHistory();
                break;

            case 4:
                cout << "Logging out..." << endl;
                break;

            default:
                cout << "Invalid." << endl;
        }

    } while (choice != 4);
}

void adminMenu(Admin& admin, vector<Event>& events) {
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



                Event e("1", name, date, venue, qty, capacity, price);
                // Event(const string& id, const string& name, const string& date, const string& venue, int capacity, double price);
                admin.addEvent(events, e);

                cout << "Event added." << endl;
                break;
            }

            case 3: {
                printEvents(events);
                if (events.size() == 0) {
                    continue;
                }
                cout << "Event number: ";
                int n;
                cin >> n;

                if (!cin || n < 1 || n > (int)events.size()){
                    clearInput();
                    cout << "Invalid choice. Try again." << endl;
                    break;
                }

                admin.deleteEvent(events, n - 1);
                cout << "Event Deleted!" << endl;
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
                    cout << "Invalid choice, try again." << endl;
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

int findUser(const string& username, const vector<User>& users) {
    for (int i = 0; i < users.size(); i++){
        if (users[i].getUsername() == username){
            return i;
        }
    }
    return -1;

}


int main(){
    vector<Event> events;
    vector<User> users;

    // load initial events from file, use fallback events if running from diff directory
    static const vector<string> FALLBACK_EVENTS = {
        "1 WinterGames 2025-08-22 IceCenter 600 600 100.00",
        "2 DevConGlobal 2025-07-10 TechArena 300 300 100.00",
        "3 SXSW 2025-09-12 Arena 50 50 100.00",
        "4 TechSummit 2025-11-05 ExpoHall 120 120 100.00",
        "5 FoodFest 2025-06-18 DowntownPlaza 500 500 100.00"
    };

    ifstream file(string(__FILE__).substr(0, string(__FILE__).find_last_of("/\\")) + "/events.txt");
    stringstream fallback;

    istream* in;

    if (file) {
        in = &file;
    } else {
        for (size_t i = 0; i < FALLBACK_EVENTS.size(); ++i)
            fallback << FALLBACK_EVENTS[i] << '\n';

        in = &fallback;
    }

    Event temp;
    while (*in >> temp)
        events.push_back(temp);


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

            cout << endl << "Enter your name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Choose a username: ";
            getline(cin, username);

            if (findUser(username, users) != -1) {
                cout << "Username already exists." << endl;
                continue;
            }

            cout << "Choose a password: ";
            getline(cin, password);
        
            users.push_back(User(name, username, password));
            cout << endl << "Signup complete. Please login." << endl;
            continue;
        }

        if (choice == 1) {
            string username;
            string password;
            
            cin.ignore();
            cout << endl << "Username: ";
            getline(cin, username);

            cout << "Password: ";
            getline(cin, password);

            if (username == "admin") {
                Admin admin("admin");
                adminMenu(admin, events);
                continue;
            }

            int user = findUser(username, users);
            if (user == -1) {
                cout << endl << "User not found. Please sign up instead!" << endl;
                continue;
            } else {
                if (users[user].login(username, password))
                {
                    cout << endl << "Login successful." << endl;
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
