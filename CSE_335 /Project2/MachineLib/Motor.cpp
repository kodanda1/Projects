/**
 * @file Motor.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include <string>
#include "Motor.h"


Motor::Motor(std::wstring imagesDir)  : mImagesDir(imagesDir) ,Component()
{
    Rectangle(60,-40,100,100);
    SetImage(imagesDir+L"/motor2.png");

    mShaft.CenteredSquare(40);
    mShaft.SetImage(imagesDir+L"/shaft.png");


}

void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    //Component::Draw(graphics,mPosition.x,mPosition.y);
    Component::Draw(graphics,x,y);

    mShaft.DrawPolygon(graphics,x+110,y-90);
    //mShaft.DrawPolygon(graphics,x+GetPosition().x,y+GetPosition().y);
   // mShaft.SetRotation(mRotation+GetMotorSpeed());

}
void Motor::SetSpeed(double speed)
{
    mSpeed = speed;

}

void Motor::SetTime(double time)
{

    mShaft.SetRotation(mRotation+GetMotorSpeed());
    mRotation = time;
    double rotation = time * mSpeed;
    mSource.RotationSink(rotation);

}



//void Motor::Update()
//{
//    auto rotation = mShaft.GetRotation();
//    rotation = (GetTime()-mStartTime)*mShaftSpeed +GetMotorSpeed();
//    mShaft.SetRotation(rotation);
//}




