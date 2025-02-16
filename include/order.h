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

enum OrderStatus {
    INCOMPLETE,
    COMPLETED,
    CANCELLED
};

struct Order {
    const std::string symbol;
    const OrderSide order_side;
    const std::uint32_t quantity;
    const OrderType order_type;
    const double limit_price;
    std::string user_tag;

    Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type, double t_limit_price, std::string user_tag);
    Order(std::string t_symbol, OrderSide t_order_side, std::uint32_t t_quantity, OrderType t_order_type, std::string user_tag);

    virtual const std::string to_string() const;
};

struct OrderTicket : public Order {
    const std::string order_id;
    const std::string order_submission_timestamp;
    const std::string order_received_timestamp;
    double average_price_filled;
    std::uint32_t quantity_filled;
    std::string last_filled_time;
    OrderStatus order_status;

    OrderTicket(const Order& t_order, std::string t_order_id, std::string order_submission_timestampt_, std::string t_order_received_timestamp);

    const std::string to_string() const override;
};