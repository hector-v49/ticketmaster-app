#include "Ticket.h"
using namespace std;

Ticket::Ticket()
{
  ticketInfo = "";
  price = 0.0;
  seatNumber = "";
  ticketQuantity = 0;
  purchaseTotal = 0;
}

Ticket::Ticket(string info, double price, string seatNum, int quantity)
{
  ticketInfo = info;
  this->price = price;
  seatNumber = seatNum;
  ticketQuantity = quantity;
  purchaseTotal = 0;
}

string Ticket::getTicketInfo() const
{
  return ticketInfo;
}

double Ticket::getPrice() const
{
  return price;
}

string Ticket::getSeatNumber() const
{
  return seatNumber;
}

int Ticket::getTicketQuantity() const
{
  return ticketQuantity;
}

double Ticket::getpurchaseTotal() const
{
  return purchaseTotal;
}

void Ticket::setTicketInfo(string info)
{
  ticketInfo = info;
}

void Ticket::setPrice(double price) 
{
  this->price = price;
}

void Ticket::setSeatNumber(int seatNum)
{
  seatNumber = seatNum;
}

void Ticket::setTicketQuantity(int quantity)
{
  ticketQuantity = quantity;
}

bool Ticket::ticketPurchase(double amount)
{
  if(amount <= 0)
  {
    return false;
  }
  if(amount > ticketQuantity)
  {
    return false;
  }
  else
  {
    ticketQuantity = ticketQuantity - amount;
    purchaseTotal = amount * price;
    return true;
  }
}

ostream& operator << (ostream& out, const Ticket& t) // WILL HAVE TO EDIT LATER
{
  out << t.getTicketInfo() << endl;
  out << t.getPrice() << endl;
  out << t.getSeatNumber() << endl;
  out << t.getTicketQuantity() << endl;
  return out;
}
