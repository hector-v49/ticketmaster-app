//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_ADMIN_EXAMPLE_H
#define SCHOOL_PROJECTS_ADMIN_EXAMPLE_H

#include <string>
#include <vector>
#include "Event_Example.h"


class Admin {
public:
    Admin();
    Admin(string name);

    // Should allow admin to add new events
    void addEvent(vector<Event>& events, const Event& e);

    // Should allow admin to remove an event by maybe the index
    void deleteEvent(vector<Event>& events, int index);

    // Should allow admin to modify event details
    // like name, date, venue, qty, price
    void editEvent(Event& e);

    // Should display all events with inventory counts
    // for example 
    // Superbowl | Qty Left: 40 | Price: $45
    void viewInventory(const vector<Event>& events) const;

    // Should show total sales from all events
    // Total Sales: $345.00
    void printTotalSales() const;

private:
    string name;
};


#endif //SCHOOL_PROJECTS_ADMIN_EXAMPLE_H