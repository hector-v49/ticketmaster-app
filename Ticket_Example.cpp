//
// Created by Shalltell Flores on 12/2/25.
//

#include "Ticket_Example.h"
using namespace std;

Ticket::Ticket() {
    price = 0.0;
}


Ticket::Ticket(double p, string name) {
    price = p;
    eventName = name;
}

double Ticket::getPrice() const {
    return price;
}

string Ticket::getEventName() const {
    return eventName;
}