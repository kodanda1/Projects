/**
 * @file RotationSink.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "RotationSink.h"

/**
 * Constructor
 */
RotationSink::RotationSink()
{


}
void RotationSink::Rotate(double rotation)
{
    mComponent->SetRotation(rotation);

}


void RotationSink::SetRotation(double rotation)
{
    mComponent->SetRotation(rotation * mSpeed + mPhase);

    //mRotation = rotation * mSpeed + mPhase;
    //GetComponent()->SetRotation(mRotation);
}
