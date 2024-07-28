#pragma once

#include <string>


enum EventType {
    TickUpdate,
    OrderUpdate
};

template <typename T>
struct Event {
    std::string timestamp;
    EventType event_type;
    T data; // <- key point of most data

    Event(const std::string& t_timestamp, EventType& t_event_type, const T& t_data):
        timestamp(t_timestamp), event_type(t_event_type), data(t_data) {};

    bool operator>(const Event& other) {
        return timestamp > other.timestamp;
    }
};