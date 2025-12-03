//
// Created by Shalltell Flores on 12/2/25.
//

#include "Admin_Example.h"
#include <iostream>

Admin::Admin() {
    
}
Admin::Admin(string name_) {
    this->name = name_;
}

void Admin::addEvent(vector<Event>& events, const Event& event) {
    // Should push event into event list, see Event_Example.h/.cpp for the expected order
}

void Admin::deleteEvent(vector<Event>& events, int index) {
    // Should remove event from vector array
}

void Admin::editEvent(Event& event) {
    // Should allow editing fields
    cout << "<<< editEvent not available yet... - please add it >>>" << endl;
}

void Admin::viewInventory(const vector<Event>& events) const {
    cout << "<<< viewInventory not available yet... - please add it >>>" << endl;
}

void Admin::printTotalSales() const {
    cout << "<<< printTotalSales not available yet... - please add it >>>" << endl;
}