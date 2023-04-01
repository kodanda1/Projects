/**
* @file TileCoalmine.h
*
* @author Charles B. Owen
*
* Class that implements a Coal mine tile
*/

#pragma once

#include "Tile.h"


/**
* A Coal mine tile
*/
class TileCoalmine : public Tile
{
private:
    /// Production states
    enum class Production {
        NoProduction,
        LowProduction,
        MediumProduction,
        FullProduction,

    };
    /// Mode states
    enum class Mode {
        Normal,
        Boosted,
        Destroyed
    };
    /// Initializing mMode
    Mode mMode = Mode::Normal;


        /// Initializing mDuration
    double mDuration = 0;


    /// Current production state
    Production mProduction = Production::NoProduction;

    /// Initializing Clicked
    bool Clicked = false;


public:
    TileCoalmine(City *city);

    ///  Default constructor (disabled)
    TileCoalmine() = delete;

    ///  Copy constructor (disabled)
    TileCoalmine(const TileCoalmine &) = delete;

    ~TileCoalmine();

    virtual wxXmlNode* XmlSave(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    void Update(double elapsed) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    virtual void Accept(TileVisitor* visitor) override { visitor->VisitCoalmine(this); }

    /**
     * Declaring Haul function
     * @return production of coalmine
     */
    double Haul();

    /**
     * DECLARING BOOST function
     */
    void Boost();
};

