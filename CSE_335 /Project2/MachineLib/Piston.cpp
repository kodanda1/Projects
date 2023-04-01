/**
 * @file Piston.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "Piston.h"
#include "Component.h"

Piston::Piston():Component(), mRodSink(this,this)
{


    //Rectangle(270,590,5,175);

    mSink.SetComponent(this);

}
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y)
{

    Component::Draw(graphics, x, y);

}
void Piston::Negotiate(Rod *rod)
{
    double x1 = rod->GetPosition().x;
    double y1 = rod->GetPosition().y;

    double x2 = GetPosition().x;
    double length = rod->GetLength();

    double alpha = asin((x2 - x1)/length);
    double beta = M_PI / 2 - alpha;
    rod->SetRotation(beta / (M_PI * 2));

    double y2 = y1 + length * cos(alpha);
    SetPosition(wxPoint(int(x2),int (y2)));

}