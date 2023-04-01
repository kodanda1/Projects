/**
 * @file RotationSource.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include <vector>
#include "RotationSink.h"

/**
 * Class rotation source declaration
 */
class RotationSource {
private:

    /**
     * Vector pointer to Rotation sink
     */
    std::vector<RotationSink*> mRotationSink;



public:

    /**
     * Constructor
     */
    RotationSource();


    ///Destructor
    virtual ~RotationSource() = default;
    /// Copy Constructor (Disabled)
    RotationSource(const RotationSource &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const RotationSource &) = delete;

    /**
     * Add rotation sink declaration
     * @param rotationsink
     */
    void AddRotationSink(RotationSink* rotationsink)
    {
        mRotationSink.push_back(rotationsink);
        //rotationsink->SetSource(this);
    };

    /**
     * Rotation sink function
     * @param rotation
     */
    void RotationSink(double rotation);


};


#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
