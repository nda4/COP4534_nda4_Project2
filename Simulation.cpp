#include "priority.hpp"
#include <iostream>
#include <fstream>
#include <random>


float GetNextRandomInterval(float avg){
    float randNum, intervalTime;
    randNum = (float)rand() / (float)RAND_MAX;
    intervalTime  = -1*(1.0/avg) * log(randNum);
    return intervalTime;
}

void CommenceCalculations(std::string txtFile);


int main(){
    CommenceCalculations("test1.txt");
    CommenceCalculations("test2.txt");
    return 0;
}

















void CommenceCalculations(std::string txtFile){
    int lambda, mu, serverCount, numEvents;
    float time = 0;
    Priority pQueue;
    FIFO fQueue;

    int customersWaitedCnt, randomInt;
    float totalWaitTime = 0, totalTime = 0, serviceTime = 0, idleTime = 0;

    std::ifstream file;
    file.open(txtFile);
    file >> lambda;
    file >> mu;
    file >> serverCount;
    file >> numEvents;
    int openServers;
    int testCounter = 0;
    openServers = serverCount;
    Customer newCustomer;
    Node* currentNode;
    for(int i = 0; i < numEvents; i++){
        
        if(pQueue.getSize() < serverCount + 1){
            for(int j = 0; j < 197; j++){
                time += GetNextRandomInterval(lambda);
                pQueue.addArrival(Customer(time));
            }
        }

        randomInt = GetNextRandomInterval(lambda);
        currentNode = pQueue.removeFrontNode();

        while(fQueue.customers.size() > 0 && openServers > 0){
            --openServers;
            fQueue.customers.at(0).setDepartureTime(randomInt + fQueue.customers.at(0).getArrivalTime());
            pQueue.addDeparture(fQueue.removeCustomer());
            serviceTime += pQueue.events.at(0)->customer.getDepartureTime();
        }
        if(currentNode->type == 'a'){
            if(openServers > 0){
                --openServers;
                currentNode->customer.setDepartureTime(randomInt + currentNode->eventTime);
                //std::cout << "eventTIme|" << currentNode->eventTime + randomInt << "| >" << testCounter << "<\t";
                testCounter++;
                pQueue.addDeparture(currentNode->customer);
                serviceTime += pQueue.events.at(0)->customer.getDepartureTime();
            }
            else{
                fQueue.addCustomer(currentNode->customer);
                customersWaitedCnt++;
            }
        }
        else{
            ++openServers;
        }
        //calculations portion
    if(fQueue.customers.size() > 0){
        totalWaitTime = totalWaitTime + (currentNode->eventTime - totalTime);
    }
    if(openServers == serverCount)
        idleTime += (currentNode->eventTime - totalTime);
    totalTime += (currentNode->eventTime - totalTime);
    // std::cout << "\tBOIIIII :: " << currentNode->eventTime << 
    //     " " << currentNode->type <<"\t";
    }
    
    std::cout << "Total Time: " << totalTime << std::endl;
    std::cout << "Customers Wait Count: " << customersWaitedCnt << std::endl;
    std::cout << "Total Wait Time: " << totalWaitTime << std::endl;
    std::cout << "Service Time: " << serviceTime << std::endl;
    std::cout << "Idle Time: " << idleTime << std::endl << std::endl;

}