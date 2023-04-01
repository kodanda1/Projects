/**
* @file TileBuilding.h
*
* @author Charles B. Owen
*
*  Class that implements a Building tile
*/

#pragma once

#include "Tile.h"


/**
*  A Building tile
*/
class TileBuilding : public Tile
{
public:
    TileBuilding(City *city);

    ///  Default constructor (disabled)
    TileBuilding() = delete;

    ///  Copy constructor (disabled)
    TileBuilding(const TileBuilding &) = delete;

    ~TileBuilding();

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitBuilding(this); }
};

