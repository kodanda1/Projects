/**
 * @file MovementSource.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "MovementSource.h"
#include "MovementSink.h"


/**
 * Constructor
 */
MovementSource::MovementSource()
{

}

void MovementSource::MovementSink(wxPoint movement)
{
    for (auto movementsink : mMovementSink)
    {
        movementsink->SetMovement(movement);

    }

}