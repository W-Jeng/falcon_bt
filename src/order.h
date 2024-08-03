#pragma once 
#include <string>
#include <cstdint>
#include <iostream>


enum OrderType {
    MKT,
    LMT
};

enum OrderSide {
    B,
    S
};

struct Order {
    const std::string symbol;
    const OrderSide order_side;
    const std::uint32_t quantity;
    const OrderType order_type;
    const double limit_price;

    Order (std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type, double t_limit_price);
    Order (std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type);

    const std::string to_string() const;
};