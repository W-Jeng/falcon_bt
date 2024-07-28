#include "backtest_handler.h"
#include "strategy_a.h"
#include "data_reader.h"
#include "event.h"


int main() {
    /*
    BacktestHandler backtest_handler;
    Strategy strategy; // Change this line to switch strategies
    backtest_handler.run_backtest(&strategy);
    */
    // read_content();
    DataReader data_reader("C:\\Users\\User\\Desktop\\cpp\\falcon_bt\\data", {"GE", "ROKU"});
    data_reader.create_input_stream("20240719");
    data_reader.init_on_minheap_symbols();

    // std::unique_ptr<MboMessage> msg = data_reader.get_next_message();
 
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    std::cout << "ts: " << data_reader.get_next_message() -> ts_event << std::endl;
    return 0;
}