#include "data_reader.h"

DataReader::DataReader(std::string t_dir, std::vector<std::string> t_symbols):
    file_directory(t_dir), symbols(std::move(t_symbols)){};

// this function is supposed to create all the input streams for all symbols for the particular date
// handles closing the input stream by automatically deallocating the memory
void DataReader::create_input_stream(std::string date) {
    for (int i = 0; i < symbols.size(); ++i) {
        std::string full_file_dir(file_directory + "\\" + symbols[i] + "_" + date + ".csv");
        std::unique_ptr<std::ifstream> input_stream_file = std::make_unique<std::ifstream>(full_file_dir);

        // check if file exists, if not throw error
        if (!(*input_stream_file)) {
            throw std::runtime_error("Unable to source the file for input stream: " + full_file_dir);
        }
        // take away header
        std::string line;
        std::getline(*input_stream_file, line);

        file_streamers.emplace(symbols[i], std::move(input_stream_file));
    }
    return;
};

// initialize the basis of min heap on every symbol
void DataReader::init_on_minheap_symbols() {
    for (int i = 0; i < symbols.size(); ++i) {
        std::unique_ptr<MboMessage> msg = get_next_sym_message(symbols[i]);
        if (msg != nullptr) {
            data_priority.push(*msg);
        }
    }

    MboMessage temp = data_priority.top();
    std::cout << "top ts event: " << temp.ts_event << std::endl;
    return;
};

// key idea is to we take the top then replace the tickers data in
// if data priority is empty meaning we have exhausted all available data across all input streamers
std::unique_ptr<MboMessage> DataReader::get_next_message() {
    if (data_priority.empty()) {
        return nullptr;
    }
    // get top, then remove the message before adding new message
    MboMessage priority_msg = data_priority.top();
    data_priority.pop(); 

    std::unique_ptr<MboMessage> msg = get_next_sym_message(priority_msg.symbol);
    if (msg != nullptr) {
        data_priority.push(*msg);
    }

    return std::make_unique<MboMessage>(priority_msg);
};

std::unique_ptr<MboMessage> DataReader::get_next_sym_message(std::string sym) {
    return convert_content(*(file_streamers[sym]));
};

// this is to get the filestreamer's next line code and transform to appropriate data class
std::unique_ptr<MboMessage> DataReader::convert_content(std::ifstream& file_streamer) {
    std::string line;

    if (!std::getline(file_streamer, line)) {
        return nullptr;
    }
    
    std::istringstream line_stream(line);
    std::string field;
    
    std::unique_ptr<MboMessage> mbo_msg = std::make_unique<MboMessage>();

    std::getline(line_stream, mbo_msg -> ts_recv, ',');
    std::getline(line_stream, mbo_msg -> ts_event, ',');

    std::getline(line_stream, field,',');
    mbo_msg -> rtype = std::stoi(field);
    
    std::getline(line_stream, field,',');
    mbo_msg -> publisher_id = std::stoi(field);
        
    std::getline(line_stream,field,',');
    mbo_msg -> instrument_id = std::stoi(field);

    std::getline(line_stream, mbo_msg -> action,',');
    std::getline(line_stream, mbo_msg -> side,',');
    std::getline(line_stream, mbo_msg -> price,',');
    
    std::getline(line_stream,field,',');
    mbo_msg -> size = std::stoi(field);
        
    std::getline(line_stream,field,',');
    mbo_msg -> channel_id = std::stoi(field);

    std::getline(line_stream,field,',');
    mbo_msg -> order_id = std::stoi(field);

    std::getline(line_stream,field,',');
    mbo_msg -> flags = std::stoi(field);

    std::getline(line_stream,field,',');
    mbo_msg -> ts_in_delta = std::stoi(field);
        
    std::getline(line_stream,field,',');
    mbo_msg -> sequence = std::stoi(field);
        
    std::getline(line_stream,mbo_msg -> symbol,',');

    return mbo_msg;
};

inline std::string DataReader::get_latest_timestamp() const {
    if (data_priority.empty()) {
        return "";
    }
    return data_priority.top().ts_event;
};