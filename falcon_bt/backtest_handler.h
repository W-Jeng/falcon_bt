#pragma once 

#include "base_strategy.h"

class BacktestHandler {
public:
    void run_backtest(BaseStrategy* base_strategy) {
        base_strategy->show();
    }
};