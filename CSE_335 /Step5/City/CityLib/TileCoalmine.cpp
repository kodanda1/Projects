/**
 * @file TileCoalmine.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "TileCoalmine.h"
#include "MemberReport.h"

using namespace std;

/// Image when the coalmine production is empty
const wstring NoProductionImage = L"coalmine-empty.png";

/// Image when the coalmine production is low
const wstring LowProductionImage = L"coalmine-low.png";

/// Time to reach low production level in seconds
const double LowProductionTime = 5;

/// Tons of coal at low production level
const double LowProductionLevel = 1;

/// Image when the coalmine production is Medium
const wstring MediumProductionImage = L"coalmine-med.png";

/// Time to reach Medium production level in seconds
const double MediumProductionTime = 6;

/// Tons of coal at Medium production level
const double MediumProductionLevel = 2.5;

/// Image when the coalmine production is Full
const wstring FullProductionImage = L"coalmine-full.png";

/// Time to reach Full production level in seconds
const double FullProductionTime = 4;

/// Tons of coal at Full production level
const double FullProductionLevel = 4;

/// Image when the coalmine is destroyed
const wstring DestroyedImage = L"burnt_land.png";

/** Constructor
* @param city The city this is a member of
*/
TileCoalmine::TileCoalmine(City *city) : Tile(city)
{
    SetImage(NoProductionImage);

}

/**
*  Destructor
*/
TileCoalmine::~TileCoalmine()
{
}

/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileCoalmine::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"coalmine");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileCoalmine::Report(std::shared_ptr<MemberReport> report)
{
    wstringstream str;
    str << L"Coal Mine - currently idle";

    report->SetReport(str.str());
}

/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void TileCoalmine::Update(double elapsed)
{
    Tile::Update(elapsed);

    switch(mMode)
    {
        case Mode::Normal:
            mDuration += elapsed;
            break;
        case Mode::Boosted:
            mDuration += elapsed*2;
            break;
        case Mode::Destroyed:
            return;

    }



    if (mProduction == Production::NoProduction && mDuration >= LowProductionTime)
    {
        mProduction = Production::LowProduction;
        SetImage(LowProductionImage);
        mDuration = 0;
    }
    if (mProduction == Production::LowProduction && mDuration >= MediumProductionTime)
    {
        mProduction = Production::MediumProduction;
        SetImage(MediumProductionImage);
        mDuration = 0;
    }
    if (mProduction == Production::MediumProduction && mDuration >= FullProductionTime)
    {
        mProduction = Production::FullProduction;
        SetImage(FullProductionImage);
        mDuration = 0;
    }

}
double TileCoalmine::Haul()
{
    auto production = mProduction;
    mProduction = Production::NoProduction;
    mDuration = 0;
    SetImage(NoProductionImage);
    if (production == Production::NoProduction)
    {
        return 0;

    }
    if (production == Production::LowProduction) {
        return LowProductionLevel;

    }
    if (production == Production::MediumProduction) {
        return MediumProductionLevel;

    }

    else
    {
        return FullProductionLevel;
    }


}


void TileCoalmine::Boost()
{

    switch(mMode)
    {
        case Mode::Normal:
          mMode = Mode::Boosted;
          break;

        case Mode::Boosted:
           mMode = Mode::Destroyed;
           SetImage(DestroyedImage);
           break;

        case Mode::Destroyed:
            mProduction = Production::NoProduction;
            break;
    }



}

