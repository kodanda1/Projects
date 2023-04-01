/**
 * @file FishCarp.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_FISHCARP_H
#define AQUARIUM_FISHCARP_H
#include "Item.h"
#include "Aquarium.h"

/**
 * Initializing class FishCarp.
 */
class FishCarp : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishCarp() = delete;

    /// Copy constructor (disabled)
    FishCarp(const FishCarp &) = delete;

    FishCarp(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishCarp &) = delete;

    void Draw(wxDC *dc) override;

    bool HitTest(int x, int y) override;
    /// Virtual function x and y are co-ordinates.
    void SetLocation(double x, double y) override;
};



#endif //AQUARIUM_FISHCARP_H
