#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include "orderbook.h"

int main() {
    OrderBook book;
    std::ifstream file("orders.csv");
    std::string line;
    std::getline(file, line); 
    uint64_t id = 0;

    auto start = std::chrono::high_resolution_clock::now();

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string sideStr, priceStr, qtyStr, idStr;
        std::getline(ss, idStr, ',');
        std::getline(ss, sideStr, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, qtyStr, ',');

        Order o;
        o.id = std::stoull(idStr);
        o.side = (sideStr == "BUY") ? Side::BUY : Side::SELL;
        o.price = std::stod(priceStr);
        o.quantity = std::stoull(qtyStr);
        book.addOrder(o);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << "Processed 1M orders in " << ms << "ms\n";
    return 0;
}
