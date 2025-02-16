#pragma once 
#include <iostream>

class BaseStrategy {
public:
    virtual void on_tick() = 0;
};