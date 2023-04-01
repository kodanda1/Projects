/**
 * @file Aquarium.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H
#include<memory>
#include "Item.h"

class FishCarp;

/**
 * initializing the Aquarium class.
 */
class Aquarium {
public:
    Aquarium();
    void OnDraw(wxDC *dc);


    void Add(std::shared_ptr<Item> item);
    std::shared_ptr<Item> HitTest(int x, int y);

    void MoveFront(std::shared_ptr<Item> item);
    void KillFish(FishCarp * carp);

private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;

};

#endif //AQUARIUM_AQUARIUM_H
