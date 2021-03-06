#ifndef WILDLAND_FIRESIM_CELL_H
#define WILDLAND_FIRESIM_CELL_H

#include "globals.h"

namespace wildland_firesim {

/*!
 * \brief The Cell class
 * holds the vegetation parameters and the cell state.
 */
class Cell
{
public:
    VegetationType type;
    float deadBiomass;
    float liveBiomass;

    CellState state;
};

}  // namespace wildland_firesim

#endif // WILDLAND_FIRESIM_CELL_H
