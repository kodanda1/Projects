/**
 * @file RodSink.h
 * @author Varuntej Kodandapuram
 */

#pragma once

#include <memory>
#include "MovementSink.h"
#include "INegotiator.h"
#include "RotationSink.h"

class Rod;

/**
 * Class RodSink declartion derived from movement sink and rotation sink
 */
class RodSink{
private:
    /// Pointer to mNegotiator
    INegotiator* mNegotiator = nullptr;

    /// Pointer to mRod
    Rod *mRod = nullptr;

public:
    /**
     * Constructor
     * @param component
     * @param negotiator
     */

    RodSink(Component* component, INegotiator* negotiator);

    ///Destructor
    virtual ~RodSink() = default;

    /** Copy constructor disabled */
    RodSink(const RodSink &) = delete;
    /** Assignment operator disabled */
    void operator=(const RodSink &) = delete;

    /**
     * Negotiate function declaration
     * @param rod
     */
    void Negotiate(Rod *rod);

    /**
     * Getter for mRod
     * @return mRod
     */
    Rod* GetRod() {return mRod;}

};



