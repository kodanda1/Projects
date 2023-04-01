#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <TileRoad.h>
#include <TileLandscape.h>
#include <TileCoalmine.h>
#include <TileBuilding.h>

using namespace std;
class TestVisitor : public TileVisitor
{
public:
    virtual void VisitRoad(TileRoad* road) override { mNumRoads++; }

    int mNumRoads = 0;
    virtual void VisitBuilding(TileBuilding* road) override { mNumBuildings++; }

    int mNumBuildings = 0;

    virtual void VisitLandscape(TileLandscape* road) override { mNumLandscapes++; }

    int mNumLandscapes = 0;

    virtual void VisitCoalmine(TileCoalmine* road) override { mNumCoalmines++; }

    int mNumCoalmines = 0;
};

TEST(CityTest, Adjacent)
{
    City city;
    int grid = City::GridSpacing;

    // Add a center tile to test
    auto center = make_shared<TileRoad>(&city);
    center->SetLocation(grid * 10, grid * 17);
    city.Add(center);

    // Upper left
    auto ul = make_shared<TileRoad>(&city);
    ul->SetLocation(grid * 8, grid * 16);
    city.Add(ul);
    city.SortTiles();

    ASSERT_EQ(ul, city.GetAdjacent(center, -1, -1)) << L"Upper left test";
    ASSERT_EQ(nullptr,city.GetAdjacent(center, 1, -1)) << L"Upper right null test";

    // Upper right
    auto ur = make_shared<TileRoad>(&city);
    ur->SetLocation(grid * 12, grid * 16);
    city.Add(ur);

    // Lower left
    auto ll = make_shared<TileRoad>(&city);
    ll->SetLocation(grid * 8, grid * 18);
    city.Add(ll);

    // Lower right
    auto lr = make_shared<TileRoad>(&city);
    lr->SetLocation(grid * 12, grid * 18);
    city.Add(lr);

    city.SortTiles();

    ASSERT_EQ(ur, city.GetAdjacent(center, 1, -1)) << L"Upper right test";
    ASSERT_EQ(ll, city.GetAdjacent(center, -1, 1)) << L"Lower left test";
    ASSERT_EQ(lr, city.GetAdjacent(center, 1, 1)) << L"Lower right test";
}
TEST(CityTest, Iterator)
{
    // Construct a city object
    City city;

    // Add some tiles
    auto tile1 = make_shared<TileRoad>(&city);
    auto tile2 = make_shared<TileRoad>(&city);
    auto tile3 = make_shared<TileRoad>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);

    // Begin points to the first item
    auto iter1 = city.begin();

    // End points after the last item
    auto iter2 = city.end();

    ASSERT_EQ(tile1, *iter1) << L"First item correct";
    ++iter1;
    ASSERT_EQ(tile2, *iter1) << L"Second item correct";
    ++iter1;
    ASSERT_EQ(tile3, *iter1) << L"Third item correct";
    ++iter1;
    ASSERT_FALSE(iter1 != iter2);


}
TEST(CityTest, Visitor)
{

    // Construct a city object
    City city;

    // Add some tiles of each time
    auto tile1 = make_shared<TileRoad>(&city);
    auto tile2 = make_shared<TileBuilding>(&city);
    auto tile3 = make_shared<TileLandscape>(&city);
    auto tile4 = make_shared<TileCoalmine>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);
    city.Add(tile4);

    TestVisitor visitor;
    city.Accept(&visitor);
    ASSERT_EQ(1, visitor.mNumRoads) << L"Visitor number of roads";
    ASSERT_EQ(1, visitor.mNumBuildings) << L"Visitor number of buildings";
    ASSERT_EQ(1, visitor.mNumLandscapes) << L"Visitor number of landscapes";
    ASSERT_EQ(1, visitor.mNumCoalmines) << L"Visitor number of coalmines";

    TestVisitor newvisitor;
    City newCity;
    newCity.Accept(&newvisitor);
    ASSERT_EQ(0, newvisitor.mNumRoads) << L"Visitor number of roads";
    ASSERT_EQ(0, newvisitor.mNumBuildings) << L"Visitor number of buildings";
    ASSERT_EQ(0, newvisitor.mNumLandscapes) << L"Visitor number of landscapes";
    ASSERT_EQ(0, newvisitor.mNumCoalmines) << L"Visitor number of coalmines";


}

