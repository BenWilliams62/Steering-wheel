# Steering wheel

## Description
This steering wheel project is being built.

The aim of this project is to develop a full functioned f1-style steering wheel, to be put on a raspberry pi. This will not be connected to an f1 car (or any other car) for budget reasons, however if you are building a project and need this program, there will be spaces left to input the necessary code. 

The file "Pi wheel" will contain the necessary code to turn a series of buttons and a raspberry pi into a controller to control the program. This will need to be compiled separately.

Main.cpp, Controls.cpp and GUI.cpp focus on the GUI and functions needed to make this project work.

## Aims
- Create a presets menu

## Progress
- initial functions added: gears, DRS, PLL, brake balance, engine braking
- Initial GUI
- Assign and listen to key presses to trigger functions

## Technologies
- C++
- Raspberry Pi
- Qt5

## How to use Qt5

Please follow the instructions from [here](https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code), as it will provide much more details, including [licensing](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5) and tutorials.

For this project, I did this:
1. Downloaded the source code    
   > git clone git://code.qt.io/qt/qt5.git    
   > cd qt5    
   > git checkout 5.12    
   > perl init-repository    
2. Make a build directory
   > cd ../    
   > mkdir qt5-build && cd qt5-build
3. Configure
   > ../qt5/configure -developer-build -opensource -nomake examples -nomake tests
4. Build
   > make -j$(nproc)


## How to run

Clone this repository to your device.

If you are running this on a computer (Windows/macOS/Linux), compile and run with the commands:
   > <path>/qt5-build/qtbase/bin/qmake -project   
   > <path>/qt5-build/qtbase/bin/qmake
  
Add the following line to the bottom of the .pro file:
   > QT += widgets

After making any changes, compile with:
   > make
  

## Controls
I - Ignition    
Q - Gear Up    
P - Gear Down    
N - Neutral    
W - DRS    
O - Pitlane Limiter    
D - Engine Braking (Up)    
C - Engine Braking (Down)    
K - Brake Balance (Forwards)    
M - Brake Balance (Backwards)    
F - Diff (Stiffer)    
V - Diff (Looser)   
Up Arrow - Preset Scroll Up    
Down Arrow - Preset Scroll Down    
B - Select Preset    
All others - Ignition    

The selection may seem non-sensical, however it aims to map roughly to the the locations of buttons on a real steering wheel
