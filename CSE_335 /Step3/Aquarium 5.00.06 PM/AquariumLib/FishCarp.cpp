/**
 * @file FishCarp.cpp
 * @author Varuntej Kodandapuram
 */
#include "FishCarp.h"
#include "pch.h"
#include "ids.h"
#include "Aquarium.h"

using namespace std;
/// Fish filename
const wstring FishCarpImageName = L"images/carp.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishCarp::FishCarp(Aquarium *aquarium) : Item(aquarium)
{
    mFishImage = make_unique<wxImage>(FishCarpImageName, wxBITMAP_TYPE_ANY);
    mFishBitmap = make_unique<wxBitmap>(*mFishImage);

}
/**
 * Draw this fish
 * @param dc Device context to draw on
 */
void FishCarp::Draw(wxDC *dc)
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
bool FishCarp::HitTest(int x, int y)
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

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 */
void FishCarp::SetLocation(double x, double y)
{
    Item::SetLocation(x,y);
    GetAquarium()->KillFish(this);

}
