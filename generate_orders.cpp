#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

int main() {
    std::ofstream file("orders.csv");
    file << "id,side,price,quantity\n"; 

    std::mt19937 gen(1337); 
    std::uniform_int_distribution<> side_dist(0, 1);
    std::uniform_real_distribution<> price_dist(95.0, 105.0);
    std::uniform_int_distribution<uint64_t> qty_dist(1, 500);

    for (int i = 1; i <= 1000000; ++i) {
        std::string side = side_dist(gen) == 0 ? "BUY" : "SELL";
        double price = std::round(price_dist(gen) * 100.0) / 100.0;
        uint64_t qty = qty_dist(gen);
        
        file << i << "," << side << "," << std::fixed << std::setprecision(2) 
             << price << "," << qty << "\n";
    }
    std::cout << "Generated 1,000,000 orders in orders.csv\n";
    return 0;
}
