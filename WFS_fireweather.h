#ifndef FIREWEATHER_H
#define FIREWEATHER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

#include "globals.h"
#include "cell.h"
#include "csvreader.h"
#include "fire.h"
#include "month.h"
#include "utility.h"

namespace wildland_firesim {

template<typename T>
struct distrParameter {
    T param1;
    T param2;
};

/*!
 * \brief The WindCondition struct
 * contains probabilities for change of wind conditions from windy and calm and to stay calm.
 */
struct WindCondition {
    float windyToCalm;
    float stayCalm;

};

constexpr int WindDirectionsCount = 8;

/*!
 * \brief The FireWeather class
 * containing functions and parameter to simulate fire weather.
 */
class FireWeather
{
public:
    FireWeather();
    /*!
     * \brief importMeteorologicalParameter
     * extracts meteorological parameters from file.
     * \param fileName
     */
    void importMeteorologicalParameter(const std::string &fileName);

    /*!
     * \brief getFixedFireWeatherParameter
     * imports fixed fire weather parameter from file.
     * \param fileName
     */
    static void getFixedFireWeatherParameter(const std::string &fileName, FireWeatherVariables *weather);

    /*!
     * \brief calculateFireWeather
     * simulates hourly fire weather. Temperature is calculated using a model by
     * Cesaraccio et al. (2001). The parameters are received from temperature distribution, while
     * sunset and sunrise times are received from the parameter file. Relative humidity is chosen
     * from a normal distribution. For the simulation of wind, it has to be determined if wind is
     * blowing. It the conditions are windy, wind direction is set according to a certain probability
     * and the wind speed chosen from a Weilbull distribution.
     * \param month
     * \param durationOfBurn
     */
    void calculateFireWeather(int month, int durationOfBurn);

    /*!
     * \brief setStartingTime
     * sets time to start a fire.
     * \param startOfFire
     */
    void setStartingTime(int startOfFire);

    void setWindyConditions(bool windyConditions);

private:
    distrParameter<float> m_minimumDailyTemperatureParameter[NumberOfMonths];
    distrParameter<float> m_maximumDailyTemperatureParameter[NumberOfMonths];
    distrParameter<float> m_relativeHumidityParameter[NumberOfMonths];
    distrParameter<float> m_windSpeedParameter[NumberOfMonths];
    WindCondition m_windConditionChange[NumberOfMonths];
    float m_windDirectionProbability[NumberOfMonths][WindDirectionsCount];
    float m_sunriseTime [NumberOfMonths];
    float m_sunsetTime [NumberOfMonths];
    // Tn: min temperature, Tx: max temperature, Tp: min temperature of following day
    float Tn, Tx, Tp;
    int startingTime; //time for fire weather

    //Meteorological Variables
    bool m_windyConditions;
    float m_windSpeed;
    int m_windDirection;
    float m_relHumidity;
    float m_temperature;
};

} //namespace wildland_firesim

#endif // FIREWEATHER_H
