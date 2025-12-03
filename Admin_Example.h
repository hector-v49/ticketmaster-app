//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_ADMIN_EXAMPLE_H
#define SCHOOL_PROJECTS_ADMIN_EXAMPLE_H

#include <string>
#include <vector>
#include "Event_Example.h"


class Admin_Example {
public:
    Admin_Example();
    Admin_Example(string name);

    // Should allow Admin_Example to add new events
    void addEvent(vector<Event_Example>& events, const Event_Example& e);

    // Should allow Admin_Example to remove an Event_Example by maybe the index
    void deleteEvent(vector<Event_Example>& events, int index);

    // Should allow Admin_Example to modify Event_Example details
    // like name, date, venue, qty, price
    void editEvent(Event_Example& e);

    // Should display all events with inventory counts
    // for example 
    // Superbowl | Qty Left: 40 | Price: $45
    void viewInventory(const vector<Event_Example>& events) const;

    // Should show total sales from all events
    // Total Sales: $345.00
    void printTotalSales() const;

private:
    string name;
};


#endif //SCHOOL_PROJECTS_ADMIN_EXAMPLE_H