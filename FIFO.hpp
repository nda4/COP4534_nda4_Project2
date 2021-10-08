#ifndef FIFO_HPP
#define FIFO_HPP


#include "customer.hpp"
#include <vector>



class FIFO{
    private:
        int hadToWait;
    public:
    
        std::vector <Customer> customers;
        void addCustomer(Customer customer);
        Customer removeCustomer();
        FIFO();    
};














#endif