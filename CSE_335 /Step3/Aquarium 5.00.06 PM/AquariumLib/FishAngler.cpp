/**
 * @file FishAngler.cpp
 * @author Varuntej Kodandapuram
 */
#include "FishAngler.h"
#include "pch.h"
#include "ids.h"
#include "Aquarium.h"

using namespace std;
/// Fish filename
const wstring FishAnglerImageName = L"images/angler.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishAngler::FishAngler(Aquarium *aquarium) : Item(aquarium)
{
    mFishImage = make_unique<wxImage>(FishAnglerImageName, wxBITMAP_TYPE_ANY);
    mFishBitmap = make_unique<wxBitmap>(*mFishImage);

}
/**
 * Draw this fish
 * @param dc Device context to draw on
 */
void FishAngler::Draw(wxDC *dc)
{
    double wid = mFishBitmap->GetWidth();
    double hit = mFishBitmap->GetHeight();
    dc->DrawBitmap(*mFishBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2));

}
/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool FishAngler::HitTest(int x, int y)
{
    double wid = mFishBitmap->GetWidth();
    double hit = mFishBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mFishImage->IsTransparent((int)testX, (int)testY);
}

