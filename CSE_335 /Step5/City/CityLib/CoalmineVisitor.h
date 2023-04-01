/**
 * @file CoalmineVisitor.h
 *
 * @author Varuntej Kodandapuram
 */
#ifndef CITY_COALMINEVISITOR_H
#define CITY_COALMINEVISITOR_H
#include "TileVisitor.h"
#include "TileCoalmine.h"

/** Coalmine visitor base class */
class CoalmineVisitor : public TileVisitor {
private:
    /**
     * Production Counter
     */
   double mTotalProduction= 0;


public:
    /**
     * Get Production of Coalmine
     * @return mTotalProduction
     */
    double GetProductionofCoalmine() const { return mTotalProduction; }

    /**
     * Visit Coalmine visitor function
     * @param coalmine
     */
    void VisitCoalmine(TileCoalmine* coalmine) override
    {
        mTotalProduction += coalmine->Haul();
    }

};



#endif //CITY_COALMINEVISITOR_H
