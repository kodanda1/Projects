/**
 * @file MachineActual.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_MACHINEACTUAL_H
#define CANADIANEXPERIENCE_MACHINEACTUAL_H
#include "Machine.h"
#include "WorkingMachine.h"
#include "Component.h"

/**
 * Machine actual class declaration
 */
class MachineActual: public Machine{
private:

    /// Member variable for machine
    std::shared_ptr<WorkingMachine> mMachine = nullptr;

    /// Member variable for images directory
    std::wstring mImagesDir;

    /// Member variable for machine number
    int mMachineNumber;

    /// Member variable for frame rate
    double mFrameRate = 30;

    /// Member variable for time
    double mTime = 0;

    /// Member variable for speed
    double mSpeed = 3;

    /// Member variable for actual time
    double mActualTime = 0;


public:
    /**
     * Constructor
     * @param imagesDir
     */

    MachineActual(std::wstring imagesDir);

    /// Destructor
    virtual ~MachineActual() = default;

    /// Copy constructor/disabled
    MachineActual(const MachineActual&) = delete;

    /// Assignment operator/disabled
    void operator=(const MachineActual&) = delete;


    /**
     * Draw function declaration
     * @param graphics
     */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * set machine number override function declaration
     * @param machine
     */
    void SetMachineNumber(int machine)override;

    /**
     * get machine number override function declaration
     * @return machine number
     */
    int GetMachineNumber()override;

    /**
     * set machine frame override function declaration
     * @param frame
     */
    void SetMachineFrame(int frame)override;

    /**
     * set speed function declaration
     * @param speed
     */
    void SetSpeed(double speed) override{mSpeed=speed;}

    /**
     * Get machine time function declaration
     * @return actual time
     */
    double GetMachineTime()override{return mActualTime;}

    /**
     * Set Location overide function declaration
     * @param location
     */
    void SetLocation(wxPoint location) override {mMachine->SetLocation(location);}

    /**
     * Get Location overide function declaration
     * @return
     */
    wxPoint GetLocation() override {return mMachine->GetLocation();}

   // void Update(double time);
};


#endif //CANADIANEXPERIENCE_MACHINEACTUAL_H
