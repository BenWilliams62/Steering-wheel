#include <iostream>
#include "Controls.hpp"

// compile with command: g++ -o <projectName> main.cpp Controls.cpp

int main()
{
    // start timer
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

    // define new Control object, car
    control car;

    car.startCar(0);


    // commands as a test
    car.timer();
    car.shift("up");
    car.shift("up");
    car.timer();
    car.shift("up");
    car.shift("down");
    car.shift("reverse");
    car.shift("up");
    car.shift("neutral");
    car.timer();
    car.shift("reverse");
    car.timer();


    return 0;
}

/*
* 1 tbsp coriander
* 1 lemon
* 1 tbsp paprika
* 1 tbsp thyme
*/