/**
 * @file Fish.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"
#include "Item.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the Y direction in
/// pixels per second
const double MaxSpeedY = 70;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/// Minimum speed in the Y direction in
/// pixels per second
const double MinSpeedY = 40;

Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
Item(aquarium, filename)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    std::uniform_real_distribution<> distribution1(MinSpeedY, MaxSpeedY);
    mSpeedX = distribution(aquarium->GetRandom());
    mSpeedY = distribution1(aquarium->GetRandom());

}
/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */

void Fish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
                GetY() + mSpeedY * elapsed);
    if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth())
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }
    if (mSpeedX < 0 && GetX() <= 0)
    {

        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }
    if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight())
    {
        mSpeedY = -mSpeedY;

    }
    if (mSpeedY < 0 && GetY() <= 0)
    {

        mSpeedY = -mSpeedY;

    }


}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode *Fish::XmlSave(wxXmlNode *node)
{
    auto itemNode = Item::XmlSave(node);
    itemNode->AddAttribute(L"speedX", wxString::FromDouble(mSpeedX));
    itemNode->AddAttribute(L"speedY", wxString::FromDouble(mSpeedY));

    return itemNode;
}