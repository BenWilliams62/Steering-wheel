#include <string>
#include <iostream>
#include <chrono>

class control
{
    // attributes
    int gear;
    double time;
    double bestTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

    // public functions
    public:
    void startCar(int g);
    void shift(std::string direction);
    void timer(); // un-comment in Controls.cpp
    void timerReset();
};