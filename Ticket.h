#include <iostream>
#include <string>
using namespace std;

class Ticket
{
  private:
    string ticketInfo;
    double price;
    int seatNumber;
    int ticketQuantity;

  public:
    Ticket();
    Ticket(string info, double price, int seatNum, int quantity);
    string getTicketInfo() const;
    double getPrice() const;
    int getSeatNumber() const;
    int getTicketQuantity() const;
    void setTicketInfo(string info);
    void setPrice(double price);
    void setSeatNumber(int seatNum);
    void setTicketQuantity(int quantity);
    bool ticketPurchase(double amount);
};

ostream& operator << (ostream& out, const Ticket& t);