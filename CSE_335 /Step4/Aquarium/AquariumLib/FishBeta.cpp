/**
 * @file FishBeta.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "ids.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include "Item.h"
#include "Fish.h"

using namespace std;
/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
    this -> setSpeedx(200);
    this -> setSpeedy(100);

}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */

wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"beta");
    //itemNode->AddAttribute(L"speedX", GetSpeedX());
    //itemNode->AddAttribute(L"speedY", GetSpeedY());

    return itemNode;
}
