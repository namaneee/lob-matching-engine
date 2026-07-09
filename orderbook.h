#pragma once
#include <map>
#include <queue>
#include "order.h"

class OrderBook {
public:
    void addOrder(Order order);
    void printBook() const;

private:
    // Bids: highest price first (greater<double>)
    std::map<double, std::queue<Order>, std::greater<double>> bids;
    // Asks: lowest price first (default)
    std::map<double, std::queue<Order>> asks;

    void match();
};