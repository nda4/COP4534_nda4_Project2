#include "FIFO.hpp"




void FIFO::addCustomer(Customer customer){
    hadToWait++;
    customers.insert(customers.begin(), customer);
};

Customer FIFO::removeCustomer(){
    Customer newCustomer = customers.back();
    customers.pop_back();
    return newCustomer;
};

FIFO::FIFO(){
    hadToWait = 0;
};