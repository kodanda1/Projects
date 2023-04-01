#include <pch.h>
#include "gtest/gtest.h"
#include <wx/graphics.h>
#include <PolyDrawable.h>

using namespace std;

TEST(PolyDrawableTest, TestPolyDrawableConstructor)
{
    PolyDrawable polydrawable(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), polydrawable.GetName());
};

TEST(PolyDrawableTest, ColorDefaultValue)
{
    PolyDrawable polydrawable(L"Harold");

    wxColour colour1 = *wxBLACK;
    ASSERT_EQ(colour1,polydrawable.GetColor() );

    polydrawable.SetColor(*wxRED);
    wxColour colour2 = *wxRED;
    ASSERT_EQ(colour2,polydrawable.GetColor() );

}

TEST(PolyDrawableTest, HitTest)
{
    // Create a bitmap, and a memory device
    // context that draws on that bitmap
    wxBitmap bitmap(1000, 1000);
    wxMemoryDC dc(bitmap);

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    auto actor = std::make_shared<Actor>(L"Square");
    actor->SetPosition(wxPoint(100, 500));

    auto poly1 = std::make_shared<PolyDrawable>(L"Polygon");
    poly1->SetPosition(wxPoint(100, 100));
    poly1->SetRotation(M_PI/2);
    poly1->AddPoint(wxPoint(0, 0));
    poly1->AddPoint(wxPoint(100, 0));
    poly1->AddPoint(wxPoint(100, 100));
    poly1->AddPoint(wxPoint(0, 100));

    actor->AddDrawable(poly1);
    actor->SetRoot(poly1);

    actor->Draw(graphics);

    // Inside the square
    ASSERT_TRUE(poly1->HitTest(wxPoint(210, 590)));

    // To the left
    ASSERT_FALSE(poly1->HitTest(wxPoint(190, 590)));

    // Below
    ASSERT_FALSE(poly1->HitTest(wxPoint(210, 610)));

    // To the right
    ASSERT_FALSE(poly1->HitTest(wxPoint(310, 590)));

    // Above
    ASSERT_FALSE(poly1->HitTest(wxPoint(210, 490)));
}