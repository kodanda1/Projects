/**
* @file Farm.cpp
*
* @author Varuntej Kodandapuram
*/

#include "Farm.h"
/** Add an animal to the farm inventory.
 *
 * @param cow A cow to add to the inventory
 */
void Farm::AddAnimal(Animal *animal)
{
    mInventory.push_back(animal);
}
/**
 * Display the farm inventory.
 */
void Farm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }

}
/**
 * Farm destructor
 */
Farm::~Farm()
{
    // Iterate over all of the animals, destroying
    // each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}
/**
 * count the number of female animals
 * in the inventory.
 * @return count
 */
int Farm::numFemales()
{
    int count = 0;
    for (auto animal: mInventory)
    {
        if (animal->isFemale())
        {
            count++;
        }
    }
    return count;
}
