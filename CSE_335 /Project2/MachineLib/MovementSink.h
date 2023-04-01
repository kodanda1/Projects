/**
 * @file MovementSink.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_MOVEMENTSINK_H
#define CANADIANEXPERIENCE_MOVEMENTSINK_H

#include "Component.h"

class MovementSource;

/**
 * Movement sink class declaration
 */
class MovementSink {
private:

    /// pointer to member variable componenet
    Component* mComponent;

    /// Member variable speed declaration
    double mSpeed = 1.0;


public:

    /**
     * Constructor
     */
    MovementSink();


    ///Destructor

    virtual ~MovementSink() = default;
    /// Copy Constructor (Disabled)
    MovementSink(const MovementSink &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const MovementSink &) = delete;


    /**
     * Settinng the component
     * @param component
     */
    void SetComponent(Component* component){mComponent = component;}

    /**
     * Getteing the component
     * @return mComponent
     */
    Component* GetComponent(){return mComponent;}

    /**
     * Set speed function declaration
     * @param speed
     */
    void SetSpeed(double speed) {mSpeed=speed;}

    /**
     * Set movement function declaration
     * @param movement
     */
    void SetMovement(wxPoint movement);
};


#endif //CANADIANEXPERIENCE_MOVEMENTSINK_H
