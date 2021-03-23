/*
#include <iostream>
#include <string>
#include <QtCore>
#include "Controls.hpp"

// compile with command: g++ -o <projectName> main.cpp Controls.cpp

int main()
{
    // start here
    control car;
    car.startCar();
    std::cout << "car started!\n";
    std::cout << "Qt version: " << qVersion() << std::endl;

    return 0;
};

*/

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "Controls.hpp"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  PlusMinus window;

  window.resize(1000, 580); // 800 480 final. Extra space for buttons
  window.setWindowTitle("Cockpit display");
  window.show();

  return app.exec();

  return app.exec();
}
