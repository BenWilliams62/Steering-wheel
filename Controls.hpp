#pragma once
#include <string>
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class control
{
    // attributes
    int gear;               // gear
    bool DRS;               // True when DRS enabled
    bool PLL;               // True when pit limiter is on
    double BB;              // Brake balance (0 - 100)
    double EB;              // Engine braking (0 - 100)
    int activePreset;       // current preset
    int optionPreset;       // flicking through presets
    int diffEntry;          // corner entry diff setting
    int diffMid;            // mid corner diff setting
    int diffExit;           // corner exit diff setting

    // public functions
    public:
    void startCar();                    // set the intial settings for the car
    void shift(std::string direction);  // handle gear changes
    void toggleDRS();                   // toggle DRS on and off
    void togglePLL();                   // toggle Pitlane limiter
    void setBB(std::string direction);  // handle Brake balance settings
    void setEB(std::string direction);  // handle Engine braking settings
    void scrollPreset(int jump);        // flick through presets
    void setPreset();                   // set preset
    void setDiffEntry(std::string direction); // sett diff entry setting
    void setDiffMid(std::string direction);   // sett diff Mid setting
    void setDiffExit(std::string direction);  // sett diff Exit setting
};

// GUI controls
class PlusMinus : public QWidget {

  Q_OBJECT

  // attributes
    bool engine;            // engine on or off
    int gear;               // gear
    bool DRS;               // True when DRS enabled
    bool PLL;               // True when pit limiter is on
    double BB;              // Brake balance (0 - 100)
    double EB;              // Engine braking (0 - 100)
    int activePreset;       // current preset
    int optionPreset;       // flicking through presets
    int diffEntry;          // corner entry diff setting


  public:
    PlusMinus(QWidget *parent = nullptr);

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
    /*
    void scrollPreset(int jump);        // flick through presets
    void setPreset();                   // set preset
    void setDiffEntry(std::string direction); // sett diff entry setting
    void setDiffMid(std::string direction);   // sett diff Mid setting
    void setDiffExit(std::string direction);  // sett diff Exit setting
    */

  private:
    QLabel *gearlbl;
    QLabel *DRSlbl;
    QLabel *PLLlbl;
    QLabel *EBlbl;
    QLabel *BBlbl;
    QLabel *Errorlbl;
};