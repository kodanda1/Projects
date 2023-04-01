/**
 * @file BoostVisitor.h
 *
 * @author VaruntejKodandapuram
 */

#ifndef CITY_BOOSTVISITOR_H
#define CITY_BOOSTVISITOR_H
#include "TileVisitor.h"
#include "TileCoalmine.h"

/** BoostVisitor visitor base class */
class BoostVisitor : public TileVisitor {
private:

public:
    /**
     * VisitCoalmine visitor function
     * @param coalmine
     */
    void VisitCoalmine(TileCoalmine *coalmine) override
    {
       coalmine->Boost();
    }

};


#endif //CITY_BOOSTVISITOR_H
