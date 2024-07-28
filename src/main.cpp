#include "backtest_handler.h"
#include "strategy_a.h"
#include "data_reader.h"


int main() {
    /*
    BacktestHandler backtest_handler;
    Strategy strategy; // Change this line to switch strategies
    backtest_handler.run_backtest(&strategy);
    */
    // read_content();
    DataReader data_reader("C:\\Users\\User\\Desktop\\cpp\\falcon_bt\\data", {"GE"}, "20240719");
    data_reader.create_input_stream();

    std::unique_ptr<MboMessage> msg = data_reader.get_next_message("GE");

    std::cout << "ts: " << msg -> ts_recv << std::endl;

    std::unique_ptr<MboMessage> msg2 = data_reader.get_next_message("GE");

    std::cout << "ts: " << msg2 -> ts_recv << std::endl;

    return 0;
}