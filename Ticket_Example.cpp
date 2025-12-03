//
// Created by Shalltell Flores on 12/2/25.
//

#include "Ticket_Example.h"
using namespace std;

Ticket_Example::Ticket_Example() {
    price = 0.0;
}


Ticket_Example::Ticket_Example(double p, string name) {
    price = p;
    eventName = name;
}

double Ticket_Example::getPrice() const {
    return price;
}

string Ticket_Example::getEventName() const {
    return eventName;
}