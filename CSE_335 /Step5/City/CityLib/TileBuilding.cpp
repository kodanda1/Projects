/**
 * @file TileBuilding.cpp
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "TileBuilding.h"
#include "MemberReport.h"

using namespace std;


/** Constructor
* @param city The city this is a member of
*/
TileBuilding::TileBuilding(City *city) : Tile(city)
{
}

/**
*  Destructor
*/
TileBuilding::~TileBuilding()
{
}

/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileBuilding::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"building");
    itemNode->AddAttribute(L"file", GetFile());

    return itemNode;
}


/**
* brief Load the attributes for an item node.
* @param node The Xml node we are loading the item from
*/
void TileBuilding::XmlLoad(wxXmlNode* node)
{
    Tile::XmlLoad(node);
    SetImage(node->GetAttribute(L"file").ToStdWstring());
}



/**
 * Generate a report for this  tile.
 * @param report
*/
void TileBuilding::Report(std::shared_ptr<MemberReport> report)
{
    wstringstream str;
    str << L"Building - " << GetFile();

    report->SetReport(str.str());
}
