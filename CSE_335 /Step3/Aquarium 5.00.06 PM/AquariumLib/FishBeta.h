/**
 * @file FishBeta.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Item.h"
#include "Aquarium.h"
/**
 * Initializing class FishBeta.
 */

class FishBeta : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    FishBeta(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishBeta &) = delete;

    void Draw(wxDC *dc) override;

    bool HitTest(int x, int y) override;
};


#endif //AQUARIUM_FISHBETA_H
