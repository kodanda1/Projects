/**
 * @file VickyFactory.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "VickyFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
/**
 * This is a factory method that creates our Harold actor.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> VickyFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Actor> actor = make_shared<Actor>(L"Vicky");

    auto dress = make_shared<ImageDrawable>(L"Dress", imagesDir + L"/vicky_dress.png");
    dress->SetCenter(wxPoint(44, 168));
    dress->SetPosition(wxPoint(0, -114));
    actor->SetRoot(dress);


    auto leftleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/vicky_lleg.png");
    leftleg->SetCenter(wxPoint(11, 9));
    leftleg->SetPosition(wxPoint(27, 0));
    dress->AddChild(leftleg);

    auto rightleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/vicky_rleg.png");
    rightleg->SetCenter(wxPoint(39, 9));
    rightleg->SetPosition(wxPoint(-27, 0));
    dress->AddChild(rightleg);

    auto headb2 = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/vicky_headb2.png");
    headb2->SetCenter(wxPoint(44, 31));
    headb2->SetPosition(wxPoint(5, -170));
    dress->AddChild(headb2);

    auto headt2 = make_shared<HeadTop>(L"Head Top", imagesDir + L"/vicky_headt2.png");
    headt2->SetCenter(wxPoint(55, 109));
    headt2->SetPosition(wxPoint(5, -28));
    headb2->AddChild(headt2);


    auto larm = make_shared<PolyDrawable>(L"Left Arm");
    larm->SetColor(wxColour(178, 255, 102));
    larm->SetPosition(wxPoint(50, -160));
    larm->AddPoint(wxPoint(-7, -7));
    larm->AddPoint(wxPoint(-7, 96));
    larm->AddPoint(wxPoint(8, 96));
    larm->AddPoint(wxPoint(8, -7));
    dress->AddChild(larm);

    auto rarm = make_shared<PolyDrawable>(L"Right Arm");
    rarm->SetColor(wxColour(178, 255, 102));
    rarm->SetPosition(wxPoint(-45, -160));
    rarm->AddPoint(wxPoint(-7, -7));
    rarm->AddPoint(wxPoint(-7, 96));
    rarm->AddPoint(wxPoint(8, 96));
    rarm->AddPoint(wxPoint(8, -7));
    dress->AddChild(rarm);

    auto lhand = make_shared<PolyDrawable>(L"Left Hand");
    lhand->SetColor(wxColour(253, 218, 180));
    lhand->SetPosition(wxPoint(0, 96));
    lhand->AddPoint(wxPoint(-12, -2));
    lhand->AddPoint(wxPoint(-12, 17));
    lhand->AddPoint(wxPoint(11, 17));
    lhand->AddPoint(wxPoint(11, -2));
    larm->AddChild(lhand);

    auto rhand = make_shared<PolyDrawable>(L"Right Hand");
    rhand->SetColor(wxColour(253, 218, 180));
    rhand->SetPosition(wxPoint(0, 96));
    rhand->AddPoint(wxPoint(-12, -2));
    rhand->AddPoint(wxPoint(-12, 17));
    rhand->AddPoint(wxPoint(11, 17));
    rhand->AddPoint(wxPoint(11, -2));
    rarm->AddChild(rhand);

    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rhand);
    actor->AddDrawable(lhand);
    actor->AddDrawable(rightleg);
    actor->AddDrawable(leftleg);
    actor->AddDrawable(dress);
    actor->AddDrawable(headb2);
    actor->AddDrawable(headt2);

    return actor;
}
