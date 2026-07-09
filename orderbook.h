#pragma once
#include <map>
#include <queue>
#include "order.h"

class OrderBook {
public:
    void addOrder(Order order);
    void printBook() const;

private:
    
    std::map<double, std::queue<Order>, std::greater<double>> bids;
    
    std::map<double, std::queue<Order>> asks;

    void match();
};
