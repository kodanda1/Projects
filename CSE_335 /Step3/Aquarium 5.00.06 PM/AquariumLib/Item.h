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
/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
*/
protected:
    Item(Aquarium *aquarium);

private:
    /// The aquarium this item is contained in
    Aquarium   *mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

public:
/**
 * Getter used to access private member finction
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
    virtual void Draw(wxDC *dc) = 0;

    /**
 * Test this item to see if it has been clicked on
 * @param x X location on the aquarium to test in pixels
 * @param y Y location on the aquarium to test in pixels
 * @return true if clicked on
 */
    virtual bool HitTest(int x, int y) = 0;
};




#endif //AQUARIUM_ITEM_H
