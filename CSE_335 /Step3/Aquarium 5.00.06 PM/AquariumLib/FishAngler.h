/**
 * @file FishAngler.h
 * @author Varuntej Kodandapuram
 */

#ifndef AQUARIUM_FISHANGLER_H
#define AQUARIUM_FISHANGLER_H
#include "Item.h"
#include "Aquarium.h"

/**
 * Initializing class FishAngler.
 */
class FishAngler : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishAngler() = delete;

    /// Copy constructor (disabled)
    FishAngler(const FishAngler &) = delete;

    FishAngler(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishAngler &) = delete;

    void Draw(wxDC *dc) override;

    bool HitTest(int x, int y) override;
};



#endif //AQUARIUM_FISHANGLER_H
