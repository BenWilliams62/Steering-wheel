#include <iostream>
#include <string>
// #include <QtCore>
#include "Controls.hpp"

// compile with command: g++ -o <projectName> main.cpp Controls.cpp

int main()
{
    // start here
    //std::cout << "Qt version: "<< qVersion() << std::endl;
    control car;
    car.startCar();
    std::cout << "car started!\n";

    return 0;
};

/*

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

*/