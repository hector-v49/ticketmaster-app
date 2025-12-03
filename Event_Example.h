//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_EVENT_EXAMPLE_H
#define SCHOOL_PROJECTS_EVENT_EXAMPLE_H


#include <string>
#include <iostream>
using namespace std;

class Event {
public:
    Event();
    Event(string name, string date, string venue, int qty, double price);

    string getName() const;
    string getDate() const;
    string getVenue() const;
    int getAvailableTickets() const;
    double getTicketPrice() const;

    // for inventory stuff, should work with tickets class...?
    void decreaseAvailableTickets(int n);

    // main.cpp will push events into this, the format is in events.txt in this order
    // event name, date, location, quantity and price
    // Superbowl 2025-06-22 Arena 50 40.00
    friend istream& operator>>(istream& input, Event& event);

private:
    string name;
    string date;
    string venue;
    int availableTickets;
    double price;
};


#endif //SCHOOL_PROJECTS_EVENT_EXAMPLE_H