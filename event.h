// Stefan's class

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <iostream>

using namespace std;

class Event
{
private:
    string eventID;     // ID for event
    string eventName;   // Event title/name
    string eventDate;   // Date as string (month/day/year)
    string venue;       // Location
    int availableTickets; // Tickets remaining
    int maxCapacity;    // Total seats available
    double ticketPrice; // Price per ticket

public:
    Event();    // Default constructor
    Event(const string& id, const string& name, const string& date, const string& venue, int capacity, double price);

    // Getters
    string getID()const;
    string getName()const;
    string getDate()const;
    string getVenue()const;

    int getAvailableTickets()const;
    int getMaxCapacity()const;
    double getTicketPrice()const;

    // Setters
    void setName(const string& name);
    void setDate(const string& date);
    void setVenue(const string& venue_);
    void setTicketPrice(double price);


    // Function behavior
    bool purchaseTickets(int quantity);
    bool addTickets(int quantity);

    // Display info
    void printEventSummary()const;

};

#endif // EVENT_H
