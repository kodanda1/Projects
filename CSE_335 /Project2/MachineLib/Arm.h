/**
 * @file Arm.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H
#include "Component.h"
#include <string>
#include "MovementSource.h"
#include "RotationSource.h"

/**
 * Arm class declaration
 */
class Arm : public Component {

private:

    /// Member variable for position
    wxPoint mPosition = wxPoint(100, 100);

    /// Rotation source for this component
    MovementSource mSource;

    /// Rotation sink for this component
    RotationSink mSink;

    /// Member variable for speed
    double mSpeed = 1;


    /// Member variable for Rotation
    double mRotation = 0;

    /// Member variable for arm length
    int mArmLength;


public:
    /**
     * Constructor
     * @param armLength
     */
    Arm(double armLength); ;

    /** Copy constructor disabled */
    Arm(const Arm &) = delete;
    /** Assignment operator disabled */
    void operator=(const Arm &) = delete;


    /**
     * Get a pointer to the source object
     * @return Pointer to RotationSource object
     */
    MovementSource *GetSource() { return &mSource; }

    /**
     * Get a pointer to the sink object
     * @return Pointer to Rotationink object
     */
    RotationSink *GetSink() { return &mSink; }

    /// update function declaration
    //void Update();

    /**
     * Set rotation function declaration
     * @param rotation
     */
    void SetRotation(double rotation) override;


};


#endif //CANADIANEXPERIENCE_ARM_H
