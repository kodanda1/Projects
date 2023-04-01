/**
 * @file Lever.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H


#include <string>
#include "Component.h"
#include "RotationSource.h"
#include "INegotiator.h"
#include "MovementSource.h"
#include "RodSink.h"
#include "Rod.h"

/**
 * Lever class declaration
 */
class Lever : public Component, public INegotiator{

private:

    /// Member variable for position
    wxPoint mPosition = wxPoint(400, 500);

    /// Rotation source for this component
    RotationSource mSource;

    /// Rotation sink for this component
    RotationSink mSink;

    /// Movement source for this component
    MovementSource mMovementSource;

    /// Member variable length
    int mLength;

    /// Member variable Drive end
    double mDriveEnd = 100;

    /// Rod sink for this component
    RodSink mRodSink;




public:
    /**
     * Constructor
     * @param length
     */
    Lever(double length);



    virtual ~Lever() = default;

    /** Copy constructor disabled */
    Lever(const Lever &) = delete;
    /** Assignment operator disabled */
    void operator=(const Lever &) = delete;

    /**
     * Draw Function
     * @param graphics
     * @param x
     * @param y
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)override;

    /**
    * Get a pointer to the source object
    * @return Pointer to RotationSource object
    */
    RotationSource *GetSource() { return &mSource; }


    /**
     * Get a pointer to the sink object
     * @return Pointer to RotationSink object
     */
    RotationSink *GetSink() { return &mSink; }


    /**
     * Get a pointer to the sink object
     * @return Pointer to MovementSink object
     */
    MovementSource *GetMovementSource() { return &mMovementSource; }

    /**
     * Setter for drive end function
     * @param drive
     */
    void SetDriveEnd(double drive) {mDriveEnd = drive;}


    /**
     * Getter for drive end function
     * @return mDriveend
     */
    double GetDriveEnd(){return mDriveEnd;}

    /**
     * Getter for rod sink
     * @return mRodSink
     */
    RodSink *GetRodSink() {return &mRodSink;}


    /**
     * override Negotiate function declaration
     * @param rod
     */
    void Negotiate(Rod *rod) override;
};


#endif //CANADIANEXPERIENCE_LEVER_H
