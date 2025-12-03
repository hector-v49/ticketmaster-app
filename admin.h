// Hector's class
#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "event.h"

class Admin : public User
{
public:
    Admin();

    Event& createNewEvent(Event& event);
    void checkSalesForEvent(Event& event);
    void addTicketsForEvent(Event& event, int amountToAdd);
};

#endif