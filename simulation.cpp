#include "simulation.h"

namespace wildland_firesim {

Simulation::Simulation()
{

}

void
Simulation::runSimulation(ExampleLandscape *landscape, FireWeather weather, FireMap *output)
{
    //starting conditions
    int numberOfTimesteps = 1;
    float durationOfBurn = 0.0;
    float nextHour = 1.0;

    //weather conditions at begin of fire
    weather.windyConditions = true; //at start of the fire there is wind
    if(simulateFireWeather){
        weather.setStartingTime(12);
        weather.calculateFireWeather(whichMonth, 0);
        output->weatherData.push_back(output->storeWeatherData(weather, durationOfBurn));
    }

    //igniting the fire
    if(igniteCentralVertex){
        fire.setCenteredIgnitionPoint(landscape);
    } else {
        fire.initiateWildFire(landscape, weather);
    }

    //simulate fire spread
    while((fire.numberOfCellsBurning != 0) && (numberOfTimesteps < maxFireDuration)){
        if(simulateFireWeather && durationOfBurn >= nextHour){
            weather.calculateFireWeather(whichMonth, static_cast<int>(std::floor(durationOfBurn)));
            output->weatherData.push_back(output->storeWeatherData(weather, durationOfBurn));
            nextHour = std::floor(durationOfBurn+1);
        }
        fire.spreadFire(landscape, weather, timestepLength);
        durationOfBurn = (numberOfTimesteps * timestepLength)/(60.f*60.f);
        numberOfTimesteps++;
    }
}


Month
Simulation::stringToMonth(std::string m){
    std::vector<std::string> abrMonth{
        {"JAN"}, {"FEB"}, {"MAR"}, {"APR"}, {"MAY"}, {"JUN"},
        {"JUL"}, {"AUG"}, {"SEP"}, {"OCT"}, {"NOV"}, {"DEC"}
    };
    std::vector<Month> enumMonth{
        {Month::January}, {Month::February}, {Month::March}, {Month::April}, {Month::May}, {Month::June},
        {Month::June}, {Month::July}, {Month::September}, {Month::October}, {Month::November}, {Month::December},
    };
    Month month;
    for(size_t i = 0; i<abrMonth.size(); i++){
        if(m == abrMonth[i]){
            month = enumMonth[i];
        }
    }
    return month;
}

}  // namespace wildland_firesim