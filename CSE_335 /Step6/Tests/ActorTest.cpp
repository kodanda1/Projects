#include <pch.h>
#include "gtest/gtest.h"
#include <Actor.h>
using namespace std;

TEST(ActorTest, TestActorConstructor)
{
    Actor actor(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), actor.GetName());
};
TEST(ActorTest, EnabledDefaultValue)
{
    Actor actor(L"Harold");

    ASSERT_EQ(true,actor.IsEnabled());

    actor.SetEnabled(false);

    ASSERT_EQ(false,actor.IsEnabled());

}
TEST(ActorTest, ClickableDefaultValue)
{
    Actor actor(L"Harold");

    ASSERT_EQ(true,actor.IsClickable());

    actor.SetClickable(false);

    ASSERT_EQ(false,actor.IsClickable());

}
TEST(ActorTest, PositionDefaultValue)
{
    Actor actor(L"Harold");

    ASSERT_EQ(wxPoint(0,0),actor.GetPosition());

    actor.SetPosition(wxPoint(225, 336));
    ASSERT_EQ(wxPoint(225,336),actor.GetPosition());

}


