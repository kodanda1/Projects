/**
 * @file MachineFactory.cpp
 *
 * @author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "pch.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "Polygon.h"
#include "MachineActual.h"
#include "Machine1Factory.h"
using namespace std;

/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
MachineFactory::MachineFactory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}


/**
 * Create a machine object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Machine
 */
std::shared_ptr<Machine> MachineFactory::CreateMachine()
{
    return std::make_shared<MachineActual>(mImagesDir);

    //auto factory = Machine1Factory::CreateMachine();

    //return std::make_shared<MachineActual>();


}




