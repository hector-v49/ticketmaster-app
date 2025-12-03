#include "admin.h"


Admin::Admin() : User() {}

Admin::Admin(string newName, string newUsername, string newPassword) : User(newName, newUsername, newPassword) {}

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