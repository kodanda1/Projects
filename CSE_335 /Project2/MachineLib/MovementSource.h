/**
 * @file MovementSource.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_MOVEMENTSOURCE_H
#define CANADIANEXPERIENCE_MOVEMENTSOURCE_H
#include "MovementSink.h"

/**
 * Movement source class declaration
 */
class MovementSource {
private:

    /// Vector pointer to member variable movement sink
    std::vector<MovementSink*> mMovementSink;


public:

    /**
     * Constructor
     */
    MovementSource();

    ///Destructor
    virtual ~MovementSource() = default;
    /// Copy Constructor (Disabled)
    MovementSource(const MovementSource &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const MovementSource &) = delete;

    /**
     * Add Movement sink function
     * @param movementsink
     */
    void AddMovementSink(MovementSink* movementsink)
    {
        mMovementSink.push_back(movementsink);
        //rotationsink->SetSource(this);
    };

    /**
     * Movement sink function declaration
     * @param movement
     */
    void MovementSink(wxPoint movement);
};



#endif //CANADIANEXPERIENCE_MOVEMENTSOURCE_H
