/**
* @file TileLandscape.h
*
* @author Charles B. Owen
*
*  Class that implements a Landscape tile
*/

#pragma once

#include "Tile.h"


/**
*  A Landscape tile
*/
class TileLandscape : public Tile
{
public:
    TileLandscape(City *city);

    ///  Default constructor (disabled)
    TileLandscape() = delete;

    ///  Copy constructor (disabled)
    TileLandscape(const TileLandscape &) = delete;

    ~TileLandscape();

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitLandscape(this); }
};

