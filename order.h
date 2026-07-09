#pragma once
#include <cstdint>
#include <string>

enum class Side { BUY, SELL };

struct Order {
    uint64_t id;
    Side side;
    double price;
    uint64_t quantity;
    uint64_t timestamp;
};