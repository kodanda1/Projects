/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "Adapter.h"
#include <machine-api.h>

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 520));
    picture->AddActor(sparty);


    auto machine1 = make_shared<Actor>(L"Machine1");
    machine1->SetClickable(false);
    machine1->SetPosition(wxPoint(1000,600));

    auto adapter1 =
            make_shared<Adapter>(L"Machine1",imagesDir);
    adapter1->SetMachineNumber(1);
    adapter1->SetStart(10);
    machine1->AddDrawable(adapter1);
    machine1->SetRoot(adapter1);


    //picture->AddActor(machine1);

    auto machine2 = make_shared<Actor>(L"Machine2");
    machine2->SetClickable(false);
    machine2->SetPosition(wxPoint(1000, 370));

    auto adapter2 =
            make_shared<Adapter>(L"Machine2", imagesDir);
    adapter2->SetMachineNumber(2);
    adapter2->SetStart(40);
    machine2->AddDrawable(adapter2);
    machine2->SetRoot(adapter2);
    //picture->AddActor(machine2);

    picture->SetMachines(adapter1,adapter2);
    picture->AddActor(machine1);
    picture->AddActor(machine2);



    return picture;
}

