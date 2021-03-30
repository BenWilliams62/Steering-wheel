#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include "Controls.hpp"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  WheelGUI window;

  // window geometry
  window.resize(800, 480); // final dimensions
  //window.resize(1000,580 // Extra space for buttons
  window.setWindowTitle("Cockpit display");
  window.show();

  return app.exec();
}
