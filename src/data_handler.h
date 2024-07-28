#pragma once

#include <queue>
#include "data_reader.h"
#include "event.h"

template <typename T>
using min_heap_on_time = std::priority_queue<T, std::vector<T>, std::greater<T>>;

class DataHandler {
public:
    // min_heap_on_time tick_event;


};