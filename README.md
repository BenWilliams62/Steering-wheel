# Steering wheel

## Description
This steering wheel project is being built.

The aim of this project is to develop a full functioned f1-style steering wheel, to be put on a raspberry pi. This will not be connected to an f1 car (or any other car) for budget reasons, however if you are building a project and need this program, there will be spaces left to input the necessary code. 

A GUI will be built that will show all settings and allow you to navigate through the menus. 

main.cpp will be the windows/macOS/Linux version, and main.pi.cpp will be the Raspberry Pi version. The differences will be that the Pi version will listen for GPIO commands, and the main version will listen for keyboard keys.

## Aims
- GUI
- Assign and listen to key presses to trigger functions

## Progress
- initial functions added: gears, DRS, PLL, diff, presets, brake balance, engine braking

## Technologies
- C++
- Raspberry Pi
- Qt5

## How to use Qt5

Please follow the instructions from [here] (https://wiki.qt.io/Building_Qt_5_from_Git#Getting_the_source_code), as they will provide much more details, including licensing and tutorials.

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
   > ../configure -developer-build -opensource -nomake examples -nomake tests -confirm-license
4. Build
   > make -j$(nproc)


## How to run

Clone this repository to your device.

If you are running this on a computer (Windows/macOS/Linux), compile and run with the commands:
   > // compile   
   > g++ main.cpp Controls.cpp -o app-name   
   > 
   > // run   
   > ./app-name   

If you are running this on a raspberry pi, compile and run with the commands:
   > // compile    
   > g++ main.pi.cpp Controls.cpp -o app-name
   > 
   > // run    
   > ./app-name    



