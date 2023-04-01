/**
 * @file FishNemo.cpp
 * @author Varuntej Kodandapuram
 */
#include "FishNemo.h"
#include "pch.h"
#include "ids.h"
#include "Aquarium.h"

using namespace std;
/// Fish filename
const wstring FishNemoImageName = L"images/nemo.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishNemo::FishNemo(Aquarium *aquarium) : Fish(aquarium, FishNemoImageName)
{
    this -> setSpeedx(200);
    this -> setSpeedy(200);
}
/**
* Save this fish to an XML node
* @param node The parent node we are going to be a child of
* @return
*/
wxXmlNode* FishNemo::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"nemo");
    return itemNode;
}


