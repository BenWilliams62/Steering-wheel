#include <iostream>
#include <string>
// #include <QtCore>
#include "Controls.hpp"

// compile with command: g++ -o <projectName> main.cpp Controls.cpp

int main()
{
    // start here
    control car;
    car.startCar();
    std::cout << "car started!\n";

    return 0;
};

