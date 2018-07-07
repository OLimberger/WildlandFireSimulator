#ifndef WILDLAND_FIRESIM_SIMULATION_H
#define WILDLAND_FIRESIM_SIMULATION_H

#include <iostream>
#include <string>
#include "utility.h"
#include "globals.h"
#include "landscape.h"
#include "fire.h"
#include "firemap.h"

namespace wildland_firesim{
class Simulation
{
public:
    Simulation();

    Month stringToMonth(std::string m);
    /*!
     * \brief runSimulation
     * Function to run the simulation and log output data.
     * \param landscape
     * \param weather
     * \param output
     */
    void runSimulation(ExampleLandscape *landscape, FireWeather weather, FireMap *output);

    int numberOfRuns;
    int maxFireDuration;
    bool simulateFireWeather;
    bool importLandscape;
    bool igniteCentralVertex;
    Month whichMonth;

    int timestepLength;
    float timeScalingFactor;

    std::string nameOfMeteorologicalParameterFile;
    std::string nameOfLandscapeParameterFile;

    Fire fire;
};

}  // namespace wildland_firesim
#endif // WILDLAND_FIRESIM_SIMULATION_H