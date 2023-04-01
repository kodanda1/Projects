/**
 * @file TileVisitor.h
 *
 * @author Charles B. Owen
 *
 * Tile visitor base class.
 */
#ifndef CITY_TILEVISITOR_H
#define CITY_TILEVISITOR_H

// Forward references to all tile types
class TileBuilding;
class TileCoalmine;
class TileLandscape;
class TileRoad;
class TileGarden;
class TileRocketPad;

/** Tile visitor base class */
class TileVisitor
{
public:
    virtual ~TileVisitor() {}

    /** Visit a TileBuilding object
     * @param building Building we are visiting */
    virtual void VisitBuilding(TileBuilding* building) {}

    /** Visit a TileCoalmine object
    * @param coalmine Coal mine we are visiting */
    virtual void VisitCoalmine(TileCoalmine* coalmine) {}

    /** Visit a TileLandscape object
    * @param landscape Landscape tile we are visiting */
    virtual void VisitLandscape(TileLandscape* landscape) {}

    /** Visit a TileRoad object
    * @param road Road we are visiting */
    virtual void VisitRoad(TileRoad* road) {}

    /** Visit a TileGarden object
    * @param garden Garden we are visiting */
    virtual void VisitGarden(TileGarden* garden) {}


    /** Visit a TileRocketPad object
    * @param pad Rocket Pad we are visiting */
    virtual void VisitRocketPad(TileRocketPad* pad) {}


};




#endif //CITY_TILEVISITOR_H
