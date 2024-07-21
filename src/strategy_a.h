#pragma once 

#include "base_strategy.h"
#include<iostream>

class Strategy:public BaseStrategy {
public:
    void on_tick() override {
        std::cout << "Derived Class" <<  std::endl;
    }
};