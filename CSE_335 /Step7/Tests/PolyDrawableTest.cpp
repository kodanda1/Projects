#include <pch.h>
#include "gtest/gtest.h"
#include <wx/graphics.h>
#include <PolyDrawable.h>
#include <Actor.h>
#include <Picture.h>

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
/** This tests that the animation of the rotation of a drawable works */
TEST(PolyDrawableTest, Animation)
{
    // Create a picture object
    auto picture = std::make_shared<Picture>();

    // Create an actor and add it to the picture
    auto actor = std::make_shared<Actor>(L"Actor");

    // Create a drawable for the actor
    auto drawable = std::make_shared<PolyDrawable>(L"Drawable");
    actor->SetRoot(drawable);
    actor->AddDrawable(drawable);

    picture->AddActor(actor);

    auto channel = drawable->GetAngleChannel();

    // First we will ensure it works with no keyframes set
    picture->SetAnimationTime(0);
    drawable->SetRotation(1.33);

    // The channel should not be valid
    ASSERT_FALSE(channel->IsValid());

    // Getting a keyframe should not changle the angle
    actor->GetKeyframe();
    ASSERT_NEAR(1.33, drawable->GetRotation(), 0.00001);

    // Now we'll set one keyframe and see if that works
    picture->SetAnimationTime(1.5);
    drawable->SetRotation(2.7);
    actor->SetKeyframe();

    // Change angle
    drawable->SetRotation(0.3);
    ASSERT_NEAR(0.3, drawable->GetRotation(), 0.00001);

    // Wherever we move, now, the keyframe angle should be used
    picture->SetAnimationTime(0);
    ASSERT_NEAR(2.7, drawable->GetRotation(), 0.00001);

    drawable->SetRotation(0.3);
    picture->SetAnimationTime(1.5);
    ASSERT_NEAR(2.7, drawable->GetRotation(), 0.00001);

    drawable->SetRotation(0.3);
    picture->SetAnimationTime(3);
    ASSERT_NEAR(2.7, drawable->GetRotation(), 0.00001);

    // We'll set a second keyframe and see if that works
    picture->SetAnimationTime(3.0);
    drawable->SetRotation(-1.8);
    actor->SetKeyframe();

    // Test before the keyframes
    drawable->SetRotation(0.3);
    picture->SetAnimationTime(0);
    ASSERT_NEAR(2.7, drawable->GetRotation(), 0.00001);

    // Test at first keyframe
    drawable->SetRotation(0.3);
    picture->SetAnimationTime(1.5);
    ASSERT_NEAR(2.7, drawable->GetRotation(), 0.00001);

    // Test at second keyframe
    drawable->SetRotation(0.3);
    picture->SetAnimationTime(3.0);
    ASSERT_NEAR(-1.8, drawable->GetRotation(), 0.00001);

    // Test after second keyframe
    drawable->SetRotation(0.3);
    picture->SetAnimationTime(4);
    ASSERT_NEAR(-1.8, drawable->GetRotation(), 0.00001);
    // Test between the two keyframs
    drawable->SetRotation(0.3);
    // Halfway between the two keyframes
    picture->SetAnimationTime(2.25);
    ASSERT_NEAR((2.7 + -1.8) / 2,
                drawable->GetRotation(), 0.00001);

    drawable->SetRotation(0.3);
    // 1/3 between the two keyframes
    picture->SetAnimationTime(2.0);
    ASSERT_NEAR(2.7 + 1.0 / 3.0 * (-1.8 - 2.7),
                drawable->GetRotation(), 0.00001);
}