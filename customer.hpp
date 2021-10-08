#ifndef CUSTOMERS_HPP
#define CUTOMERS_HPP





//Node Customer. Is to be stored in both FIFO and Priority Queues.

class Customer{
    private:
        float arrivalTime;
        float startOfServiceTime;
        float departureTime;
    public:
        Customer(float arrivalTime);
        void setDepartureTime(float departureTime);
        Customer(){};
        void setStartOfService(float s);
        float getArrivalTime();
        float getStartServiceTime();
        float getDepartureTime();
};









#endif