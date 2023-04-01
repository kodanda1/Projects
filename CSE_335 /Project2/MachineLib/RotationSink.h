/**
 * @file RotationSink.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

#include "Component.h"

class RotationSource;

/**
 * Rotation sink class initialization
 */
class RotationSink {

private:

    /// Pointer to member variable component
    Component* mComponent;

    /// Member variable of speed declaration
    double mSpeed = 1.0;

    /// Member variable of phase declaration
    double mPhase = 0.0;

    /// Member variable of phase rotation
    double mRotation = 0;

    /// Rotation source for this component


public:

    /**
     * Constructor
     */
    RotationSink();


    ///Destructor

    virtual ~RotationSink() = default;
    /// Copy Constructor (Disabled)
    RotationSink(const RotationSink &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const RotationSink &) = delete;


    /**
     * Rotate function declaration
     * @param rotation
     */
    void Rotate(double rotation);

    /**
     * Setter for component
     * @param component
     */
    void SetComponent(Component* component){mComponent = component;}

    /**
     * Getter for component
     * @return
     */
    Component* GetComponent(){return mComponent;}

    /**
     * Setter for Speed
     * @param speed
     */
    void SetSpeed(double speed) {mSpeed=speed;}

    /**
     * Setter for Phase
     * @param phase
     */
    void SetPhase(double phase) {mPhase=phase;}

    /**
     * Setter for Rotation
     * @param rotation
     */
    void SetRotation(double rotation) ;


};


#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
