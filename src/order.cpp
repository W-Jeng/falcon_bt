#include <stdexcept>
#include "order.h"
#include "util.h"

// for LMT order initialization
Order::Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type, double t_limit_price): 
    symbol(std::move(t_symbol)), order_side(t_order_side), quantity(t_quantity), order_type(t_order_type), limit_price(t_limit_price) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity cannot be zero or negative");
        }
    };

// for MKT order initialization
Order::Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type): 
    symbol(std::move(t_symbol)), order_side(t_order_side), quantity(t_quantity), order_type(t_order_type), limit_price(0.0) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity cannot be zero or negative");
        }
        if (order_type == OrderType::LMT) {
            throw std::invalid_argument("If order type is set to LMT, limit price must be present");
        }
    };

const std::string Order::to_string() const {
    std::string order_side_string = "B";
    std::string order_type_string = "LMT";

    if (order_side == OrderSide::S) {
        order_side_string = "S";
    }
    if (order_type == OrderType::MKT) {
        order_type_string = "MKT";
    }

    return "Order(symbol=" + symbol + ", order_side=" + order_side_string + ", quantity=" +
        std::to_string(quantity) + ", order_type=" + order_type_string + ", limit_price=" + std::to_string(limit_price)+")";
};