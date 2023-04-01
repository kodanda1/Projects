/**
 * @file Item.h
 * @author Varuntej Kodandapuram
 *
 * Base class for any item in our aquarium.
 */


#ifndef AQUARIUM_ITEM_H
#define AQUARIUM_ITEM_H
class Aquarium;
/**
 * Base class for any item in our aquarium.
 */

class Item {

protected:
/**
 * Constructor
 * @param aquarium
 * @param filename
 */
    Item(Aquarium *aquarium, const std::wstring &filename);

private:
    /// The aquarium this item is contained in
    Aquarium   *mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying fish image
    std::unique_ptr<wxImage> mItemImage ;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mItemBitmap;
    bool mMirror = false;   ///< True mirrors the item image



public:
/**
 * Getter used to access private member function
 * @return mAquarium
 */
     Aquarium *GetAquarium() {
         return mAquarium;

    }


    virtual ~Item();
 /**
 * The X location of the item
 * @return X location in pixels
 */
    double GetX() const { return mX; }

/**
 * The Y location of the item
 * @return Y location in pixels
 */
    double GetY() const { return mY; }

/**
 * Set the item location
 * @param x X location in pixels
 * @param y Y location in pixels
 */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }
    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * Draw this item
     * @param dc Device context to draw on
     */
    void Draw(wxDC *dc);

    bool HitTest(int x, int y);

    virtual wxXmlNode *XmlSave(wxXmlNode *node);

    void XmlLoad(wxXmlNode *node);

    /**
     * Declaring Virtual update function
     * @param elapsed
     */
    virtual void Update(double elapsed) {}


    void SetMirror(bool m);
};

#endif //AQUARIUM_ITEM_H
