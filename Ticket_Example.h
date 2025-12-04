//
// Created by Shalltell Flores on 12/2/25.
//

#ifndef SCHOOL_PROJECTS_TICKET_EXAMPLE_H
#define SCHOOL_PROJECTS_TICKET_EXAMPLE_H
#include <string>

using namespace std;

class Ticket_Example {
public:
    Ticket_Example();
    Ticket_Example(double price, string eventName);

    double getPrice() const;

    // event name sgown on Ticket_Example
    string getEventName() const;

private:
    double price;
    string eventName;
};



#endif //SCHOOL_PROJECTS_TICKET_EXAMPLE_H