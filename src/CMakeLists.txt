# CMakeList.txt : CMake project for falcon_bt, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (falcon_bt "main.cpp" "backtest_handler.cpp"  "strategy_a.h" "backtest_handler.h" "base_strategy.h" "data_handler.h" "data_reader.h" "data_reader.cpp" "event.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET falcon_bt PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
