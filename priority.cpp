#include "priority.hpp"
#include <iostream>

int Priority::getSize(){
    return this->events.size();
}


void Priority::addArrival(Customer customer){
    Node* newArrival = new Node(customer.getArrivalTime(), customer, 'a');
    if(events.size() == 0)
        events.push_back(newArrival);
    for(int i = 0; i < events.size(); i++){
        if(newArrival->eventTime < events.at(i)->eventTime){
            events.insert(events.begin() + i, newArrival);
            break;
        }
        else{
            events.push_back(newArrival);
            break;
    }
    }
}

void Priority::addDeparture(Customer customer){
    Node* newDeparture = new Node(customer.getDepartureTime(), customer, 'd');
    if(events.size() == 0)
        events.push_back(newDeparture);
    for(int i = 0; i < events.size(); i++){
        if(newDeparture->eventTime < events.at(i)->eventTime){
            events.insert(events.begin() + i, newDeparture);
            break;
        }
        else{
            events.push_back(newDeparture);
            break;
    }
    }
}

Node* Priority::removeFrontNode(){
    Node* temp;
    temp = this->events.at(0);
    this->events.erase(this->events.begin());
    return temp;
}
