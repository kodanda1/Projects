/**
 * @file Machine1Factory.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINE1FACTORY_H

#include <memory>


class WorkingMachine;

/**
 * Machine1Factory class declaration
 */
class Machine1Factory {

private:
    /// The images directory
    std::wstring mImagesDir;

public:

    /**
     * Constructor
     * @param imagesDir
     */
    Machine1Factory(std::wstring imagesDir);


    /**
     * Shared pointer to working machine
     * @return machine
     */
    std::shared_ptr<WorkingMachine> Create();





};


#endif //CANADIANEXPERIENCE_MACHINE1FACTORY_H
