/**
 * @file Piston.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H
#include <string>
#include "Component.h"
#include "RotationSource.h"
#include "INegotiator.h"
#include "MovementSource.h"
#include "RodSink.h"
#include "Rod.h"

/**
 * Class piston declaration
 */
class Piston : public Component, public INegotiator{
private:

    /// Member variable for position
    wxPoint mPosition = wxPoint(400, 500);

    /// Rotation source for this component
    RotationSource mSource;

    /// Rotation sink for this component
    RotationSink mSink;

    /// Movement source for this component
    MovementSource mMovementSource;



    /// Rod sink for this component
    RodSink mRodSink;




public:

    /**
     * Constructor
     */
    Piston();



    virtual ~Piston() = default;

    /** Copy constructor disabled */
    Piston(const Piston &) = delete;
    /** Assignment operator disabled */
    void operator=(const Piston &) = delete;

    /**
     * Draw Function
     * @param graphics
     * @param x
     * @param y
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)override;



    /**
     * Getter for rod sink
     * @return mRodSink
     */
    RodSink *GetRodSink() {return &mRodSink;}

    /**
     * Negotiate function declaration
     * @param rod
     */
    void Negotiate(Rod *rod) override;
};


#endif //CANADIANEXPERIENCE_PISTON_H
