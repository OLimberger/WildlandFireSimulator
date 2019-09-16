#ifndef FIREMAP_H
#define FIREMAP_H

#include "globals.h"
#include "cell.h"
#include "fire.h"

namespace wildland_firesim {

/*!
 * \brief The FireMap class
 * contains function to define the output of the model.
 */
class Output
{
public:
    Output();
    /*!
     * \brief writeBurnMapToASCII
     * Function to write cell states into an ascii-grid.
     * \param landscape
     * \param fileName
     */
    static void writeBurnMapToASCII(const LandscapeInterface &landscape, const std::string &fileName);
    /*!
     * \brief writeVegetationMapToASCII
     * Function to write vegetation types into an ascii-grid.
     * \param landscape
     * \param fileName
     */
    static void writeVegetationMapToASCII(const LandscapeInterface &landscape, const std::string &fileName);
    /*!
     * \brief writeVegetationDataToCSV
     * Function to write vegetation parameters into a csv-Table
     * \param landscape
     * \param fileName
     */
    static void writeVegetationDataToCSV(const LandscapeInterface &landscape, const std::string &fileName);
    /*!
     * \brief writeFireWeatherDataToCSV
     * Function to write weather data into a csv-Table
     * \param landscape
     * \param fileName
     */
    void writeFireWeatherDataToCSV(const std::string &fileName);

    /*!
     * \brief writeBurnDataToCSV
     * \param landscape
     * \param fileName
     */
    static void writeBurnDataToCSV(const LandscapeInterface &landscape, const Fire &fire, const std::string &fileName);
    /*!
     * \brief setfileName
     * Function to generate file names.
     * \param baseName
     * \param extention
     * \param i
     * \return
     */
    static std::string createFilename(const std::string &baseName, const std::string &extention, int i);
    /*!
     * \brief storeWeatherData
     * Function to extract weather data at a certain time.
     * \param weather
     * \param durationOfBurn
     * \return
     */
    std::string storeWeatherData(const FireWeatherVariables &weather, float durationOfBurn);

    void addWeatherData(const std::string &line);
    void clearWeatherData();

private:
    std::vector<std::string> m_weatherData;
};

} //namespace wildland_firesim
#endif // FIREMAP_H
