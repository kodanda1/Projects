/**
 * @file Arm.cpp
 *
 * @author Varuntej Kodandapuram
 */
#include "pch.h"
#include "Arm.h"
#include "Component.h"

Arm::Arm(double armLength):mArmLength(armLength)
{

    Rectangle(-5, 8, mArmLength, int(0.25*mArmLength));
    mSink.SetComponent(this);


}


void Arm::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    double x = GetPosition().x + (mArmLength-20) * cos(GetRotation() * M_PI * 2);
    double y = GetPosition().y + (mArmLength-25) * sin(GetRotation() * M_PI * 2);
    mSource.MovementSink(wxPoint(x,y));

}

