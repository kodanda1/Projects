/**
 * @file FishAngler.cpp
 * @author Varuntej Kodandapuram
 */
#include "FishAngler.h"
#include "pch.h"
#include "ids.h"
#include "Aquarium.h"

using namespace std;
/// Fish filename
const wstring FishAnglerImageName = L"images/angler.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishAngler::FishAngler(Aquarium *aquarium) : Fish(aquarium, FishAnglerImageName)
{
    this -> setSpeedx(70);
    this -> setSpeedy(90);
}
/**
* Save this fish to an XML node
* @param node The parent node we are going to be a child of
* @return
*/
wxXmlNode* FishAngler::XmlSave(wxXmlNode* node)
{
    auto itemNode = Fish::XmlSave(node);
    itemNode->AddAttribute(L"type", L"angler");
    return itemNode;
}




