#pragma once
#include <string>
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

// GUI controls
class WheelGUI : public QWidget {

  Q_OBJECT

  // attributes
    bool engine;            // engine on or off
    int gear;               // gear
    bool DRS;               // True when DRS enabled
    bool PLL;               // True when pit limiter is on
    double BB;              // Brake balance (0 - 100)
    double EB;              // Engine braking (0 - 100)
    int diffEntry;          // corner entry diff setting
    int activePreset;       // current selected preset
    int optionPreset;       // preset currently hovered on


  public:
    WheelGUI(QWidget *parent = nullptr);

  private slots:
    void startCar();                    // set the intial settings for the car
    void shiftUp();                     // handle gear changes
    void shiftDown();                   // handle gear changes
    void shiftNeutral();                // handle neutral change
    void toggleDRS();                   // toggle DRS on and off
    void togglePLL();                   // toggle Pitlane limiter
    void EBUp();                        // turn up engine braking
    void EBDown();                      // turn down engine braking
    void BBUp();                        // Shift brake balance forward
    void BBDown();                      // Shift brake balance backwards
    void setDiffUp();                   // Set the diff settings.
    void setDiffDn();                   // Set the diff settings.
    void scrollUp();                    // scroll up in the menu
    void scrollDown();                  // scroll down in the menu
    void selectMenu();                  // select menu option

  protected:
    void keyPressEvent(QKeyEvent *event);// handle controls through key
  private:
    QLabel *gearlbl;
    QLabel *DRSlbl;
    QLabel *PLLlbl;
    QLabel *EBlbl;
    QLabel *BBlbl;
    QLabel *Errorlbl;
    QLabel *Difflbl;
    QLabel *Presetlbl;
    QLabel *Selectlbl;
};