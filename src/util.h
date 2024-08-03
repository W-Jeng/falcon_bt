
#include <cmath>

double round_decimal(double value, int decimal_places) {
    // Calculate the scaling factor
    double scale = std::pow(10.0, decimal_places);
    
    // Perform rounding and then scale back
    return std::round(value * scale) / scale;
}