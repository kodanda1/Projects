/**
 * @file Component.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "Component.h"
#include "Polygon.h"
/**
 * Constructor
 */

Component::Component():Polygon()
{

}



void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics,x+mPosition.x,y+mPosition.y);


}
void Component::SetWorkingMachine(WorkingMachine *workingMachine)
{
    mWorkingMachine = workingMachine;

}
