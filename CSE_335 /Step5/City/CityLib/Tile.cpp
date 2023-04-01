/**
 * @file Tile.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include "Tile.h"
#include "City.h"

using namespace std;



/**
 *  Distance from center for inside of tiles.
 *
 * Our tiles are a diamond that is 64 pixels tall and 128 pixels
 * wide. So, if we take the distance from the center vertically and 
 * double it, it would be as if we had a 64 by 64 diamond. The 
 * "Manhattan distance" from the center would be no more than 64
 * in that case.
 */
const int InsideTolerance = 64;


/**  Constructor
 * @param city The city this item is a member of
 */
Tile::Tile(City *city) : mCity(city)
{
}


/**
*  Destructor
*/
Tile::~Tile()
{
}

/**
 *  Set the image file to draw
 * @param file The base filename. Blank files are allowed
 */
void Tile::SetImage(const std::wstring &file)
{
    if (!file.empty())
    {
        wstring filename = mCity->GetImagesDirectory() + L"/" + file;
        mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
        mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    }
    else
    {
        mItemImage.release();
        mItemBitmap.release();
    }

    mFile = file;
}

/**
 * Draw the tile.
 * @param dc Device context to draw the tile on
*/
void Tile::Draw(wxDC* dc)
{
    if (mItemImage != nullptr)
    {
        int wid = mItemImage->GetWidth();
        int hit = mItemImage->GetHeight();

        dc->DrawBitmap(*mItemBitmap,
                mX - OffsetLeft,
                mY + OffsetDown - hit);
    }

}


/**  Draw a border around the tile
 * @param dc The graphics context to draw on
 */
void Tile::DrawBorder(wxDC* dc)
{
    wxPoint points[] = { { mX - OffsetLeft, mY }, { mX, mY - OffsetDown }, { mX + OffsetLeft, mY }, { mX, mY + OffsetDown }, { mX - OffsetLeft, mY } };

    dc->DrawLines(5, points);
}




bool Tile::HitTest(int x, int y)
{
    // Simple manhattan distance 
    return (abs(x - mX) + abs(y - mY) * 2) <= InsideTolerance;
}


/**  Save this item to an XML node
 * @param node The node we are going to be a child of
 * @return Created XML node
 */
wxXmlNode* Tile::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"tile");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"x", wxString::Format(L"%i", mX));
    itemNode->AddAttribute(L"y", wxString::Format(L"%i", mY));

    return itemNode;
}


/**
* brief Load the attributes for an item node.
*
* This is the  base class version that loads the attributes
* common to all items. Override this to load custom attributes
* for specific items.
*
* @param node The Xml node we are loading the item from
*/
void Tile::XmlLoad(wxXmlNode* node)
{
    long x, y;
    node->GetAttribute(L"x", L"0").ToLong(&x);
    node->GetAttribute(L"y", L"0").ToLong(&y);
    mX = (int)x;
    mY = (int)y;
}

/**
 *  Force the tile to a regular grid by forcing the values to be multiples of 32.
 *
 * This version works correctly for negative coordinates.
 */
void Tile::QuantizeLocation()
{
    int spacing = City::GridSpacing;
    if (mX < 0)
    {
        mX = ((mX + spacing / 2) / spacing) * spacing - spacing;
    }
    else
    {
        mX = ((mX + spacing / 2) / spacing) * spacing;
    }

    if (mY < 0)
    {
        mY = ((mY + spacing / 2) / spacing) * spacing - spacing;
    }
    else
    {
        mY = ((mY + spacing / 2) / spacing) * spacing;
    }

}

/**
 *  Get any adjacent tile.
 *
 * Given a tile in the city, this determines if there is another
 * tile adjacent to it. The parameters dx, dy determine which direction
 * to look.
 *
 * The values for specific adjacencies (dx, dy, and direction):
 *    - -1 -1 Upper left
 *    - 1 -1 Upper right
 *    - -1 1 Lower left
 *    - 1 1 Lower right
 *
 * @param dx Left/right determination, -1=left, 1=right
 * @param dy Up/Down determination, -1=up, 1=down
 * @return Adjacent tile or nullptr if none.
 */
std::shared_ptr<Tile> Tile::GetAdjacent(int dx, int dy)
{
    return mCity->GetAdjacent(this, dx, dy);
}
