# Limit Order Book (LOB) Matching Engine

## Overview
This project is a high-performance Limit Order Book (LOB) matching engine built in C++. It simulates the core matching logic of a financial exchange by ingesting a massive stream of simulated buy and sell orders, matching them based on strict price-time priority (FIFO), and resolving high-throughput partial fills.

## Time Complexity
The engine leverages the C++ Standard Template Library (STL) to ensure deterministic, low-latency execution:

| Operation | Data Structure | Time Complexity |
| :--- | :--- | :--- |
| Price Level Routing (Inserts) | `std::map` | $O(\log N)$ |
| Order Execution (FIFO Match) | `std::queue` | $O(1)$ |
| Order Pop / Deletion | `std::queue` | $O(1)$ |

## Performance Benchmark
* **Processed 1,000,000 randomized orders in ~4081ms.** *(Note: This benchmark represents end-to-end execution on a local machine, which includes the I/O bottleneck of single-threaded string parsing from a CSV file. The core in-memory matching logic executes in a fraction of this total time).*

## How to Build and Run
This project uses standard C++ components and can be compiled natively without complex build systems.

**1. Generate the Mock Dataset**
First, compile and run the data generator to create the 1 million test orders (`orders.csv`):
```bash
g++ -O2 -o generator generate_orders.cpp
.\generator.exe
