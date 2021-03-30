#include "Controls.hpp"
//#include <QGridLayout>
#include <string>
#include <QFont>
#include <QKeyEvent>
#include <QMenu>

// GUI
WheelGUI::WheelGUI(QWidget *parent)
    : QWidget(parent) {

  // create all the buttons and labels
  /*
  // uncomment this block if you want the on screen buttons
  auto *gearplsBtn = new QPushButton("Gear +", this);
  auto *gearminBtn = new QPushButton("Gear -", this);
  auto *gearntrBtn = new QPushButton("Gear N", this);
  auto *DRSBtn = new QPushButton("DRS", this);
  auto *PLLBtn = new QPushButton("PLL", this);
  auto *EBplsBtn = new QPushButton("EB +", this);
  auto *EBminBtn = new QPushButton("EB -", this);
  auto *BBplsBtn = new QPushButton("BB +", this);
  auto *BBminBtn = new QPushButton("BB -", this);
  auto *ignitionBtn = new QPushButton("Ignition", this);
  auto *DiffUpBtn = new QPushButton("Diff +", this);
  auto *DiffDnBtn = new QPushButton("Diff -", this);
  */
  // rotary switch

  gearlbl = new QLabel("", this);
  DRSlbl = new QLabel("DRS", this);
  PLLlbl = new QLabel("PLL", this);
  EBlbl = new QLabel("Engine Braking", this);
  BBlbl = new QLabel("Brake Balance", this);
  Errorlbl = new QLabel("Start engine", this);
  Difflbl = new QLabel("Diff", this);
  Presetlbl = new QLabel("Current",this);
  Selectlbl = new QLabel("Hover",this);

  // stylise
  // ignition
  // ignitionBtn->setGeometry(0, 480, 100,100);

  // gears
  // gearplsBtn->setGeometry(900, 200, 100,100);
  // gearminBtn->setGeometry(000, 200, 100,100);
  // gearntrBtn->setGeometry(900, 480, 100,100);
  gearlbl->setGeometry(350,0,200,400);
  QFont ft;
  ft.setPointSize(200);
  gearlbl->setFont(ft);

  // DRS
  DRSlbl->setGeometry(00,0,100,100);
  // DRSBtn->setGeometry(0,0,100,100);

  // Pit lane limiter
  PLLlbl->setGeometry(700,0,100,100);
  // PLLBtn->setGeometry(900,0,100,100);

  // engine breaking
  //EBplsBtn->setGeometry(000,300,100,50);
  //EBminBtn->setGeometry(000,350,100,50);
  EBlbl->setGeometry(00,300,100,100);

  // engine breaking
  // BBplsBtn->setGeometry(900,300,100,50);
  // BBminBtn->setGeometry(900,350,100,50);
  BBlbl->setGeometry(700,300,100,100);

  // Error label
  Errorlbl->setGeometry(450, 400,200,50);

  // Diff
  // DiffUpBtn->setGeometry(300,480,100,100);
  // DiffDnBtn->setGeometry(200,480,100,100);
  Difflbl->setGeometry(150,380,50,100);

  // Preset
  Presetlbl->setGeometry(350,380,50,100);
  Selectlbl->setGeometry(400,380,50,100);

    /*
    // uncomment for onscreen buttons
  connect(ignitionBtn, &QPushButton::clicked, this, &WheelGUI::startCar);
  connect(gearplsBtn, &QPushButton::clicked, this, &WheelGUI::shiftUp);
  connect(gearminBtn, &QPushButton::clicked, this, &WheelGUI::shiftDown);
  connect(gearntrBtn, &QPushButton::clicked, this, &WheelGUI::shiftNeutral);
  connect(DRSBtn, &QPushButton::clicked, this, &WheelGUI::toggleDRS);
  connect(PLLBtn, &QPushButton::clicked, this, &WheelGUI::togglePLL);
  connect(EBplsBtn, &QPushButton::clicked, this, &WheelGUI::EBUp);
  connect(EBminBtn, &QPushButton::clicked, this, &WheelGUI::EBDown);
  connect(BBplsBtn, &QPushButton::clicked, this, &WheelGUI::BBUp);
  connect(BBminBtn, &QPushButton::clicked, this, &WheelGUI::BBDown);
  connect(DiffUpBtn, &QPushButton::clicked, this, &WheelGUI::setDiffUp);
  connect(DiffDnBtn, &QPushButton::clicked, this, &WheelGUI::setDiffDn);
  */
  // rotary switch
};

// Start the car button press
void WheelGUI::startCar()
{
    if (engine == false)
    {
        engine = true;
        Errorlbl->setText("");
        // turn car on
    }
    else
    {
        engine = false;
        gearlbl->setText("I");
        Errorlbl->setText("Start Engine");
        // turn car off
    };

    gear = 0;
    gearlbl->setText("N");
    
    DRS = false;
    DRSlbl->setText("");

    PLL = true;
    PLLlbl->setText("");

    BB = 50.0;
    BBlbl->setText(QString::number(BB));
    
    EB = 50.0;
    EBlbl->setText(QString::number(EB));

    diffEntry = 1;
    Difflbl->setText(QString::number(diffEntry));

    activePreset = 1;
    Presetlbl->setText(QString::number(activePreset));

    optionPreset = 1;
    Selectlbl->setText(QString::number(optionPreset));

};

// Shift up button press
void WheelGUI::shiftUp()
{
    if (engine != true)
    {
        return;
    };
    if (gear < 8)
    {
        // change gear up
        gear++;
    };
    gearlbl->setText(QString::number(gear));
    if (gear == 0)
    {
        WheelGUI::shiftNeutral();
    };
};

// Shift Down button press
void WheelGUI::shiftDown()
{
    if (engine != true)
    {
        return;
    };
    if (gear > 1)
    {
        // change gear down
        gear--;
        gearlbl->setText(QString::number(gear));
    }
    else if (gear == 0)
    {
        // change gear to reverse
        gear = -1;
        gearlbl->setText("R");
    };
};

// Shift to neutral button press
void WheelGUI::shiftNeutral()
{
    if (engine != true)
    {
        return;
    };
    // change gear to neutral
    gear = 0;
    gearlbl->setText("N");
};

// Turn DRS on or off
void WheelGUI::toggleDRS()
{
    if (engine != true)
    {
        return;
    };
    if (DRS == true)
    {
        // Close DRS
        DRS = false;
        DRSlbl->setText("");
    }
    else
    {
        // Open DRS
        DRS = true;
        DRSlbl->setText("DRS");
    };
};

// Turn pit lane limiter on or off
void WheelGUI::togglePLL()
{
    if (engine != true)
    {
        return;
    };
    if (PLL == true)
    {
        // Turn on PLL
        PLL = false;
        PLLlbl->setText("");
    }
    else
    {
        // Turn off PLL
        PLL = true;
        PLLlbl->setText("PLL");
    };
};

// turn engine braking up
void WheelGUI::EBUp()
{
    if (engine != true)
    {
        return;
    };
    if (EB < 100.0)
    {
        EB += 0.1;
        EBlbl->setText(QString::number(EB));
    };
};

// turn engine braking down
void WheelGUI::EBDown()
{
    if (engine != true)
    {
        return;
    };
    if (EB > 0.0)
    {
        EB -= 0.1;
        EBlbl->setText(QString::number(EB));
    };
};

// move brake balance forward
void WheelGUI::BBUp()
{
    if (engine != true)
    {
        return;
    };
    if (BB < 100.0)
    {
        BB += 0.1;
        BBlbl->setText(QString::number(BB));
    };
};

// move brake balance backwards
void WheelGUI::BBDown()
{
    if (engine != true)
    {
        return;
    };
    if (BB > 0.0)
    {
        BB -= 0.1;
        BBlbl->setText(QString::number(BB));
    };
};

// stiffen Diff
void WheelGUI::setDiffUp()
{
    if (diffEntry < 10)
    {
        diffEntry++;
    };
    Difflbl->setText(QString::number(diffEntry));
};

// Loosen Diff
void WheelGUI::setDiffDn()
{
    if (diffEntry != 1)
    {
        diffEntry--;
    };
    Difflbl->setText(QString::number(diffEntry));
};

// preset menu scroll up
void WheelGUI::scrollUp()
{
    if (optionPreset < 10)
    {
        optionPreset++;
        Selectlbl->setText(QString::number(optionPreset));
    };
};

// preset menu scroll down
void WheelGUI::scrollDown()
{
    if (optionPreset > 1)
    {
        optionPreset--;
        Selectlbl->setText(QString::number(optionPreset));
    };
};

// preset menu - select
void WheelGUI::selectMenu()
{
    activePreset = optionPreset;
    Presetlbl->setText(QString::number(activePreset));
};

// Key press handling
void WheelGUI::keyPressEvent(QKeyEvent *event)
{
    // Ignition
    if (event->key() == Qt::Key_I)
    {
        WheelGUI::startCar();
    }
    // gear shift up
    else if(event->key() == Qt::Key_P)
    {
        WheelGUI::shiftUp();
    }
    // gear shift down
    else if (event->key() == Qt::Key_Q)
    {
        WheelGUI::shiftDown();
    }
    // gear shift to  neutral
    else if (event->key() == Qt::Key_N)
    {
        WheelGUI::shiftNeutral();
    }
    // toggle DRS
    else if (event->key() == Qt::Key_W)
    {
        WheelGUI::toggleDRS();
    }
    // toggle PLL
    else if (event->key() == Qt::Key_O)
    {
        WheelGUI::togglePLL();
    }
    // Engine braking up
    else if (event->key() == Qt::Key_D)
    {
        WheelGUI::EBUp();
    }
    // Engine braking down
    else if (event->key() == Qt::Key_C)
    {
        WheelGUI::EBDown();
    }
    // brake balance - Forward
    else if (event->key() == Qt::Key_K)
    {
        WheelGUI::BBUp();
    }
    // brake balance - Backwards
    else if (event->key() == Qt::Key_M)
    {
        WheelGUI::BBDown();
    }
    // set Diff - stiffer
    else if (event->key() == Qt::Key_F)
    {
        WheelGUI::setDiffUp();
    }
    // set Diff - looser
    else if (event->key() == Qt::Key_V)
    {
        WheelGUI::setDiffDn();
    }
    // scroll up menu
    else if (event->key() == Qt::Key_Up)
    {
        WheelGUI::scrollUp();
    }
    // scroll down menu
    else if (event->key() == Qt::Key_Down)
    {
        WheelGUI::scrollDown();
    }
    // select menu item
    else if (event->key() == Qt::Key_B)
    {
        WheelGUI::selectMenu();
    }
    else
    {
        WheelGUI::startCar();
    };
};

