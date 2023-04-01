/**
 * @file main.cpp
 * @author Charles B. Owen
 *
 * Main entry point for machine demonstrator program
 *
 * Do not modify this file!
 */
#include "pch.h"
#include "MachineDemoBaseApp.h"
#include "MachineIsolator.h"

//<editor-fold desc="MachineDemoApp">
/**
 * MachineDemo main application class.
 * Most of the work is actually done in the base class.
 */
class MachineDemoApp : public MachineDemoBaseApp {
public:
    /**
     * Create the machine isolator, which contains the machine we are displaying.
     * @param imagesDir Directory containing the images for the program
     * @return MachineIsolator object
     */
    std::shared_ptr<IMachineIsolator> CreateMachineIsolator(std::wstring imagesDir) override
    {
        return std::make_shared<MachineIsolator>(imagesDir);
    }

};
//</editor-fold>

wxIMPLEMENT_APP(MachineDemoApp);

