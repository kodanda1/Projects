/**
 * @file MachineActual.cpp
 *
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "MachineActual.h"
#include "Machine1Factory.h"
#include "Machine2Factory.h"


using namespace std;
MachineActual::MachineActual(std::wstring imagesDir)  : mImagesDir(imagesDir)
{
    SetMachineNumber(1);

}
void MachineActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->Draw(graphics);
}
int MachineActual::GetMachineNumber() {

    return mMachineNumber;
}
void MachineActual::SetMachineNumber(int machine) {

    if(machine == 1)
    {
        mMachineNumber = 1;

        Machine1Factory machine1(mImagesDir);

        mMachine = machine1.Create();
        mMachine->SetMachineActual(this);
    }
    else if(machine == 2)
    {
        mMachineNumber = 2;

        Machine2Factory machine2(mImagesDir);
        mMachine = machine2.Create();
        mMachine->SetMachineActual(this);

    }

}

void MachineActual::SetMachineFrame(int frame)
{
    mActualTime = frame / mFrameRate;
    mTime = frame / mFrameRate * mSpeed;
    mMachine->SetTime(GetMachineTime());
    mMachine->Update(mTime);
    mMachine->SetSpeed(mSpeed);
}



