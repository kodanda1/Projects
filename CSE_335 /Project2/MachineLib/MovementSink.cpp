/**
 * @file MovementSink.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "MovementSink.h"
#include "Component.h"
/**
 * Constructor
 */
MovementSink::MovementSink()
{


}

void MovementSink::SetMovement(wxPoint movement)
{

   mComponent->SetPosition(movement);
}

