//
// Created by Shalltell Flores on 12/2/25.
//

#include "Admin_Example.h"
#include <iostream>

Admin_Example::Admin_Example() {
    
}
Admin_Example::Admin_Example(string name_) {
    this->name = name_;
}

void Admin_Example::addEvent(vector<Event_Example>& events, const Event_Example& Event_Example) {
    // Should push Event_Example into Event_Example list, see Event_Example.h/.cpp for the expected order
}

void Admin_Example::deleteEvent(vector<Event_Example>& events, int index) {
    // Should remove Event_Example from vector array
}

void Admin_Example::editEvent(Event_Example& Event_Example) {
    // Should allow editing fields
    cout << "<<< editEvent not available yet... - please add it >>>" << endl;
}

void Admin_Example::viewInventory(const vector<Event_Example>& events) const {
    cout << "<<< viewInventory not available yet... - please add it >>>" << endl;
}

void Admin_Example::printTotalSales() const {
    cout << "<<< printTotalSales not available yet... - please add it >>>" << endl;
}