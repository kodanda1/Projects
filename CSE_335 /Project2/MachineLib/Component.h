/**
 * @file Component.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H
#include "Polygon.h"

class WorkingMachine;
/**
 * Component class declaration
 */
class Component : public Polygon{

private:


    /// Get a pointer to the WorkingMachine object
    WorkingMachine* mWorkingMachine = nullptr;

    /// The underlying image we are drawing
    //std::unique_ptr<wxImage> mImage;

    /// member variable for position
    wxPoint mPosition ;

    /// member variable for time
    double mTime ;

    /// member variable for motor speed
    double mMotorSpeed = 0;





public:

    /**
     * Constructor
     */
    Component();


    ///Destructor

    virtual ~Component() = default;
    /// Copy Constructor (Disabled)
    Component(const Component &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Component &) = delete;

    /**
     * Declaration of set working machine
     * @param workingMachine
     */
    void SetWorkingMachine(WorkingMachine* workingMachine);

    /**
     * Declaration of Draw function which draws our components
     * @param graphics
     * @param x
     * @param y
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Setter for mPosition
     * @param position
     */
    virtual void SetPosition( wxPoint position){mPosition = position;}

    /**
     * Getter for mPosition
     * @return mPosition
     */
    wxPoint GetPosition(){return mPosition;}

    /**
     * Getter for mTime
     * @return mTime
     */
    double GetTime(){return mTime;}

    /**
     * Getter for Motor speed
     * @return mMotorSpeed
     */
    double GetMotorSpeed(){return mMotorSpeed;}

    /**
     * Declaration of virtual Set time function
     * @param time
     */
    virtual void SetTime(double time) { mTime = time; }



};


#endif //CANADIANEXPERIENCE_COMPONENT_H
