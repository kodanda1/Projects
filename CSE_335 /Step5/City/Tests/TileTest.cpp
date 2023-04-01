#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <Tile.h>

using namespace std;

/**
*  Tile mock derived object
*/
class TileMock : public Tile
{
public:
    /**  Constructor
     * \param city City this tile is a member of */
    TileMock(City *city) : Tile(city)
    {
    }

    ///  Default constructor (disabled)
    TileMock() = delete;

    ///  Copy constructor (disabled)
    TileMock(const TileMock &) = delete;

    ~TileMock() {}
    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     * */
    virtual void Accept(TileVisitor* visitor) override { }
};

TEST(TileTest, Constructor)
{
    City city;
    TileMock tile(&city);
}

TEST(TileTest, Adjacent)
{
    City city;
    int grid = City::GridSpacing;

    // Add a center tile to test
    auto center = make_shared<TileMock>(&city);
    center->SetLocation(grid * 10, grid * 17);
    city.Add(center);

    // Upper left
    auto ul = make_shared<TileMock>(&city);
    ul->SetLocation(grid * 8, grid * 16);
    city.Add(ul);
    city.SortTiles();

    ASSERT_EQ(ul, center->GetAdjacent(-1, -1)) << L"Upper right null tests";
    ASSERT_EQ(nullptr, center->GetAdjacent(1, -1)) << L"Upper right null test";

    // Upper right
    auto ur = make_shared<TileMock>(&city);
    ur->SetLocation(grid * 12, grid * 16);
    city.Add(ur);

    // Lower left
    auto ll = make_shared<TileMock>(&city);
    ll->SetLocation(grid * 8, grid * 18);
    city.Add(ll);

    // Lower right
    auto lr = make_shared<TileMock>(&city);
    lr->SetLocation(grid * 12, grid * 18);
    city.Add(lr);

    city.SortTiles();

    ASSERT_EQ(ur, center->GetAdjacent(1, -1)) << L"Upper right test";
    ASSERT_EQ(ll, center->GetAdjacent(-1, 1)) << L"Lower left test";
    ASSERT_EQ(lr, center->GetAdjacent(1, 1)) << L"Lower right test";
}


TEST(TileTest, SetLocation)
{
    City city;
    TileMock tile(&city);

    ASSERT_EQ(0, tile.GetX());
    ASSERT_EQ(0, tile.GetY());

    tile.SetLocation(17, 23);
    ASSERT_EQ(17, tile.GetX());
    ASSERT_EQ(23, tile.GetY());
}

