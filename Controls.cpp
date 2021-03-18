#include <iostream>
#include <string>
#include <chrono>
#include "Controls.hpp"

// initiate engine
void control::startCar(int g)
{
    if (g <= 8)
    {
        if (g >= 0)
        {
            gear = g;
        };
    };
    // set default time
    time = 0.0;
    bestTime = 0.0;
};

// handle gear change
void control::shift(std::string direction)
{
    if (direction == "up")
    {
        if (gear < 8)
        {
            // handle gear change mechanics
            gear++;
            // handle gear change graphics
        };
    }
    else if (direction == "down")
    {
        if (gear > 0)
        {
            // handle gear change mechanics
            gear--;
            // handle gear change graphics
        };
    }
    else if (direction == "neutral")
    {
        // handle gear change mechanics
        gear = 0;
        // handle gear change graphics
    }
    else if (direction == "reverse")
    {
        if (gear == 0)
        {
            // handle gear change mechanics
            gear = -1;
            // handle gear change graphics
        }
        else
        {
            std::cout << "Go to neutral first. ";
        }
    }
    else
    {
        std::cout << "No Gear Change. ";
    };

    std::cout << gear << " selected\n";
}

// timer function

void control::timer()
{
    if (time == 0.0)
    {
        startTime = std::chrono::high_resolution_clock::now();
        time = 0.1;
    }
    else
    {
        time = (std::chrono::high_resolution_clock::now() - startTime).count();
        startTime = std::chrono::high_resolution_clock::now();
        if (bestTime == 0.0 || time < bestTime)
        {
            bestTime = time;
            std::cout << bestTime << std::endl;  
        };
    };
};


// timer reset
void control::timerReset()
{
    time = 0.0;
    bestTime = 0.0;
}