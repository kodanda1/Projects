#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <TileRoad.h>

using namespace std;

TEST(TileRoadTest, Adjacencies)
{
    City city;
    TileRoad road(&city);

    ASSERT_EQ(wstring(L"roadlr.png"), road.GetFile());

    // Nothing
    road.SetAdjacencies(false, false, false, false);
    ASSERT_EQ(wstring(L"roadlr.png"), road.GetFile());

    // One adjacency
    road.SetAdjacencies(true, false, false, false);
    ASSERT_EQ(wstring(L"roadlr.png"), road.GetFile());

    road.SetAdjacencies(false, true, false, false);
    ASSERT_EQ(wstring(L"roadud.png"), road.GetFile());

    road.SetAdjacencies(false, false, true, false);
    ASSERT_EQ(wstring(L"roadud.png"), road.GetFile());

    road.SetAdjacencies(false, false, false, true);
    ASSERT_EQ(wstring(L"roadlr.png"), road.GetFile());

    // Two adjacencies
    road.SetAdjacencies(true, true, false, false);
    ASSERT_EQ(wstring(L"roadlu.png"), road.GetFile());

    road.SetAdjacencies(true, false, true, false);
    ASSERT_EQ(wstring(L"roadld.png"), road.GetFile());

    road.SetAdjacencies(true, false, false, true);
    ASSERT_EQ(wstring(L"roadlr.png"), road.GetFile());

    road.SetAdjacencies(false, true, true, false);
    ASSERT_EQ(wstring(L"roadud.png"), road.GetFile());

    road.SetAdjacencies(false, true, false, true);
    ASSERT_EQ(wstring(L"roadur.png"), road.GetFile());

    road.SetAdjacencies(false, false, true, true);
    ASSERT_EQ(wstring(L"roaddr.png"), road.GetFile());

    // Three adjacencies
    road.SetAdjacencies(false, true, true, true);
    ASSERT_EQ(wstring(L"roadudr.png"), road.GetFile());

    road.SetAdjacencies(true, false, true, true);
    ASSERT_EQ(wstring(L"roadldr.png"), road.GetFile());

    road.SetAdjacencies(true, true, false, true);
    ASSERT_EQ(wstring(L"roadlur.png"), road.GetFile());

    road.SetAdjacencies(true, true, true, false);
    ASSERT_EQ(wstring(L"roadlud.png"), road.GetFile());

    // All four
    road.SetAdjacencies(true, true, true, true);
    ASSERT_EQ(wstring(L"roadludr.png"), road.GetFile());
}

