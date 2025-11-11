#pragma once
#include <unordered_map>
#include <string>
class Binance {
    std::unordered_map<std::string, long double> coin_bid_price;
    std::unordered_map<std::string, long double> coin_ask_price;
public:
    Binance() = delete;
    std::string get_bid_price(std::string coin);
    std::string get_ask_price(std::string coin);
    void update_prices();
};