#include "Controls.hpp"
//#include <QGridLayout>
#include <string>
#include <QFont>

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
  // rotary switch

  gearlbl = new QLabel("", this);
  DRSlbl = new QLabel("", this);
  PLLlbl = new QLabel("", this);
  EBlbl = new QLabel("", this);
  BBlbl = new QLabel("", this);
  Errorlbl = new QLabel("Start engine", this);

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

  // rotary switch

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
  // rotary switch
};

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
    // diffEntry = 1;
    // diffMid = 1;
    // diffExit = 1;
};

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

void PlusMinus::shiftNeutral()
{
    if (engine != true)
    {
        return;
    };
    gear = 0;
    gearlbl->setText("N");
};

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

/*
void PlusMinus::Presets()
{

};
*/