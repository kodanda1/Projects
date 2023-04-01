/**
 * @file Machine2Factory.cpp
 *
 * @author Varuntej Kodandapuram
 */


#include "pch.h"
#include "Machine2Factory.h"
#include "WorkingMachine.h"
#include "Shape.h"
#include "MachineActual.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Lever.h"


using namespace std;
Machine2Factory::Machine2Factory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}
std::shared_ptr<WorkingMachine> Machine2Factory::Create() {
    auto machine2 = make_shared<WorkingMachine>();

    auto base = make_shared<Component>();
    int wid = 550;
    base->Rectangle(-wid / 2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/rust.png");

    machine2->AddComponent(base);


    auto motor = make_shared<Motor>(mImagesDir);
    motor->SetImage(mImagesDir + L"/motor-frame.png");
    motor->SetPosition (wxPoint(200, -38));
    motor->SetSpeed(1.0);
    machine2->AddComponent(motor);

    auto motor2 = make_shared<Shape>();
    motor2->Rectangle(-160, -40, 90, 60);
    motor2->SetColor(wxColour(0,0,0));
    machine2->AddComponent(motor2);


    auto gear1 = make_shared<Gear>(40, 20);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetColor(wxColour(0,0,0));
    gear1->SetPosition(wxPoint(110, -38 -  100/ 2));
    machine2->AddComponent(gear1);

    motor->GetSource()->AddRotationSink(gear1->GetSink());


    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetColor(wxColour(204,0,0));
    gear2->SetPosition(wxPoint(gear1->GetPosition().x -20, gear1->GetPosition().y-70));
    machine2->AddComponent(gear2);
    gear1->Drive(gear2, 0.1);

    auto gear3 = make_shared<Gear>(40, 20);
    gear3->SetImage(mImagesDir + L"/hammered-copper.png");
    gear3->SetColor(wxColour(255,255,0));
    gear3->SetPosition(wxPoint(gear1->GetPosition().x -40, gear1->GetPosition().y-140));

    machine2->AddComponent(gear3);
    gear1->Drive(gear3, 0.1);

    auto gear4 = make_shared<Gear>(40, 20);
    gear4->SetImage(mImagesDir + L"/hammered-copper.png");
    gear4->SetColor(wxColour(0,51,102));
    gear4->SetPosition(wxPoint(gear1->GetPosition().x -70, gear1->GetPosition().y-210));
    machine2->AddComponent(gear4);
    gear3->Drive(gear4, 0.1);

    auto gear5 = make_shared<Gear>(40, 20);
    gear5->SetImage(mImagesDir + L"/hammered-copper.png");
    gear5->SetColor(wxColour(0,102,0));
    gear5->SetPosition(wxPoint(gear1->GetPosition().x -225, gear1->GetPosition().y-10));
    machine2->AddComponent(gear5);
    motor->GetSource()->AddRotationSink(gear5->GetSink());

    auto gear6 = make_shared<Gear>(40, 20);
    gear6->SetImage(mImagesDir + L"/hammered-copper.png");
    gear6->SetColor(wxColour(102,0,204));
    gear6->SetPosition(wxPoint(gear1->GetPosition().x -200, gear1->GetPosition().y-80));
    machine2->AddComponent(gear6);
    gear5->Drive(gear6, 0.1);

    auto gear7 = make_shared<Gear>(40, 20);
    gear7->SetImage(mImagesDir + L"/hammered-copper.png");
    gear7->SetColor(wxColour(255,178,102));
    gear7->SetPosition(wxPoint(gear1->GetPosition().x -175, gear1->GetPosition().y-150));
    machine2->AddComponent(gear7);
    gear6->Drive(gear7, 0.1);

    auto gear8 = make_shared<Gear>(40, 20);
    gear8->SetImage(mImagesDir + L"/hammered-copper.png");
    gear8->SetColor(wxColour(0,255,255));
    gear8->SetPosition(wxPoint(gear1->GetPosition().x -150, gear1->GetPosition().y-215));
    machine2->AddComponent(gear8);
    gear7->Drive(gear8, 0.1);

    auto gear9 = make_shared<Gear>(40, 20);
    gear9->SetImage(mImagesDir + L"/hammered-copper.png");
    gear9->SetColor(wxColour(255,204,204));
    gear9->SetPosition(wxPoint(gear1->GetPosition().x -105, gear1->GetPosition().y-280));
    machine2->AddComponent(gear9);
    motor->GetSource()->AddRotationSink(gear9->GetSink());

    auto gear10 = make_shared<Gear>(40, 20);
    gear10->SetImage(mImagesDir + L"/hammered-copper.png");
    gear10->SetColor(wxColour(229,255,204));
    gear10->SetPosition(wxPoint(gear1->GetPosition().x -150, gear1->GetPosition().y-5));
    machine2->AddComponent(gear10);
    gear5->Drive(gear10, 0.1);

    auto gear11 = make_shared<Gear>(40, 20);
    gear11->SetImage(mImagesDir + L"/hammered-copper.png");
    gear11->SetColor(wxColour(51,25,0));
    gear11->SetPosition(wxPoint(gear1->GetPosition().x -75, gear1->GetPosition().y-5));
    machine2->AddComponent(gear11);
    gear1->Drive(gear11, 0.1);

    auto gear12 = make_shared<Gear>(30, 15);
    gear12->SetImage(mImagesDir + L"/hammered-copper.png");
    //gear1->SetColor(wxColour(0,0,0));
    gear12->SetPosition(wxPoint(gear1->GetPosition().x -110, gear1->GetPosition().y-100));
    machine2->AddComponent(gear12);
    motor->GetSource()->AddRotationSink(gear12->GetSink());



    return machine2;

}

