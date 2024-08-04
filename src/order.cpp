#include <stdexcept>
#include "order.h"
#include "util.h"

// for LMT order initialization
Order::Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity,
             OrderType t_order_type, double t_limit_price, std::string t_user_tag):
    symbol(std::move(t_symbol)),
    order_side(t_order_side),
    quantity(t_quantity),
    order_type(t_order_type),
    limit_price(t_limit_price),
    user_tag(std::move(t_user_tag)) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity cannot be zero or negative");
        }
    };

// for MKT order initialization
Order::Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity,
             OrderType t_order_type, std::string t_user_tag): 
    symbol(std::move(t_symbol)),
    order_side(t_order_side),
    quantity(t_quantity), order_type(t_order_type),
    limit_price(0.0),
    user_tag(std::move(t_user_tag)) {
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
        std::to_string(quantity) + ", order_type=" + order_type_string + ", limit_price=" +
        std::to_string(limit_price) + ", user_tag=" + user_tag + ")";
};

// derived class of Order 
OrderTicket::OrderTicket(const Order& t_order, std::string t_order_id,
                         std::string t_order_submission_timestamp, std::string t_order_received_timestamp):
    Order(t_order),
    order_id(t_order_id),
    order_submission_timestamp(t_order_submission_timestamp),
    order_received_timestamp(t_order_received_timestamp),
    average_price_filled(0.0),
    quantity_filled(0),
    last_filled_time(""),
    order_status(OrderStatus::INCOMPLETE){};

const std::string OrderTicket::to_string() const {
    std::string order_side_string = "B";
    std::string order_type_string = "LMT";
    std::string order_status_string = "INCOMPLETE";

    if (order_side == OrderSide::S) {
        order_side_string = "S";
    }
    if (order_type == OrderType::MKT) {
        order_type_string = "MKT";
    }
    
    if (order_status == OrderStatus::CANCELLED) {
        order_status_string = "CANCELLED";
    } else if (order_status == OrderStatus::COMPLETED) {
        order_status_string = "COMPLETED";
    }

    return "Order(symbol=" + symbol + ", order_side=" + order_side_string + ", quantity=" +
        std::to_string(quantity) + ", order_type=" + order_type_string + ", limit_price=" +
        std::to_string(limit_price) + ", user_tag=" + user_tag + ", order_id=" + order_id +
        ", order_submission_timestamp=" + order_submission_timestamp + ", order_received_timestamp=" + 
        order_received_timestamp + ", average_price_filled=" + std::to_string(average_price_filled) +
        ", quantity_filled=" + std::to_string(quantity_filled) + ", last_filled_time=" + last_filled_time + 
        ", order_status=" + order_status_string + ")";
};