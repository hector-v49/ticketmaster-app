//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_EVENT_EXAMPLE_H
#define SCHOOL_PROJECTS_EVENT_EXAMPLE_H


#include <string>
#include <iostream>
using namespace std;

class Event_Example {
public:
    Event_Example();
    Event_Example(string name, string date, string venue, int qty, double price);

    string getName() const;
    string getDate() const;
    string getVenue() const;
    int getAvailableTickets() const;
    double getTicketPrice() const;

    // for inventory stuff, should work with tickets class...?
    void decreaseAvailableTickets(int n);

    // main.cpp will push events into this, the format is in events.txt in this order
    // Event_Example name, date, location, quantity and price
    // Superbowl 2025-06-22 Arena 50 40.00
    friend istream& operator>>(istream& input, Event_Example& Event_Example);

private:
    string name;
    string date;
    string venue;
    int availableTickets;
    double price;
};


#endif //SCHOOL_PROJECTS_EVENT_EXAMPLE_H