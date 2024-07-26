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
    DataReader data_reader("dirdir", {"ABCD", "CDE"}, "2024-01-01");
    return 0;
}