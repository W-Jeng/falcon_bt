#include "backtest_handler.h"
#include "strategy_a.h" // Change this line to switch strategies
// #include "StrategyB.h" // Uncomment to switch to StrategyB

int main() {
    BacktestHandler backtest_handler;

    // Create an instance of the chosen strategy
    Strategy strategy; // Change this line to switch strategies
    // StrategyB strategy; // Uncomment to switch to StrategyB
    strategy.show();
    backtest_handler.run_backtest(&strategy);

    return 0;
}