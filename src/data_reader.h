#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdint>

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


void read_content() {
    std::ifstream input_file("C:\\Users\\User\\Desktop\\cpp\\falcon_bt\\src\\mbo_ge.csv");

    if(!input_file) {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    std::string line;
    std::vector<MboMessage> mbo_messages;

    // Skip the header line
    std::getline(input_file,line);

    while(std::getline(input_file,line)) {
        std::istringstream line_stream(line);
        std::string field;
        MboMessage mbo_msg;

        std::getline(line_stream, mbo_msg.ts_recv, ',');

        
        std::getline(line_stream, mbo_msg.ts_event, ',');

        std::getline(line_stream, field,',');
        mbo_msg.rtype = std::stoi(field);

        std::getline(line_stream, field,',');
        mbo_msg.publisher_id = std::stoi(field);
        
        std::getline(line_stream,field,',');
        mbo_msg.instrument_id = std::stoi(field);

        std::getline(line_stream, mbo_msg.action,',');
        std::getline(line_stream, mbo_msg.side,',');
        
        std::getline(line_stream, mbo_msg.price,',');
        
        std::getline(line_stream,field,',');
        mbo_msg.size = std::stoi(field);
        
        std::getline(line_stream,field,',');
        mbo_msg.channel_id = std::stoi(field);

        std::getline(line_stream,field,',');
        mbo_msg.order_id = std::stoi(field);

        std::getline(line_stream,field,',');
        mbo_msg.flags = std::stoi(field);

        std::getline(line_stream,field,',');
        mbo_msg.ts_in_delta = std::stoi(field);
        
        std::getline(line_stream,field,',');
        mbo_msg.sequence = std::stoi(field);
        
        std::getline(line_stream,mbo_msg.symbol,',');
        
        mbo_messages.push_back(mbo_msg);

        if (mbo_messages.size() % 100000 == 0) 
            std::cout << "size: " << mbo_messages.size() << std::endl;
    }

    input_file.close();
    
    return;
}

/*
To save memory, it's better to load the tick data on the fly and maintain it using a min_heap on the unix timestamp
1) initiation requires reading data for string stream across different files for ONE DAY
*/
class DataReader {
public:
    DataReader(std::string t_dir, std::vector<std::string> t_symbols, std::string t_date);

    void create_input_stream();
};

