#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>
#include <unordered_map>

struct MboMessage{
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
};

/*
To save memory, it's better to load the tick data on the fly and maintain it using a min_heap on the unix timestamp
1) initiation requires reading data for string stream across different files for ONE DAY
*/
class DataReader {
public:
    std::string file_directory;
    std::vector<std::string> symbols;
    std::string date;
    std::unordered_map<std::string, std::ifstream*> file_streamers;

    DataReader(std::string t_dir, std::vector<std::string> t_symbols, std::string t_date);

    void create_input_stream();
    MboMessage get_next_message(std::string sym);

private:
    MboMessage* convert_content(std::ifstream& file_streamer);
};

