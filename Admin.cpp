#include "Admin.h"

Admin::Admin() : name("n/a") {}

Admin::Admin(string name_) {
    this->name = name_;
}

void Admin::addEvent(vector<Event>& events, const Event& event) {
    // Should push event into event list, see Event_Example.h/.cpp for the expected order
    events.push_back(event);
}

void Admin::deleteEvent(vector<Event>& events, int index) {
    // Should remove event from vector array

    // Check if the index is valid
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void Admin::editEvent(Event& event) {
    // Should allow editing fields
    char input;

    // Temp variables for member variable updating
    string _s;
    int _i;
    double _d;
    
    do
    {
        cout << "===== EVENT EDIT MENU =====:\n";
        cout << "1. Name\n2. Date\n3. Venue\n4. Ticket Quantity\n5. Ticket Price\n6. Exit edit menu\nSelect: ";
        cin >> input;

        switch (input)
        {
        case '1':
            cout << "Input new Event name: ";
            cin >> _s;
            event.setName(_s);
            break;
        case '2':
            cout << "Input new Event date (format: YYYY-MM-DD): ";
            cin >> _s;
            event.setDate(_s);
            break;
        case '3':
            cout << "Input new venue location: ";
            cin >> _s;
            event.setVenue(_s);
            break;
        case '4':
            cout << "Input new ticket quantity: ";
            cin >> _i;
            event.setAmountOfAvailableTickets(_i);
            break;
        case '5':
            cout << "Input new ticket price: ";
            cin >> _d;
            event.setTicketPrice(_d);
            break;
        case '6':
            break;
        default:
            cout << "Invalid input.\n";
            break;
        }
    } while (input != '6');
}

void Admin::viewInventory(const vector<Event>& events) const {
    // cout << "<<< viewInventory not available yet... - please add it >>>" << endl;
    
    cout << "--- Current inventory ---\n";
    for (int i = 0; i < events.size(); i++)
    {
        cout << "Event #" << i + 1 << ": "
             << events.at(i).getName() << " | Qty Left: "
             << events.at(i).getAmountOfAvailableTickets() << " | Price: $"
             << events.at(i).getTicketPrice() << endl;
    }
}

void Admin::printTotalSales(const vector<Event>& events) const {
    // cout << "<<< printTotalSales not available yet... - please add it >>>" << endl;
    double total = 0;

    for (int i = 0; i < events.size(); i++)
    {
        total += (events.at(i).getMaxCapacity() - events.at(i).getAmountOfAvailableTickets()) * events.at(i).getTicketPrice();
    }

    cout << "Total Sales for " << events.size() << " event(s): $" << total << endl;

}