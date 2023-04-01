/**
 * @file Tile.h
 *
 * @author Charles B. Owen
 *
 * Base class for any tile in our city
 */

#pragma once
#include "TileVisitor.h"
#include <string>
#include <memory>

class City;
class MemberReport;

/**
 * Base class for any tile in our city
 */
class Tile
{
private:
    /// The city this item is contained in
    City   *mCity;

    // Item location in the aquarium
    int   mX = 0;     ///< X location for the center of the item
    int   mY = 0;     ///< Y location for the center of the item

    /// The image for this tile
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap for this tile
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// The file for this item
    std::wstring mFile;

protected:
    Tile(City *city);


public:
	/// How much we offset drawing the tile to the left of the center
	const static int OffsetLeft = 64;

	/// How much we offset drawing the tile above the center
	const static int OffsetDown = 32;

    /** The directory were the images are stored */
    static const std::wstring ImagesDirectory;

    /** The grid spacing in the city */
    static const int GridSpacing = 64;

    ///  Default constructor (disabled)
    Tile() = delete;

    ///  Copy constructor (disabled)
    Tile(const Tile &) = delete;

    virtual ~Tile();

    void SetImage(const std::wstring &file);

    /**  Get the file name for this tile image
     * @return Filename or blank if none */
    std::wstring GetFile() { return mFile; }

    /**  The X location of the center of the tile
    * @return X location in pixels */
    int GetX() const { return mX; }

    /**  The Y location of the center of the tile
    * @return Y location in pixels */
    int GetY() const { return mY; }

    /**  Set the item location
    * @param x X location
    * @param y Y location */
    void SetLocation(int x, int y) { mX = x; mY = y; }

    virtual void Draw(wxDC *dc);

    virtual void DrawBorder(wxDC *dc);

    /**  Test this item to see if it has been clicked on
    * @param x X location on the aquarium to test
    * @param y Y location on the aquarium to test
    * @return true if clicked on */
    virtual bool HitTest(int x, int y);

    virtual wxXmlNode *XmlSave(wxXmlNode *node);
    virtual void XmlLoad(wxXmlNode *node);

    ///  Handle updates for animation
    /// @param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    ///  Get the city this item is in
    /// @return City pointer
    City *GetCity() { return mCity; }

    void QuantizeLocation();

    /**
    *  Get any adjacent tile.
    *
    * Given a tile in the city, this determines if there is another
    * tile adjacent to it. The parameters dx, dy determine which direction
    * to look.
    *
    * The values for specific adjacencies (dx, dy, and direction):
    *    - -1 -1 Upper left
    *    - 1 -1 Upper right
    *    - -1 1 Lower left
    *    - 1 1 Lower right
    *
    * @param dx Left/right determination, -1=left, 1=right
    * @param dy Up/Down determination, -1=up, 1=down
    * @return Adjacent tile or nullptr if none.
    */
    std::shared_ptr<Tile> GetAdjacent(int dx, int dy);

    /**
     * Generate a member report for this tile (member)
     * @param report MemberReport object to add the report to.
    */
    virtual void Report(std::shared_ptr<MemberReport> report) {}

    /**
     * Indicate that this object is about to be deleted by
     * begin dragged into the trash can. If the function 
     * override returns false, the delete will not occur.
     * @return true if okay to delete.
    */
    virtual bool PendingDelete() { return true; }

    /**
    * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(TileVisitor* visitor) = 0;
};

