/**
 * @file Aquarium.cpp
 * @author Varuntej Kodandapuram
 */
#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishCarp.h"
#include "Item.h"

using namespace std;
/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{
    mBackground = make_unique<wxBitmap>(
            L"images/background1.png", wxBITMAP_TYPE_ANY);
}


/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc) {
    dc->DrawBitmap(*mBackground, 0, 0);
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);

    for (auto item : mItems)
    {
        item->Draw(dc);
    }
}
/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}


/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}
/**
 * move item on to the front in the aquarium.
 * @param item
 */
void Aquarium::MoveFront(std::shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        mItems.erase(loc);
        mItems.push_back(item);

    }
}
/**
 * Function used for making carp fish
 * eat other fishes.
 * @param carp
 */
void Aquarium::KillFish(FishCarp *carp)
{
    for (auto item : mItems) {

      auto loc = find(begin(mItems), end(mItems), item);

      if(carp !=item.get()&& item->HitTest(carp->GetX(),carp->GetY())){
          mItems.erase(loc);
          break;
      }

    }


}
