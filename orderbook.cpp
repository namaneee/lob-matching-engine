// orderbook.cpp
#include "orderbook.h"
#include <iostream>

void OrderBook::addOrder(Order order) {
    if (order.side == Side::BUY) {
        bids[order.price].push(order);
    } else {
        asks[order.price].push(order);
    }
    match();
}

void OrderBook::match() {
    while (!bids.empty() && !asks.empty()) {
        double bestBidPrice = bids.begin()->first;
        auto& bidQueue = bids.begin()->second;
        
        double bestAskPrice = asks.begin()->first;
        auto& askQueue = asks.begin()->second;

        if (bestBidPrice < bestAskPrice) break; // No match possible

        Order& bid = bidQueue.front();
        Order& ask = askQueue.front();

        uint64_t tradedQty = std::min(bid.quantity, ask.quantity);
        //std::cout << "TRADE: " << tradedQty 
                 // << " @ $" << bestAskPrice << "\n";

        bid.quantity -= tradedQty;
        ask.quantity -= tradedQty;

        if (bid.quantity == 0) bidQueue.pop();
        if (ask.quantity == 0) askQueue.pop();
        if (bidQueue.empty()) bids.erase(bestBidPrice);
        if (askQueue.empty()) asks.erase(bestAskPrice);
    }
}