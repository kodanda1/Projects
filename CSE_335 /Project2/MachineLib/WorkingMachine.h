/**
 * @file WorkingMachine.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_WORKINGMACHINE_H
#define CANADIANEXPERIENCE_WORKINGMACHINE_H
#include "Component.h"

class MachineActual;

/**
 * Working machine class declaration
 */
class WorkingMachine  {
private:

    /**
     * Vector shared pointer to components
     */
    std::vector<std::shared_ptr<Component>>mComponents;

    /// Pointer to member variable machine actual
    MachineActual *mMachineActual = nullptr;

    /// Pointer to member variable working machine
    WorkingMachine *mWorkingMachine = nullptr;

    /// Member variable for time
    double mTime;

    /// Member variable for speed
    double mSpeed;

    /// Member variable for location
    wxPoint mLocation;


public:

    /**
     * Constructor
     */
    WorkingMachine();


    ///Destructor

    virtual ~WorkingMachine() = default;

    /** Copy constructor disabled */
    WorkingMachine(const WorkingMachine &) = delete;
    /** Assignment operator disabled */
    void operator=(const WorkingMachine &) = delete;

    /**
     * Add component function
     * @param component
     */
    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Draw function
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Set machine actual function declaration
     * @param machineActual
     */
    void SetMachineActual(MachineActual *machineActual) {mMachineActual =machineActual;}

    /**
     * Set time function
     * @param time
     */
    virtual void SetTime(double time) { mTime = time; }

    /**
     * Update function declaration
     * @param Time
     */
    void Update(double Time);

    /**
     * Setter for speed
     * @param speed
     */
    void SetSpeed(double speed) {mSpeed=speed;}

    /**
     * Setter for location
     * @param location
     */
    void SetLocation(wxPoint location) {mLocation= location;}

    /**
     * Getter for location
     * @return
     */
    wxPoint GetLocation() {return mLocation;}

};


#endif //CANADIANEXPERIENCE_WORKINGMACHINE_H
