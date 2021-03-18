# Steering wheel

## Description
This steering wheel project is being built.

The aim of this project is to develop a full functioned f1-style steering wheel, to be put on a raspberry pi. This will not be connected to an f1 car (or any other car) for budget reasons, however if you are building a project and need this program, there will be spaces left to input the necessary code. 

A GUI will be built that will show all settings and allow you to navigate through the menus. 

main.cpp will be the windows/macOS/Linux version, and main.pi.cpp will be the Raspberry Pi version. The differences will be that the Pi version will listen for GPIO commands, and the main version will listen for keyboard keys.

## Technologies
- C++
- Raspberry Pi

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

## Controls

Mac/Windows/Linux:   
u - upshift   
d - downshift   
n - neutral   
r - reverse    
t - timer (times 1 lap, display only the best time)   
c - timer reset   

Raspberry Pi:


