/**
* @file TileRoad.h
*
* @author Charles B. Owen
*
*  Class that implements a Road tile
*/

#pragma once

#include "Tile.h"


/**
*  A Road tile
*/
class TileRoad : public Tile
{
private:
    /// The current adjacency integer or -1 if none
    int mCurrentAdj = -1;

public:
    TileRoad(City *city);

    ///  Default constructor (disabled)
    TileRoad() = delete;

    ///  Copy constructor (disabled)
    TileRoad(const TileRoad &) = delete;

    ~TileRoad();

    virtual wxXmlNode* XmlSave(wxXmlNode* node) override;

    void SetAdjacencies(bool ul, bool ur, bool ll, bool lr);
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitRoad(this); }
};

