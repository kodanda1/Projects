/**
 * @file Rod.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H
#include "Component.h"
#include <string>
#include "MovementSource.h"
#include "RotationSource.h"

class RodSink;

/**
 * Rod class initialization
 */
class Rod : public Component {

private:

    /// Member variable position declaration
    wxPoint mPosition = wxPoint(100, 100);

    /// Movement source for this component
    MovementSource mSource;

    /// Movement sink for this component
    MovementSink mSink;


    /// Member variable for Rotation
    double mRotation = 0;

    /// Member variable for length
    double mLength = 0;

    /// Rotation sink for this component
    RotationSink mRotationSink;

    /// Rod sink for this component
    RodSink *mRodSink = nullptr;


public:

    /**
     * Constructor
     * @param length
     */
    Rod(double length) ;

    /** Copy constructor disabled */
    Rod(const Rod &) = delete;
    /** Assignment operator disabled */
    void operator=(const Rod &) = delete;

    /**
     * Draw function declaration
     * @param graphics
     * @param x
     * @param y
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)override;



    /**
     * Getter for movement source
     * @return mSource
     */
    MovementSource *GetSource() { return &mSource; }

    /**
     * Getter for movement sink
     * @return mSink
     */
    MovementSink *GetSink() { return &mSink; }


    /**
     * Getter for Rotation sink
     * @return mRotationSink
     */
    RotationSink *GetRotationsink() { return &mRotationSink; }

    /**
     * Getter for length
     * @return mLength
     */
    double GetLength() {return mLength;}

    /**
     * Setter for position
     * @param position
     */
    void SetPosition(wxPoint position) override;

    /**
     * Setter for rod sink
     * @param rodsink
     */
    void SetRodSink(RodSink *rodsink) {mRodSink = rodsink;}

};


#endif //CANADIANEXPERIENCE_ROD_H
