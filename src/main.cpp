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

    MboMessage* msg = data_reader.get_next_message("GE");

    return 0;
}