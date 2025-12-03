// By Hector Verduzco Rayo, [insert name], [insert name]...
// Code DUE: December 5, 2025
// Final Group Project
#include <iostream>
#include "Ticket.h"
using namespace std;

int main()
{
  Ticket VIP("VIP Section", 250, 1, 1);
  Ticket Floor("Floor Section", 150, 32, 1);
  Ticket Balcony("Balcony Section", 80, 75, 1);
  
  int ticketChoice = 0;
  double amount = 0;

  cout << "Select Ticket type:   (1-3)\n";
  cout << "1. VIP\n" << "2. Floor\n" << "3. Balcony\n";
  cin >> ticketChoice;
  cout << endl << endl;

  if(ticketChoice == 1)
  {
    cout << "How many VIP ticekts do you want to buy? ";
    cin >> amount;
    if(VIP.ticketPurchase(amount))
    {
      cout << "Purchase successful." << endl;
      cout << VIP << endl;
    }
    else
    {
      cout << "Not enough tickets available." << endl;
    }
  }

  else if(ticketChoice == 2)
  {
    cout << "How many Floor ticekts do you want to buy? ";
    cin >> amount;
    if(Floor.ticketPurchase(amount))
    {
      cout << "Purchase successful." << endl;
      cout << Floor << endl;
    }
    else
    {
      cout << "Not enough tickets available." << endl;
    }
  }

   else if(ticketChoice == 3)
    {
      cout << "How many Balcony ticekts do you want to buy? ";
      cin >> amount;
      if(Balcony.ticketPurchase(amount))
      {
        cout << "Purchase successful." << endl;
        cout << Balcony << endl;
      }
      else
      {
        cout << "Not enough tickets available." << endl;
      }
    }
  else
 {
  cout << "Invalid Input" << endl;
 }
  return 0;
}