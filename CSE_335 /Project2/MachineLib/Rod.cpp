/**
 * @file Rod.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "Rod.h"
#include "Component.h"
#include "RodSink.h"


Rod::Rod(double length):Component()
{
    mLength = length;
    Rectangle(0,6,length,6);



    mSink.SetComponent(this);

}
void Rod::Draw(std::shared_ptr<wxGraphicsContext> graphics,int x, int y)
{

    Component::Draw(graphics, x, y);

}
void Rod::SetPosition(wxPoint position) {
    Component::SetPosition(position);

    if(mRodSink != nullptr)
    {
        mRodSink->Negotiate(this);
    }
}

