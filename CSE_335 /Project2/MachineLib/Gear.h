/**
 * @file Gear.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include <string>
#include "RotationSource.h"
#include "RotationSink.h"

/**
 * Gear class declaration
 */
class Gear : public Component {

private:

    /// Declaration of images directory
    std::wstring mImagesDir;


    /// Declaration of num teeth
    int mNumTeeth =10;



    /// Member variable for Rotation
    double mRotation = 0;


    /// Rotation source for this component
    RotationSource mSource;

    /// Rotation sink for this component
    RotationSink mSink;

    /// Member variable for speed
    double mSpeed = 1;

    /// Member variable for phase
    double mPhase = 0;




public:

    /**
     * Constructor
     * @param radius
     * @param numTeeth
     */
    Gear(double radius, int numTeeth) ;


    ///Destructor

    virtual ~Gear() = default;

    /** Copy constructor disabled */
    Gear(const Gear &) = delete;
    /** Assignment operator disabled */
    void operator=(const Gear &) = delete;


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
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y ) override;

    /**
     * Setter for Rotation
     * @param rotation
     */
    void SetRotation(double rotation) override;


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
     * Drive function
     * @param gear
     * @param phase
     */
    void Drive(std::shared_ptr<Gear> gear, double phase);


    /**
     * SetTime function
     * @param time
     */
    void SetTime(double time)override;




};


#endif //CANADIANEXPERIENCE_GEAR_H
