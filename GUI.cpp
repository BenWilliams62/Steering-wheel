#include "Controls.hpp"
//#include <QGridLayout>
#include <string>
#include <QFont>
#include <QKeyEvent>

// GUI
PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent) {

  // create all the buttons and labels
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
  // rotary switch

  gearlbl = new QLabel("", this);
  DRSlbl = new QLabel("", this);
  PLLlbl = new QLabel("", this);
  EBlbl = new QLabel("", this);
  BBlbl = new QLabel("", this);
  Errorlbl = new QLabel("Start engine", this);
  Difflbl = new QLabel("", this);

  // stylise
  // ignition
  ignitionBtn->setGeometry(0, 480, 100,100);

  // gears
  gearplsBtn->setGeometry(900, 200, 100,100);
  gearminBtn->setGeometry(000, 200, 100,100);
  gearntrBtn->setGeometry(900, 480, 100,100);
  gearlbl->setGeometry(450,0,200,400);
  QFont ft;
  ft.setPointSize(200);
  gearlbl->setFont(ft);

  // DRS
  DRSlbl->setGeometry(100,0,100,100);
  DRSBtn->setGeometry(0,0,100,100);

  // Pit lane limiter
  PLLlbl->setGeometry(800,0,100,100);
  PLLBtn->setGeometry(900,0,100,100);

  // engine breaking
  EBplsBtn->setGeometry(000,300,100,50);
  EBminBtn->setGeometry(000,350,100,50);
  EBlbl->setGeometry(100,300,100,100);

  // engine breaking
  BBplsBtn->setGeometry(900,300,100,50);
  BBminBtn->setGeometry(900,350,100,50);
  BBlbl->setGeometry(800,300,100,100);

  // Error label
  Errorlbl->setGeometry(450, 400,200,50);

  // Diff
  DiffUpBtn->setGeometry(300,480,100,100);
  DiffDnBtn->setGeometry(200,480,100,100);
  Difflbl->setGeometry(250,380,50,100);

  connect(ignitionBtn, &QPushButton::clicked, this, &PlusMinus::startCar);
  connect(gearplsBtn, &QPushButton::clicked, this, &PlusMinus::shiftUp);
  connect(gearminBtn, &QPushButton::clicked, this, &PlusMinus::shiftDown);
  connect(gearntrBtn, &QPushButton::clicked, this, &PlusMinus::shiftNeutral);
  connect(DRSBtn, &QPushButton::clicked, this, &PlusMinus::toggleDRS);
  connect(PLLBtn, &QPushButton::clicked, this, &PlusMinus::togglePLL);
  connect(EBplsBtn, &QPushButton::clicked, this, &PlusMinus::EBUp);
  connect(EBminBtn, &QPushButton::clicked, this, &PlusMinus::EBDown);
  connect(BBplsBtn, &QPushButton::clicked, this, &PlusMinus::BBUp);
  connect(BBminBtn, &QPushButton::clicked, this, &PlusMinus::BBDown);
  connect(DiffUpBtn, &QPushButton::clicked, this, &PlusMinus::setDiffUp);
  connect(DiffDnBtn, &QPushButton::clicked, this, &PlusMinus::setDiffDn);
  // rotary switch
};

// Start the car button press
void PlusMinus::startCar()
{
    if (engine == false)
    {
        engine = true;
        Errorlbl->setText("");
    }
    else
    {
        engine = false;
        gearlbl->setText("I");
        Errorlbl->setText("Start Engine");
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
    // activePreset = 1;
    // optionPreset = 1;

    diffEntry = 1;
    Difflbl->setText(QString::number(diffEntry));
};

// Shift up button press
void PlusMinus::shiftUp()
{
    if (engine != true)
    {
        return;
    };
    if (gear < 8)
    {
        gear++;
    };
    gearlbl->setText(QString::number(gear));
    if (gear == 0)
    {
        gearlbl->setText("N");
    };
};

// Shift Down button press
void PlusMinus::shiftDown()
{
    if (engine != true)
    {
        return;
    };
    if (gear > 1)
    {
        gear--;
        gearlbl->setText(QString::number(gear));
    }
    else if (gear == 0)
    {
        gear = -1;
        gearlbl->setText("R");
    };
};

// Shift to neutral button press
void PlusMinus::shiftNeutral()
{
    if (engine != true)
    {
        return;
    };
    gear = 0;
    gearlbl->setText("N");
};

// Turn DRS on or off
void PlusMinus::toggleDRS()
{
    if (engine != true)
    {
        return;
    };
    if (DRS == true)
    {
        DRS = false;
        DRSlbl->setText("");
    }
    else
    {
        DRS = true;
        DRSlbl->setText("DRS");
    };
};

// Turn pit lane limiter on or off
void PlusMinus::togglePLL()
{
    if (engine != true)
    {
        return;
    };
    if (PLL == true)
    {
        PLL = false;
        PLLlbl->setText("");
    }
    else
    {
        PLL = true;
        PLLlbl->setText("PLL");
    };
};

// turn engine braking up
void PlusMinus::EBUp()
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
void PlusMinus::EBDown()
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
void PlusMinus::BBUp()
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
void PlusMinus::BBDown()
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
void PlusMinus::setDiffUp()
{
    if (diffEntry < 10)
    {
        diffEntry++;
    };
    Difflbl->setText(QString::number(diffEntry));
};

// Loosen Diff
void PlusMinus::setDiffDn()
{
    if (diffEntry != 1)
    {
        diffEntry--;
    };
    Difflbl->setText(QString::number(diffEntry));
};

/*
void PlusMinus::Presets()
{

};
*/

// Key press handling56
void PlusMinus::keyPressEvent(QKeyEvent *event)
{
    // Ignition
    if (event->key() == Qt::Key_I)
    {
        PlusMinus::startCar();
    }
    // gear shift up
    else if(event->key() == Qt::Key_P)
    {
        PlusMinus::shiftUp();
    }
    // gear shift down
    else if (event->key() == Qt::Key_Q)
    {
        PlusMinus::shiftDown();
    }
    // gear shift to  neutral
    else if (event->key() == Qt::Key_N)
    {
        PlusMinus::shiftNeutral();
    }
    // toggle DRS
    else if (event->key() == Qt::Key_W)
    {
        PlusMinus::toggleDRS();
    }
    // toggle PLL
    else if (event->key() == Qt::Key_O)
    {
        PlusMinus::togglePLL();
    }
    // Engine braking up
    else if (event->key() == Qt::Key_D)
    {
        PlusMinus::EBUp();
    }
    // Engine braking down
    else if (event->key() == Qt::Key_C)
    {
        PlusMinus::EBDown();
    }
    // brake balance - Forward
    else if (event->key() == Qt::Key_K)
    {
        PlusMinus::BBUp();
    }
    // brake balance - Backwards
    else if (event->key() == Qt::Key_M)
    {
        PlusMinus::BBDown();
    }
    // set Diff - stiffer
    else if (event->key() == Qt::Key_F)
    {
        PlusMinus::setDiffUp();
    }
    // set Diff - looser
    else if (event->key() == Qt::Key_V)
    {
        PlusMinus::setDiffDn();
    }
    else
    {
        PlusMinus::startCar();
    }
}