/**
 * @file TileRocketPad.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "City.h"
#include "TileRocketPad.h"
#include "MemberReport.h"
#include "City.h"

using namespace std;


/// The image to display for the rocket pad
const wstring RocketPadImage = L"pad.png";


/** Constructor
* @param city The city this is a member of
*/
TileRocketPad::TileRocketPad(City* city) : Tile(city)
{
    SetImage(RocketPadImage);
}




/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileRocketPad::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"rocketpad");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileRocketPad::Report(std::shared_ptr<MemberReport> report)
{
    wstringstream str;
    str << L"Rocket Pad";

    report->SetReport(str.str());
}

