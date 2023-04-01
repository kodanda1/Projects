/**
 * @file Machine.cpp
 * @author Charles Owen
 *
 * You are not allowed to change this class in any way!
 *
 * This is a simple adapter class that routes all of the
 * operations to the class MachineStandin, which is a standin
 * for an actual machine in the system.
 */

#include "pch.h"
#include "Machine.h"
#include "MachineStandin.h"

using namespace std;

Machine::Machine()
{
    mStandin = make_shared<MachineStandin>();
}

void Machine::SetLocation(wxPoint location)
{
    mStandin->SetLocation(location);
}

wxPoint Machine::GetLocation()
{
    return mStandin->GetLocation();
}


void Machine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mStandin->DrawMachine(graphics);
}


void Machine::SetMachineFrame(int frame)
{
    mStandin->SetMachineFrame(frame);
}


void Machine::SetSpeed(double speed)
{
    mStandin->SetSpeed(speed);
}

void Machine::SetFrameRate(double rate)
{

}

void Machine::SetMachineNumber(int seed)
{
    mStandin->SetMachine(seed);
}

int Machine::GetMachineNumber()
{
    return mStandin->GetMachine();
}

double Machine::GetMachineTime()
{
    return 0;
}

