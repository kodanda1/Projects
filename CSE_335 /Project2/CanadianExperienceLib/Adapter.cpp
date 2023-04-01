/**
 * @file Adapter.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include <string>
#include "Adapter.h"
#include "Timeline.h"
#include <machine-api.h>

Adapter::Adapter(const std::wstring &name, const std::wstring imagesDir): Drawable(name)
{
    MachineFactory factory (imagesDir);
    mMachine = factory.CreateMachine();

}

void Adapter::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    int frame = mTimeline->GetCurrentFrame();

    if(frame>= mStartingFrame)
    {
        mMachine->SetMachineFrame(frame - mStartingFrame);

    }
    else
    {
        mMachine->SetMachineFrame(0);
    }

    double scale = 0.55f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
    graphics->Scale(scale, scale);
    mMachine->SetLocation(wxPoint(0,0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();

}

bool Adapter::HitTest(wxPoint pos)
{
    return false;

}

void Adapter::SetTimeline(Timeline *timeline)
{
    Drawable::SetTimeline(timeline);

    mTimeline = timeline;

}



void Adapter::SetMachineNumber(int x)
{
    mMachine->SetMachineNumber(x);

}

int Adapter::GetMachineNumber()
{
    return mMachine->GetMachineNumber();
}

void Adapter::Save(wxXmlNode* root)
{
    int machineNumber = mMachine->GetMachineNumber();

    if(machineNumber == 1)
    {
        root->AddAttribute(L"MachineNumber1", wxString::Format(wxT("%i"), machineNumber));
        root->AddAttribute(L"Frame1", wxString::Format(wxT("%i"), mStartingFrame));

    }



    if(machineNumber == 2)
    {
        root->AddAttribute(L"MachineNumber2", wxString::Format(wxT("%i"), machineNumber));
        root->AddAttribute(L"Frame2", wxString::Format(wxT("%i"), mStartingFrame));
    }



}
void Adapter::Load(wxXmlNode* root) {
    int num = 0;
    int startFrame = 0;

    if (mMachine->GetMachineNumber() == 1) {
        num = wxAtoi(root->GetAttribute(L"MachineNumber1", L"1"));
        startFrame = wxAtoi(root->GetAttribute(L"StartFrame2", L"0"));
    }

    mMachine->SetMachineNumber(num);
    mStartingFrame = startFrame;

}

