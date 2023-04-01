
/**
 * @file Farm.h
 *
 * @author Varuntej Kodandapuram
 *
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */
#pragma once
#include <vector>
#include "Cow.h"


#ifndef STEP_1_FARM_H
#define STEP_1_FARM_H

/**
 * Class that describes a farm.
 *
 * Holds a collection of animals that make up the farm
 * inventory.
 */

class Farm {
public:
    void AddAnimal(Animal *animal);
    void DisplayInventory();
    int numFemales();
    ~Farm();


private:
    /// A list with the inventory of all animals on the farm
    std::vector<Animal *> mInventory;


};


#endif //STEP_1_FARM_H
