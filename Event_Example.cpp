//
// Created by Shalltell Flores on 12/2/25.
//

#include "Event_Example.h"
using namespace std;

Event_Example::Event_Example() {
    price = 0.0;
    availableTickets = 0;
    maxCapacity = 0;
    //this should have the rest of the empty strings
}

Event_Example::Event_Example(string name, string date, string venue, int qty, double price, int capacity) {
    this->name = name;
    this->date = date;
    this->venue = venue;
    this->availableTickets = qty;
    this->maxCapacity = capacity;
    this->price = price;
}

int Event_Example::getMaxCapacity() const
{
    return maxCapacity;
}


string Event_Example::getName() const { return name; }
string Event_Example::getDate() const { return date; }
string Event_Example::getVenue() const { return venue; }
double Event_Example::getTicketPrice() const { return price; }

void Event_Example::decreaseAvailableTickets(int n) {
    // this should subtract tickets
}

istream& operator>>(istream& input, Event_Example& Event_Example){
    // main.cpp will push events into this, the format is in events.txt in this order
    // Event_Example name, date, location, quantity and price and maxCapacity
    // Superbowl 2025-06-22 Arena 50 40.00 100
    return input;
}

int Event_Example::getAmountOfAvailableTickets() const
{
    return availableTickets;
}