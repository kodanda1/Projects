/**
* @file TileGarden.h
*
* @author Charles B. Owen
*
*  Class that implements a Garden tile
*/

#pragma once

#include "Tile.h"


/**
*  A Garden tile
*/
class TileGarden : public Tile
{
public:
    TileGarden(City* city);

    ///  Default constructor (disabled)
    TileGarden() = delete;

    ///  Copy constructor (disabled)
    TileGarden(const TileGarden&) = delete;

    ~TileGarden();;

    virtual wxXmlNode* XmlSave(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    /// The supported pruning states
    enum class PruningStates { Pruned, Overgrown1, Overgrown2, Overgrown3, Overgrown4 };
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitGarden(this); }
};

