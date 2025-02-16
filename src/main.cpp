#include "backtest_handler.h"
#include "strategy_a.h"
#include "data_reader.h"
#include "event.h"
#include "order.h"
#include <iostream>

int main() {
    /*
    BacktestHandler backtest_handler;
    Strategy strategy; // Change this line to switch strategies
    backtest_handler.run_backtest(&strategy);
    */
    // read_content();

    std::cout << "hello world!" << std::endl;
    /*
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

    Order order("abc", OrderSide::B, 100, OrderType::LMT, 100.02, "123_temp"); 
    std::cout << order.to_string() << std::endl;

    OrderTicket order_ticket(order, "110", "001", "002");
    std::cout << order_ticket.to_string() << std::endl;
    */
    return 0;
}