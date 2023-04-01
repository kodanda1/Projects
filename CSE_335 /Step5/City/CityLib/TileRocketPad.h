/**
 * @file TileRocketPad.h
 *
 * @author Charles B. Owen
 *
 * Class that implements a rocket pad.
 */

#pragma once

#include "Tile.h"

/**
 * Class that implements a rocket pad.
 * 
 * This is where rockets take off and land.
*/
class TileRocketPad : public Tile
{
public:
    TileRocketPad(City* city);

    ///  Default constructor (disabled)
    TileRocketPad() = delete;

    ///  Copy constructor (disabled)
    TileRocketPad(const TileRocketPad&) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void Report(std::shared_ptr<MemberReport> report) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitRocketPad(this); }
};

