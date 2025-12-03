//
// Created by Shalltell Flores on 12/2/25.
//

#include "Event_Example.h"
using namespace std;

Event::Event() {
    price = 0.0;
    availableTickets = 0;
    //this should have the rest of the empty strings
}

Event::Event(string name, string date, string venue, int qty, double price) {
    this->name = name;
    this->date = date;
    this->venue = venue;
    this->availableTickets = qty;
    this->price = price;
}


string Event::getName() const { return name; }
string Event::getDate() const { return date; }
string Event::getVenue() const { return venue; }
int Event::getAvailableTickets() const { return availableTickets; }
double Event::getTicketPrice() const { return price; }

void Event::decreaseAvailableTickets(int n) {
    // this should subtract tickets
}

istream& operator>>(istream& input, Event& event){
    // main.cpp will push events into this, the format is in events.txt in this order
    // event name, date, location, quantity and price
    // Superbowl 2025-06-22 Arena 50 40.00
    return input;
}