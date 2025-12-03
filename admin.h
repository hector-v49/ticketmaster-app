// Hector's class
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "event.h"

class Admin
{
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
    void printTotalSales(const vector<Event>& events) const;
private:
    string name;
};

#endif