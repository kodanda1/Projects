#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <CityReport.h>
#include <MemberReport.h>

#include <TileLandscape.h>
#include <TileBuilding.h>
#include <TileCoalmine.h>

using namespace std;

/** Testing stub class, creates a vector from
 * the list. This is done so we can test this
 * before we create the iterator. DO NOT USE
 * THIS CODE to solve the iterator task */
class CityReportStub : public CityReport
{
public:
    CityReportStub(City* city) : CityReport(city) {}

    std::vector<std::shared_ptr<MemberReport>> GetReports()
    {
        // Result list
        std::vector<std::shared_ptr<MemberReport>> list;

        // position is the current position in the collection
        std::wstring position = mFirstReportKey;
        while(!position.empty())
        {
            auto reportHolder = mReports[position];
            list.push_back(reportHolder->mReport);
            position = reportHolder->mNextReport;
        }

        return list;
    }
};

class CityReportTest : public ::testing::Test {
protected:
    static void AddTile(City* city, CityReport* report, std::shared_ptr<Tile> tile)
    {
        city->Add(tile);

        auto memberReport = make_shared<MemberReport>(tile);
        tile->Report(memberReport);
        report->Add(memberReport);
    }

    static void AddLandscape(City* city, CityReport* report, int x, int y)
    {
        auto tile = make_shared<TileLandscape>(city);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }

    static void AddBuilding(City* city, CityReport* report, int x, int y, std::wstring file)
    {
        auto tile = make_shared<TileBuilding>(city);
        tile->SetImage(file);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }


    static void AddCoalmine(City* city, CityReport* report, int x, int y)
    {
        auto tile = make_shared<TileCoalmine>(city);
        tile->SetLocation(x, y);
        AddTile(city, report, tile);
    }
};

TEST_F(CityReportTest, Add)
{
    City city;     // We need a city

    // The report class under test
    CityReportStub report(&city);

    auto results = report.GetReports();
    ASSERT_EQ(0, (int)results.size());

    AddLandscape(&city, &report, 100, 210);

    results = report.GetReports();
    ASSERT_EQ(1, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());

    AddBuilding(&city, &report, 30, 109, L"market.png");

    results = report.GetReports();
    ASSERT_EQ(2, (int)results.size());
    ASSERT_EQ(wstring(L"100, 210: Landscape"), results[0]->Report());
    ASSERT_EQ(wstring(L"30, 109: Building - market.png"), results[1]->Report());

    auto str = results[1]->Report();

    for (int i = 0; i < 100; i++)
    {
        AddLandscape(&city, &report, 100+i, 210);
        AddBuilding(&city, &report, 130, 200+i, L"market.png");
        AddCoalmine(&city, &report, 300+i, 299);
    }

    results = report.GetReports();
    ASSERT_EQ(302, (int)results.size());

    for (int i = 0; i < 100; i++)
    {
        wstringstream str1, str2, str3;
        str1 << 100 + i << ", 210: Landscape";
        str2 << "130, " << 200 + i << ": Building - market.png";
        str3 << 300 + i << ", 299: Coalmine - currently idle";

        ASSERT_EQ(str1.str(), results[i * 3 + 2]->Report());
        ASSERT_EQ(str2.str(), results[i * 3 + 3]->Report());
        ASSERT_EQ(str2.str(), results[i * 3 + 3]->Report());
    }

}
TEST_F(CityReportTest, Iterator)
{
    // We need a city
    City city;

    // The report class under test
    CityReportStub report(&city);

    // Test to ensure the collection is initially empty
    auto results = report.GetReports();
    ASSERT_FALSE(report.begin() != report.end());

    // Add one landscape tile
    AddLandscape(&city, &report, 100, 210);

    // Test that the iterator works with one item in the collection
    results = report.GetReports();
    // Get an iterator
    auto iter = report.begin();
    // Ensure the iterator points to the same thing as the know first
    // item in the collection.
    ASSERT_EQ(results[0]->Report(), (*iter)->Report());
    // Ensure the iterator things it is not at the end yet
    ASSERT_TRUE(iter != report.end());
    // Increment, should increment to the end
    ++iter;
    ASSERT_FALSE(iter != report.end());

    // Add one building tile
    AddBuilding(&city, &report, 30, 109, L"market.png");

    // Test that the iterator works with two items in the collection
    results = report.GetReports();
    iter = report.begin();
    ASSERT_EQ(results[0]->Report(), (*iter)->Report());
    ASSERT_TRUE(iter != report.end());
    ++iter;
    ASSERT_EQ(results[1]->Report(), (*iter)->Report());
    ASSERT_TRUE(iter != report.end());
    ++iter;
    ASSERT_FALSE(iter != report.end());

    // Test with varying numbers of items in the collection
    for (int i = 0; i < 100; i++)
    {
        // Add three tiles
        AddLandscape(&city, &report, 100 + i, 210);
        AddBuilding(&city, &report, 130, 200 + i, L"market.png");
        AddCoalmine(&city, &report, 300 + i, 299);

        // Test the iterator
        results = report.GetReports();
        size_t cnt = 0;
        for (auto memberReport : report)
        {
            ASSERT_TRUE(cnt < results.size());
            ASSERT_EQ(results[cnt]->Report(), memberReport->Report());

            cnt++;
        }

        ASSERT_EQ(results.size(), cnt);
    }
}
