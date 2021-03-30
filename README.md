# Steering wheel

## Description
A very simple GUI app in C++ using Qt5. The goal is to create a steering wheel display similar to those used in F1, with keystrokes triggering functions such as gear changes, diff control or brake balance.

As I have no plans to implement this in a go kart or such, there has been no attempt to implement the necessary motor movements that would be required to actually change a diff setting or a gear, however there is space left if this changes.

On screen buttons were used in development, so I have left them in the source code, but commented out such that they can be added again if needed for further development.

## Functions Built
- initial functions added: gears, DRS, PLL, brake balance, engine braking
- Initial GUI
- Assign and listen to key presses to trigger functions

## Technologies
- C++
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
