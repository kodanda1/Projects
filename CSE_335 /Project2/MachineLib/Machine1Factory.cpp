/**
 * @file Machine1Factory.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "Machine1Factory.h"
#include "WorkingMachine.h"
#include "Shape.h"
#include "MachineActual.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Lever.h"
#include "Rod.h"
#include "Component.h"
#include "Piston.h"
using namespace std;
Machine1Factory::Machine1Factory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}
std::shared_ptr<WorkingMachine> Machine1Factory::Create() {
    //auto factory = std::make_shared<WorkingMachine>(1);
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<WorkingMachine>();

    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid / 2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");


    machine->AddComponent(base);

    // The motor
    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetPosition (wxPoint(100, -38));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(wxPoint(110, -89));
    machine->AddComponent(gear1);

    motor->GetSource()->AddRotationSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Component>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(wxPoint(170, -40));
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(wxPoint(gear1->GetPosition().x + 55, gear1->GetPosition().y));
    machine->AddComponent(gear2);

    gear1->Drive(gear2, 0.1);


    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(60);
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->SetPosition(gear2->GetPosition());
    machine->AddComponent(arm);

    gear2->GetSource()->AddRotationSink(arm->GetSink());


    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-30, -40, 40, 220);
    column->SetImage(mImagesDir + L"/column.png");


    // The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(wxPoint(-5, -232));
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddComponent(lever);


    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition());
    flag->SetPosition(wxPoint(-10,-250));
    machine->AddComponent(flag);
    lever->GetSource()->AddRotationSink(flag->GetSink());

    // Column is added after the lever so it is in front
    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(150);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    rod1->SetPosition(arm->GetPosition());
    machine->AddComponent(rod1);
    arm->GetSource()->AddMovementSink(rod1->GetSink());
    rod1->SetRodSink(lever->GetRodSink());


    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(50);

    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetMovementSource()->AddMovementSink(rod2->GetSink());

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Piston>();
    double pistonH = 70;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(mImagesDir + L"/piston.png");
    piston->SetPosition(wxPoint(-175, -150));
    machine->AddComponent(piston);
    rod2->SetRodSink(piston->GetRodSink());

    machine->AddComponent(rod2);

    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(wxPoint(-175, -38));
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);


    return machine;
}
