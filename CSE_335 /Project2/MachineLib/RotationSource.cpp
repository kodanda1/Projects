/**
 * @file RotationSource.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "RotationSource.h"
#include "RotationSink.h"

/**
 * Constructor
 */
RotationSource::RotationSource()
{

}

void RotationSource::RotationSink(double rotation)
{
    for (auto rotationsink : mRotationSink)
    {
       rotationsink->SetRotation(rotation);

    }

}