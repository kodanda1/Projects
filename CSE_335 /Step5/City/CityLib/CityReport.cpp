/**
 * @file CityReport.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include "CityReport.h"

using namespace std;

/// Length of keys that index report holders
const int KeyLength = 10;

/**
 * Constructor
 * @param city City this report is for. 
*/
CityReport::CityReport(City* city) : mCity(city)
{
    random_device rd;
    mRandom = mt19937(rd());
}

/**
 * Add a new city report
 * @param report ReportHolder to add
*/
void CityReport::Add(std::shared_ptr<MemberReport> report)
{
    // Create a ReportHolder object to hold the new report
    // and add the report to it
    auto reportHolder = make_shared<ReportHolder>();
    reportHolder->mReport = report;

    // Generate a key and add it to the collection
    auto newReportKey = RandomKey();
    mReports[newReportKey] = reportHolder;

    if(mFirstReportKey.empty())
    {
        // If this is the first item in the collection,
        // set the first report key to point to it
        mFirstReportKey = newReportKey;
    }
    else
    {
        // If not the first, make the last item point to the new item
        mReports[mLastReportKey]->mNextReport = newReportKey;
    }

    // The last report key is always what we just added
    // to the collection.
    mLastReportKey = newReportKey;
}

/**
 * Generate a random string key we can used to identify
 * a location in the collection of reports
 * @return Random string
 */
std::wstring CityReport::RandomKey()
{
    static wchar_t characters[] = L"0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::uniform_int_distribution<std::wstring::size_type> pick(0, (sizeof(characters) / sizeof(wchar_t)) - 2);

    std::wstring s;
    s.reserve(KeyLength);

    for(int i=0; i<KeyLength; i++) {
        s += characters[pick(mRandom)];
    }

    return s;
}