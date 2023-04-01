/**
 * @file Motor.h
 *
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H
#include "Component.h"
#include <string>
#include "RotationSource.h"

/**
 * Motor class declaration
 */
class Motor:public Component {

private:


    /// Member variable for shaft
    Polygon mShaft;


    /// Declaration of images directory
    std::wstring mImagesDir;

    /// Member variable for Position
    wxPoint mPosition = wxPoint(0, 0);

    /// Member variable for Speed
    double mSpeed;


    /// Member variable for Rotation
    double mRotation;

    /// Member variable for Time
    double mTime;

    /// Rotation source for this component
    RotationSource mSource;


    /// Rotation sink for this component
    RotationSink mSink;




public:

    /**
     * Constructor
     * @param imagesDir
     */
    Motor(std::wstring imagesDir);

    ///Destructor
    virtual ~Motor() = default;

    /** Copy constructor disabled */
    Motor(const Motor &) = delete;
    /** Assignment operator disabled */
    void operator=(const Motor &) = delete;



    /**
     * Set Speed function
     * @param speed
     */
    void SetSpeed(double speed);


    /**
     * Draw function
     * @param graphics
     * @param x
     * @param y
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;


    /**
     * Setter for position
     * @param position
     */
    void SetPosition( wxPoint position)override{mPosition = position;}


    /**
     * Set time override function
     * @param time
     */
    void SetTime(double time)override;



    /**
     * Get a pointer to the source object
     * @return Pointer to RotationSource object
     */
    RotationSource *GetSource() { return &mSource; }


};


#endif //CANADIANEXPERIENCE_MOTOR_H
