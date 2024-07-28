#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <unordered_map>
#include <queue>

template <typename T>
using min_heap_event = std::priority_queue<T, std::vector<T>, std::greater<T>>;

struct MboMessage {
    std::string ts_recv;
    std::string ts_event;
    uint16_t rtype;
    uint16_t publisher_id;
    uint16_t instrument_id;
    std::string action;
    std::string side;
    std::string price;
    uint32_t size;
    uint16_t channel_id;
    uint16_t order_id;
    uint16_t flags;
    uint32_t ts_in_delta;
    uint32_t sequence;
    std::string symbol;
    bool is_loaded = false;

    bool operator>(const MboMessage& other) const {
        return ts_event > other.ts_event;
    }
};

/*
To save memory, it's better to load the tick data on the fly and maintain it using a min_heap on the unix timestamp
1) initiation requires reading data for string stream across different files for ONE DAY
*/

class DataReader {
public:
    std::string file_directory;
    std::vector<std::string> symbols;
    std::unordered_map<std::string, std::unique_ptr<std::ifstream>> file_streamers;
    min_heap_event<MboMessage> data_priority;

    DataReader(std::string t_dir, std::vector<std::string> t_symbols);

    void create_input_stream(std::string date);
    void init_on_minheap_symbols();
    std::unique_ptr<MboMessage> get_next_message();

private:
    std::unique_ptr<MboMessage> get_next_sym_message(std::string sym);
    std::unique_ptr<MboMessage> convert_content(std::ifstream& file_streamer);
};

