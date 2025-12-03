#include "Event.h"
using namespace std;

Event::Event()
{
    eventID = "None";
    eventName = "Unknown Event name";
    eventDate = "00/00/0000";
    venue = "TBD";
    availableTickets = 0;
    maxCapacity = 0;
    ticketPrice = 0.0;

}

Event::Event(const string& id, const string& name, const string& date, const string& venue, int capacity, double price)
{
    eventID = id;
    eventName = name;
    eventDate = date;
    this->venue = venue;
    maxCapacity = capacity;
    availableTickets = capacity;
    ticketPrice = price;
}

string Event::getID() const
{
    return eventID;
}

string Event::getName()const
{
    return eventName;
}

string Event::getDate()const
{
    return eventDate;
}

string Event::getVenue()const
{
    return venue;
}

int Event::getAvailableTickets() const
{
    return availableTickets;
}

int Event::getMaxCapacity() const
{
    return maxCapacity;
}

double Event::getTicketPrice()const
{
    return ticketPrice;
}

void Event::setName(const string& name)
{
    eventName = name;
}

void Event::setDate(const string& date)
{
    eventDate = date;
}

void Event::setVenue(const string& venue_)
{
    venue = venue_;
}

void Event::setTicketPrice(double price)
{
    if (price>= 0)
        ticketPrice = price;
}

    // Function behavior
bool Event::purchaseTickets(int quantity)
{
    if(quantity <= 0) return false;

    if(quantity > availableTickets)
        return false;

    availableTickets -= quantity;
    return true;
}

bool Event::addTickets(int quantity)
{
    if(quantity <= 0) return false;

    if(availableTickets + quantity > maxCapacity)
        return false;
    availableTickets += quantity;
    return true;
}

//  Display's info
void Event::printEventSummary()const
{
    cout << "==============================\n";
    cout << " Event ID: " << eventID << "\n";
    cout << " Name: " << eventName << "\n";
    cout << " Date: " << eventDate << "\n";
    cout << " Venue: " << venue << "\n";
    cout << " Capacity: " << maxCapacity << "\n";
    cout << " Tickets Available: " << availableTickets << "\n";
    cout << " Ticket Price: $" << ticketPrice << "\n";
    cout << "==============================\n";
}
