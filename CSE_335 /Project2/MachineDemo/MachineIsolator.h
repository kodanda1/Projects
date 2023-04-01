/**
 * @file MachineIsolator.h
 * @author Charles Owen
 *
 * This class makes it possible for MachineDemoLib to be isolated from
 * MachineLib completely, abstracting all machine functionality
 * to this single class, allowing for dependency injection into
 * MachineDemoLib
 *
 * Do not modify this file!
 *
 * Do not try to include this file. It is for MachineDemo use only.
 */

#ifndef MACHINEDEMO_MACHINEISOLATOR_H
#define MACHINEDEMO_MACHINEISOLATOR_H

#include <memory>
#include <IMachineIsolator.h>
#include <machine-api.h>


/**
 * This class makes it possible for MachineDemo to be isolated from
 * MachineLib completely, abstracting all machine functionality
 * to this single class.
 */
class MachineIsolator final : public IMachineIsolator {
private:
    /// The machine we are isolating
    std::shared_ptr<Machine> mMachine;

public:
    /**
     * Constructor
     * @param imagesDir Directory containing the machine images
     */
    explicit MachineIsolator(std::wstring imagesDir)
    {
        //
        // Use the MachineFactory factory to create the machine object
        //
        MachineFactory factory(imagesDir);
        mMachine = factory.CreateMachine();
    }

    /**
     * Set the machine number
     * @param machine New machine number
     */
    void SetMachineNumber(int machine) override
    {
        mMachine->SetMachineNumber(machine);
    }

    /**
     * Get the current machine number
     * @return Machine number
     */
    int GetMachineNumber() override
    {
        return mMachine->GetMachineNumber();
    }

    /**
     * Set the machine location
     * @param location Location of the machine
     */
    void SetLocation(wxPoint location) override
    {
        mMachine->SetLocation(location);
    }

    /**
    * Set the current machine animation frame
    * @param frame Frame number
    */
    void SetMachineFrame(int frame) override
    {
        mMachine->SetMachineFrame(frame);
    }

    /**
     * Set the frame rate
     * @param rate Frame rate in frames per second
     */
    void SetFrameRate(double rate) override
    {
        mMachine->SetFrameRate(rate);
    }

    /**
     * Set the machine speed
     * @param speed Speed from 0 to 1
     */
    void SetSpeed(double speed) override
    {
        mMachine->SetSpeed(speed);
    }

    /**
     * Display the machine selection dialog box
     * @param parent Parent window for the dialog box
     * @return True if OK pressed
     */
    bool DoDialog(wxWindow* parent) override
    {
        MachineDialog dialog(parent, mMachine);
        return (dialog.ShowModal() == wxID_OK);
    }

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override
    {
        mMachine->DrawMachine(graphics);
    }

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    double GetMachineTime() override
    {
        return mMachine->GetMachineTime();
    }

};

#endif //MACHINEDEMO_MACHINEISOLATOR_H
