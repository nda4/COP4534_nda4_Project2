#include "customer.hpp"



Customer::Customer(float arrivalTime){
    this->arrivalTime = arrivalTime;
}

void Customer::setStartOfService(float s){
    this->startOfServiceTime = s;
}

void Customer::setDepartureTime(float departureTime){
    this->departureTime = departureTime;
}

float Customer::getArrivalTime(){
    return this->arrivalTime;
}
float Customer::getDepartureTime(){
    return this->departureTime;
}
float Customer::getStartServiceTime(){
    return this->startOfServiceTime;
}
