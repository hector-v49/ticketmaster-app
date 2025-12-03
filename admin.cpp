#include "admin.h"


Admin::Admin() : User() {}

void Admin::addTicketsForEvent(Event& event, int amountToAdd)
{
    if (event.getAmountOfAvailableTickets() + amountToAdd > event.getMaxCapacity())
    {
        event.setAmountOfAvailableTickets(event.getMaxCapacity());
    }
    else
    {
        event.setAmountOfAvailableTickets(event.getAmountOfAvailableTickets() + amountToAdd);
    }
}