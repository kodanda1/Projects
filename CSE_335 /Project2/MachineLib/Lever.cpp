/**
 * @file Lever.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "Lever.h"
#include "Component.h"



Lever::Lever(double length) :Component(), INegotiator(), mRodSink(this, this)
{
    mLength = length;

    Rectangle((int)(-length/2),(int)((length*0.127)/2), (int)length ,(int)(length*0.127));


}
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{

    Component::Draw(graphics,x,y);

}
void Lever::Negotiate(Rod *rod)
{
    double x2 = GetPosition().x;
    double y2 = GetPosition().y;
    double a = mDriveEnd;

    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;

    double length = rod->GetLength();

    double c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

    double delta = atan2(-(y2-y1), x2 - x1);

    double alpha = acos((length * length + c * c - a * a)/(2 * length * c));

    double theta = delta - alpha;

    const double PI2 =M_PI * 2;

    rod->SetRotation(-theta/PI2);

    double x3 = x1 + length * cos(-theta);
    double y3 = y1 + length * sin(-theta);

    double phi = atan2((y3 - y2), (x3 - x2));

    SetRotation(phi/PI2);

    mSource.RotationSink(phi/PI2);

    double x4 = x2 + -a * cos(phi);
    double y4 = y2 + -a * sin (phi);

    mMovementSource.MovementSink(wxPoint(x4, y4));

}

