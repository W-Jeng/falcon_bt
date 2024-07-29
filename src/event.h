#pragma once

#include <string>

enum EventType {
    TickUpdate,
    OrderUpdate
};

template <typename T>
struct Event {
    EventType event_type;
    std::string timestamp;

    Event(const EventType& t_event_type):
        event_type(t_event_type){};

    bool operator>(const Event& other) {
        return timestamp > other.timestamp;
    }

    void update_timestamp(const T& event_object) {
        // the class T needs to have a method called "get_latest_timestamp", so that we can call it
        // having this update, we can cycle through another min heap to achieve "what kind of event is next", then call the respective function
        timestamp = event_object.get_latest_timestamp();
        return;
    }
};