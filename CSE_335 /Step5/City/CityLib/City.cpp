/**
 * @file City.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <algorithm>
#include <wx/stdpaths.h>

#include "City.h"
#include "Tile.h"
#include "TileLandscape.h"
#include "TileBuilding.h"
#include "TileRoad.h"
#include "TileCoalmine.h"
#include "TileRocketPad.h"
#include "TileGarden.h"
#include "CityReport.h"
#include "MemberReport.h"

using namespace std;

/**
 * Declaring Image Directory
 */
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
*/
City::City()
{
    SetImagesDirectory(L".");
}



/**
 * Set the directory the images are stored in
 * @param dir
 */
void City::SetImagesDirectory(const std::wstring &dir) {
    mImagesDirectory = dir + ImagesDirectory;
}


/**  Draw the city
* @param graphics The GDI+ graphics context to draw on
*/
void City::OnDraw(wxDC* graphics)
{
    for (auto item : mTiles)
    {
        item->Draw(graphics);
    }
}


/**  Add a tile to the city
* @param tile New tile to add
*/
void City::Add(std::shared_ptr<Tile> tile)
{
    mTiles.push_back(tile);
}



/**  Test an x,y click location to see if it clicked
* on some item in the city.
* @param x X location
* @param y Y location
* @return Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Tile> City::HitTest(int x, int y)
{
    for (auto i = mTiles.rbegin(); i != mTiles.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}


/**  Move an item to the front of the list of items.
*
* Removes item from the list and adds it to the end so it
* will display last.
* @param item The item to move
*/
void City::MoveToFront(std::shared_ptr<Tile> item)
{
    auto loc = find(::begin(mTiles), ::end(mTiles), item);
    if (loc != ::end(mTiles))
    {
        mTiles.erase(loc);
    }

    mTiles.push_back(item);
}


/**  Delete an item from the aquarium
*
* @param item The item to delete.
*/
void City::DeleteItem(std::shared_ptr<Tile> item)
{
    if (!item->PendingDelete())
    {
        return;
    }

    auto loc = find(::begin(mTiles), ::end(mTiles), item);
    if (loc != ::end(mTiles))
    {
        mTiles.erase(loc);
    }
}


/**  Handle updates for animation
* @param elapsed The time since the last update
*/
void City::Update(double elapsed)
{
    for (auto item : mTiles)
    {
        item->Update(elapsed);
    }
}

/**  Save the city as a .city XML file.
*
* Open an XML file and stream the city data to it.
*
* @param filename The filename of the file to save the city to
*/
void City::Save(const wxString &filename)
{
    //
    // Create an XML document
    //
    wxXmlDocument xmlDoc;

    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"aqua");
    xmlDoc.SetRoot(root);

    // Iterate over all items and save them
    for (auto item : mTiles)
    {
        item->XmlSave(root);
    }

    if(!xmlDoc.Save(filename, wxXML_NO_INDENTATION))
    {
        wxMessageBox(L"Write to XML failed");
        return;
    }
}


/**  Load the city from a .city XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* @param filename The filename of the file to load the city from.
*/
void City::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Aquarium file");
        return;
    }

    // Once we know it is open, clear the existing data
    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto node = root->GetChildren();
    for( ; node; node=node->GetNext())
    {
        if (node->GetName() == L"tile")
        {
            XmlTile(node);
        }
    }

    //
    // All loaded, ensure all sorted
    //
    SortTiles();
}


/**
 * Handle an XML node for a city tile.
 * @param node 
*/
void City::XmlTile(wxXmlNode* node)
{
    // A pointer for the item we are loading
    shared_ptr<Tile> tile;

    // We have an item. What type?
    auto type = node->GetAttribute(L"type");
    if (type == L"landscape")
    {
        tile = make_shared<TileLandscape>(this);
    }
    else if (type == L"building")
    {
        tile = make_shared<TileBuilding>(this);
    }
    else if (type == L"road")
    {
        tile = make_shared<TileRoad>(this);
    }
    else if (type == L"coalmine")
    {
        tile = make_shared<TileCoalmine>(this);
    }
    else if (type == L"rocketpad")
    {
        tile = make_shared<TileRocketPad>(this);
    }
    else if (type == L"garden")
    {
        tile = make_shared<TileGarden>(this);
    }

    if (tile != nullptr)
    {
        tile->XmlLoad(node);
        Add(tile);
    }
}




/**
*  Clear the city data.
*
* Deletes all known items in the city.
*/
void City::Clear()
{
    mTiles.clear();
}




/**
 *  Ensure the tiles are in the correct drawing order.
 *
 * This draws bottom to top so the tiles can overlapp.
 * Also builds the adjacency support since this is called whenever
 * the city is reorganized.
 */
void City::SortTiles()
{
    // sort using a lambda expression 
    sort(::begin(mTiles), ::end(mTiles), 
        [](const shared_ptr<Tile> &a, const shared_ptr<Tile> &b) {
        if (a->GetY() < b->GetY())
            return true;

        if (a->GetY() > b->GetY())
            return false;

        return a->GetX() > b->GetX();
    });

    BuildAdjacencies();
}


/**
 *  Build support for fast adjacency testing.
 *
 * This builds a map of the grid locations of every tile, so we can
 * just look them up.
 */
void City::BuildAdjacencies()
{
    mAdjacency.clear();
    for (auto tile : mTiles)
    {
        mAdjacency[pair<int, int>(tile->GetX() / GridSpacing, 
            tile->GetY() / GridSpacing)] = tile;
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
 * @param tile Tile to test
 * @param dx Left/right determination, -1=left, 1=right
 * @param dy Up/Down determination, -1=up, 1=down
 * @return Adjacent tile or nullptr if none.
 */
std::shared_ptr<Tile> City::GetAdjacent(std::shared_ptr<Tile> tile, int dx, int dy)
{
    return GetAdjacent(tile.get(), dx, dy);
}

/**
 *  Get any adjacent tile.
 * 
 * Identical to the other version, except this version accepts a
 * regular pointer instead of a shared_ptr. This allows the function
 * to be called from Tile, which only knows itself as a pointer.
 * 
 * @param tile Tile to test
 * @param dx Left/right determination, -1=left, 1=right
 * @param dy Up/Down determination, -1=up, 1=down
 * @return Adjacent tile or nullptr if none.
 */
std::shared_ptr<Tile> City::GetAdjacent(Tile *tile, int dx, int dy)
{
    int atX = tile->GetX() / GridSpacing + dx * 2;
    int atY = tile->GetY() / GridSpacing + dy;

    auto adj = mAdjacency.find(pair<int, int>(atX, atY));
    if (adj != mAdjacency.end())
    {
        // We found it
        return adj->second;
    }

    // If nothing found
    return nullptr;
}



/**
*  Generate a report for the city.
*  @return Generated report of type CityReport
*/
std::shared_ptr<CityReport> City::GenerateCityReport()
{
    auto report = make_shared<CityReport>(this);

    for (auto item : mTiles)
    {
        auto memberReport = make_shared<MemberReport>(item);
        item->Report(memberReport);
        report->Add(memberReport);
    }

    return report;
}
/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void City::Accept(TileVisitor* visitor)
{
    for (auto tile : mTiles)
    {
        tile->Accept(visitor);
    }
}

