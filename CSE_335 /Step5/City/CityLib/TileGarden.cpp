/**
 * @file TileGarden.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "TileGarden.h"
#include "MemberReport.h"

using namespace std;


/// Garden base image
const std::wstring GardenImage = L"garden.png";

/// Garden image in overgrown state 1
const std::wstring GardenOvergrownImage1 = L"garden1.png";

/// Garden image in overgrown state 2
const std::wstring GardenOvergrownImage2 = L"garden2.png";

/// Garden image in overgrown state 3
const std::wstring GardenOvergrownImage3 = L"garden3.png";

/// Garden image in overgrown state 4
const std::wstring GardenOvergrownImage4 = L"garden4.png";

/// Time until garden overgrown state 1
const double GardenOvergrownTime1 = 2.0;

/// Time until garden overgrown state 2
const double GardenOvergrownTime2 = 4.0;

/// Time until garden overgrown state 3
const double GardenOvergrownTime3 = 7.0;

/// Time until garden overgrown state 4
const double GardenOvergrownTime4 = 10.0;



/** Constructor
* @param city The city this is a member of
*/
TileGarden::TileGarden(City* city) : Tile(city)
{
    SetImage(GardenImage);
}

/**
*  Destructor
*/
TileGarden::~TileGarden()
{
}



/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileGarden::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"garden");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileGarden::Report(std::shared_ptr<MemberReport> report)
{
    wstringstream str;
    str << L"Garden";

    report->SetReport(str.str());
}
