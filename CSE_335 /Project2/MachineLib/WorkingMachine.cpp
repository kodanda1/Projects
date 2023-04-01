/**
 * @file WorkingMachine.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "WorkingMachine.h"
#include "Component.h"
#include "Motor.h"
#include "MachineActual.h"

WorkingMachine::WorkingMachine()
{

}


void WorkingMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto components : mComponents)
    {
        components->Draw(graphics,GetLocation().x,GetLocation().y);
    }
}
void WorkingMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetWorkingMachine(this);
}
void WorkingMachine::Update(double Time)
{
    for(auto component : mComponents){
        mTime = Time;
        component->SetTime(Time);
    }


}

