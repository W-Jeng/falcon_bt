#include "data_reader.h"

DataReader::DataReader(std::string t_dir, std::vector<std::string> t_symbols, std::string t_date):
    file_directory(t_dir), symbols(std::move(t_symbols)), date(t_date){};


void DataReader::create_input_stream() {
    // this function is supposed to create all the input streams for all symbols for the particular date

    for (int i = 0; i < symbols.size(); ++i) {
        std::string full_file_dir(file_directory + "\\" + symbols[i] + "_" + date + ".csv");
        std::unique_ptr<std::ifstream> input_stream_file = std::make_unique<std::ifstream>(full_file_dir);

        // check if file exists, if not throw error
        if (!input_stream_file) {
            throw std::runtime_error("Unable to source the file for input stream: " + full_file_dir);
        }
        std::string line;
        std::getline(*input_stream_file, line);

        std::cout << "line: " << line << std::endl;

        file_streamers.emplace(symbols[i], std::move(input_stream_file));
    }
    return;
}

MboMessage* DataReader::get_next_message(std::string sym) {
    std::cout << "here 0" << std::endl;
    std::cout << "mem: " << file_streamers[sym] << std::endl;
    
    MboMessage* msg = convert_content(*(file_streamers[sym]));
    
    return msg;
}

MboMessage* DataReader::convert_content(std::ifstream& file_streamer) {
    // if data exist then return the data, else return nullptr

    std::string line;
    std::cout << "here 1" << std::endl;
    std::getline(file_streamer, line);

    std::cout << "here 1.5" << std::endl;
    if (!std::getline(file_streamer, line)) {
        std::cout << "here!" << std::endl;
        return nullptr;
    }
    std::cout << "here 2" << std::endl;
    std::istringstream line_stream(line);
    std::string field;
    MboMessage mbo_msg;
    std::cout << "here 3" << std::endl;
    std::getline(line_stream, mbo_msg.ts_recv, ',');
    std::getline(line_stream, mbo_msg.ts_event, ',');

    std::getline(line_stream, field,',');
    mbo_msg.rtype = std::stoi(field);
    std::cout << "here 3" << std::endl;
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

    return &mbo_msg;
};

void read_content2() {
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
