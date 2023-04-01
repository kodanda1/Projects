/**
 * @file MachineFactory.h
 *
 * @author Charles Owen
 *
 * Machine factory class. Creates Machine objects
 *
 * You should not have any reason to change this header file!
 */

#ifndef CANADIANEXPERIENCE_MACHINEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEFACTORY_H

#include <memory>

class Polygon;
class Machine;

/**
 * Machine factory class. Creates Machine objects
 */
class MachineFactory
{
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    MachineFactory(std::wstring imagesDir);

    // Do no change the return type for CreateMachine!
    std::shared_ptr<Machine> CreateMachine();
};

#endif //CANADIANEXPERIENCE_MACHIN0FACTORY_H