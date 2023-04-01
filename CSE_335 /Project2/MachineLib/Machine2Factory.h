/**
 * @file Machine2Factory.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINE2FACTORY_H

#include <memory>
#include "RotationSource.h"
class Polygon;
class MachineActual;
class WorkingMachine;

/**
 * Machine2Factory class declaration
 */
class Machine2Factory {
private:
    /// The images directory
    std::wstring mImagesDir;

    /// Rotation source for this component
    RotationSource mSource;

public:

    /**
     * Constructor
     * @param imagesDir
     */
    Machine2Factory(std::wstring imagesDir);

    /**
     * Shared pointer to working machine
     * @return machine
     */
    std::shared_ptr<WorkingMachine> Create();


    /// Get a pointer to the source object
    /// \return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }


};


#endif //CANADIANEXPERIENCE_MACHINE2FACTORY_H
