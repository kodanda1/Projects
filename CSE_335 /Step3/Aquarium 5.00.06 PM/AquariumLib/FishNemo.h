/**
 * @file FishNemo.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_FISHNEMO_H
#define AQUARIUM_FISHNEMO_H
#include "Item.h"
#include "Aquarium.h"

/**
 * Initializing class FishNemo.
 */
class FishNemo : public Item {
private:
    /// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:
    /// Default constructor (disabled)
    FishNemo() = delete;

    /// Copy constructor (disabled)
    FishNemo(const FishNemo &) = delete;

    FishNemo(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishNemo &) = delete;

    void Draw(wxDC *dc) override;

    bool HitTest(int x, int y) override;
};



#endif //AQUARIUM_FISHNEMO_H
