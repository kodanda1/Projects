/**
 * @file MemberReport.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <sstream>
#include <iostream>
#include "MemberReport.h"
#include "Tile.h"

using namespace std;

/**
 * Constructor
 * @param tile File this report is for. 
*/
MemberReport::MemberReport(std::shared_ptr<Tile> tile) : mTile(tile)
{
}

/**
 * Generate the report line that is displayed.
 * @return String report line
*/
std::wstring MemberReport::Report()
{
    wstringstream str;
    str << mTile->GetX() << L", " << mTile->GetY() << L": " << mReport;
    return str.str();
}