/**
 * @file CityReport.h
 *
 * @author Charles B. Owen
 *
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
 */

#pragma once

#include <unordered_map>
#include <memory>
#include <vector>
#include <list>
#include <random>

class City;
class MemberReport;

/**
 * The city report is generated by the members of the city.
 * It is a collection of objects of type MemberReport.
*/
class CityReport {
private:
    /// The city this report is for
    City *mCity;

    /// Random number generator
    std::mt19937 mRandom;

protected:
    /// Contents of a map location for a report
    class ReportHolder {
    public:
        /// The actual report
        std::shared_ptr<MemberReport> mReport;

        /// Key for the next report or empty string if none
        std::wstring mNextReport;
    };

    /// Hash map that holds the member reports
    std::unordered_map<std::wstring, std::shared_ptr<ReportHolder>> mReports;

    /// Key for the first report in the collection
    std::wstring mFirstReportKey;

    /// Key for the last report in the collection
    std::wstring mLastReportKey;

public:
    explicit CityReport(City *city);

    void Add(std::shared_ptr<MemberReport> report);

    std::wstring RandomKey();

    /** Iterator that iterates over the city tiles */
    class Iter {
    public:
        /** Constructor
         * @param cityreport The city we are iterating over
         * @param pos Position in the collection
         */
        Iter(CityReport *cityreport, std::wstring pos) : mCityReport(cityreport), mPos(pos) {}

        /**
         * Compare two iterators
         * @param other The other iterator we are comparing to
         * @return  true if this position is not equal to the other position
        */
        bool operator!=(const Iter &other) const {
            return mPos != other.mPos;
        }
        /**
         * Value of the position
         * @return position
         */
        std::shared_ptr<MemberReport> operator *()  { return mCityReport->mReports[mPos]->mReport; }


        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const Iter &operator++() {
            mPos =  mCityReport->mReports[mPos]->mNextReport;
            return *this;
        }

    private:
        CityReport *mCityReport;   ///< City we are iterating over
        std::wstring mPos;       ///< Position in the collection
    };

/**
  * Get an iterator for the beginning of the collection
  * @return Iter object at position 0
  */
    Iter begin() { return Iter(this, mFirstReportKey); }

/**
 * Get an iterator for the end of the collection
 * @return Iter object at position past the end
 */
    Iter end() { return Iter(this, L""); }
};
