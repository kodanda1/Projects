/**
 * @file TileLandscape.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include "TileLandscape.h"
#include "MemberReport.h"

using namespace std;


/** Constructor
* @param city The city this is a member of
*/
TileLandscape::TileLandscape(City *city) : Tile(city)
{
}

/**
*  Destructor
*/
TileLandscape::~TileLandscape()
{
}


/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileLandscape::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"landscape");
    itemNode->AddAttribute(L"file", GetFile());

    return itemNode;
}


/**
* Load the attributes for an item node.
* @param node The Xml node we are loading the item from
*/
void TileLandscape::XmlLoad(wxXmlNode* node)
{
    Tile::XmlLoad(node);
    SetImage(node->GetAttribute(L"file").ToStdWstring());
}

/**
 * Generate a report for this landscape tile.
 * @param report 
*/
void TileLandscape::Report(std::shared_ptr<MemberReport> report)
{
    report->SetReport(L"Landscape");
}
