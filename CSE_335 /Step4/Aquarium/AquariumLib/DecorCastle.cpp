
/**
* @file DecorCastle.cpp
* @author Varuntej Kodandapuram
*/

#include "pch.h"
#include "ids.h"
#include "DecorCastle.h"
#include "Aquarium.h"

using namespace std;
/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{

}
/**
* Save this fish to an XML node
* @param node The parent node we are going to be a child of
* @return
*/
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"type", L"castle");
    return itemNode;
}

