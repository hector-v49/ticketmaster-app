#include "Ticket.h"
using namespace std;

Ticket::Ticket()
{
  ticketInfo = "";
  price = 0.0;
  seatNumber = 0;
  ticketQuantity = 0;
}

Ticket::Ticket(string info, double price, int seatNum, int quantity)
{
  ticketInfo = info;
  this->price = price;
  seatNumber = seatNum;
  ticketQuantity = quantity;
}

string Ticket::getTicketInfo() const
{
  return ticketInfo;
}

double Ticket::getPrice() const
{
  return price;
}

int Ticket::getSeatNumber() const
{
  return seatNumber;
}

int Ticket::getTicketQuantity() const
{
  return ticketQuantity;
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