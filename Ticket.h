#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <string>

using namespace std;

class Ticket
{
  private:
    string ticketInfo;
    double price;
    string seatNumber;
    int ticketQuantity;
    double purchaseTotal;

  public:
    Ticket();
    Ticket(string info, double price, string seatNum, int quantity);
    string getTicketInfo() const;
    double getPrice() const;
    string getSeatNumber() const;
    int getTicketQuantity() const;
    double getpurchaseTotal() const;
    void setTicketInfo(string info);
    void setPrice(double price);
    void setSeatNumber(int seatNum);
    void setTicketQuantity(int quantity);
    bool ticketPurchase(double amount);
};

ostream& operator << (ostream& out, const Ticket& t);

#endif // TICKET_H