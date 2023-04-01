/**
 * @file Gear.cpp
 *
 * @author Varuntej Kodandapuram
 */



#include "pch.h"
#include "Gear.h"
const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down
////< PI * 2 constant
const double PI2 = M_PI*2;      ///< PI2 value calculation
Gear::Gear(double radius, int numTeeth)
{


    mSink.SetComponent(this);
    // Where the tooth starts in the arc

    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < numTeeth; t++)
    {
        double angle1 = double(t) / double(numTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(numTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(numTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(numTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(numTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));


    }


}


void Gear::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    //Component::Draw(graphics, GetPosition().x, GetPosition().y);
    Component::Draw(graphics, x,y);
    //DrawPolygon(graphics, mX, mY);


}
void Gear::SetSpeed(double speed)
{
    mSpeed = speed;

}
void Gear::SetRotation(double rotation)
{
    Component::SetRotation(rotation+ mPhase);
    mSource.RotationSink(rotation);
}


void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();
    mSource.AddRotationSink(sink);
    sink->SetSpeed(-(double)mNumTeeth / (double)gear->mNumTeeth);
    sink->SetPhase(phase);
    mSource.RotationSink(mRotation);

}

void Gear::SetTime(double time)
{
    mRotation = mSpeed * time + mPhase;

}






