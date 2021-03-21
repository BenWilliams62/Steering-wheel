#include <iostream>
#include <string>
#include "Controls.hpp"

// initiate engine
void control::startCar()
{
    gear = 0;
    DRS = false;
    PLL = true;
    BB = 50.0;
    EB = 50.0;
    activePreset = 1;
    optionPreset = 1;
    diffEntry = 1;
    diffMid = 1;
    diffExit = 1;
    
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
        };
    }
    else
    {
        std::cout << "No Gear Change. ";
    };

    std::cout << gear << " selected\n";
};

// toggle DRS
void control::toggleDRS()
{
    if (DRS == true)
    {
        DRS = false;
    }
    else
    {
        DRS = true;
    };
};

// toggle Pitlane limiter
void control::togglePLL()
{
    if (PLL == true)
    {
        PLL = false;
    }
    else
    {
        PLL = true;
    };
};

// set Brake balance - might change to set to number
void control::setBB(std::string direction)
{
    if (direction == "up")
    {
        if (BB < 100)
        {
            BB += 0.1;
        };
    }
    else
    {
        if (BB > 0)
        {
            BB -= 0.1;
        };
    };
};

// set Engine braking - might change to set to number
void control::setEB(std::string direction)
{
    if (direction == "up")
    {
        if (EB < 100)
        {
            EB += 0.1;
        };
    }
    else
    {
        if (EB > 0)
        {
            EB -= 0.1;
        };
    };
};

// scroll throug presets
void control::scrollPreset(int jump)
{
    optionPreset = (optionPreset + jump) % 20;   // assume 20 presets
};

// set preset
void control::setPreset()
{
    activePreset = optionPreset;
};

// set Diff - entry. mihgt change to set to number
void control::setDiffEntry(std::string direction)
{
    if (direction == "up")
    {
        diffEntry = (diffEntry + 1) % 10;  // asume 10 options

    }
    else
    {
        diffEntry = (diffEntry + 9) % 10;
    };
};

// set Diff - entry. mihgt change to set to number
void control::setDiffMid(std::string direction)
{
    if (direction == "up")
    {
        diffMid = (diffMid + 1) % 10;

    }
    else
    {
        diffMid = (diffMid + 9) % 10;
    };
};

// set Diff - entry. mihgt change to set to number
void control::setDiffExit(std::string direction)
{
    if (direction == "up")
    {
        diffExit = (diffExit + 1) % 10;

    }
    else
    {
        diffExit = (diffExit + 9) % 10;
    };
};