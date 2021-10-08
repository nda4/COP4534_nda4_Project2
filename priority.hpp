#ifndef PRIORITY_HPP
#define PRIORITY_HPP

#include "FIFO.hpp"
#include <string>

struct Node{
    float eventTime;
    char type;
    Customer customer;
    Node(float eventTime, Customer customer, char type){
        this->eventTime = eventTime;
        this->customer = customer;
        this->type = type;
    }
    Node* nextNode = nullptr;
};  

class Priority{
    private:
        char type;
        
    public:
        std::vector <Node*> events;
        void addArrival(Customer newCustomer);
        Priority(){};
        void addDeparture(Customer newCustomer);
        int getSize();
        Node* removeFrontNode();
};
#endif