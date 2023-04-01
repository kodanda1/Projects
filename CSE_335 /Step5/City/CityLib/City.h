/**
 * @file City.h
 *
 * @author Charles B. Owen
 *
 *  Class that implements a simple city with tiles we can manipulate
 */

#pragma once

#include <memory>
#include <vector>
#include <map>
#include <utility>

#include "Tile.h"

class CityReport;

/**
 *  Implements a simple city with tiles we can manipulate
 */
class City
{
private:
    void XmlTile(wxXmlNode *node);
    void BuildAdjacencies();

    /// All of the tiles that make up our city
    std::vector<std::shared_ptr<Tile> > mTiles;

    /// Adjacency lookup support
    std::map<std::pair<int, int>, std::shared_ptr<Tile> > mAdjacency;

    /// Directory containing the system images
    std::wstring mImagesDirectory;

public:
    City();

    /**
     * Destructor
    */
    virtual ~City() = default;

    /// The spacing between grid locations
    static const int GridSpacing = 32;

    /**
     * Get the directory the images are stored in
     * @return Images directory path
     */
    const std::wstring &GetImagesDirectory() const { return mImagesDirectory; }

    void SetImagesDirectory(const std::wstring &dir);

    void Add(std::shared_ptr<Tile> item);
    std::shared_ptr<Tile> HitTest(int x, int y);
    void MoveToFront(std::shared_ptr<Tile> item);
    void DeleteItem(std::shared_ptr<Tile> item);

    void OnDraw(wxDC *graphics);

    void Save(const wxString &filename);
    void Load(const wxString &filename);
    void Clear();

    void Update(double elapsed);
    void SortTiles();

    std::shared_ptr<Tile> GetAdjacent(std::shared_ptr<Tile> tile, int dx, int dy);
    std::shared_ptr<Tile> GetAdjacent(Tile *tile, int dx, int dy);

    std::shared_ptr<CityReport> GenerateCityReport();

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * @param city The city we are iterating over
         * @param pos Position in the collection
         */
        Iter(City* city, int pos) : mCity(city), mPos(pos) {}

        /**
         * Compare two iterators
         * @param other The other iterator we are comparing to
         * @return  true if this position is not equal to the other position
        */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Tile> operator *() const { return mCity->mTiles[mPos]; }

        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        City* mCity;   ///< City we are iterating over
        int mPos;       ///< Position in the collection
    };
    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    Iter begin() { return Iter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    Iter end() { return Iter(this, mTiles.size()); }

    void Accept(TileVisitor *visitor);
};

