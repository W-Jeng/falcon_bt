#pragma once 

#include "base_strategy.h"
#include<iostream>

class Strategy:public BaseStrategy {
public:
    void show()
    {
        std::cout << "Derived Class";
    }
};