/**
 * @file PolyDrawable.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_POLYDRAWABLE_H
#include "Drawable.h"
/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */

class PolyDrawable : public Drawable {
private:

/// The polygon color
    wxColour mColor = *wxBLACK;

/// Vector for points
    std::vector<wxPoint> mPoints;

    /// The transformed graphics path used
    /// to draw this polygon
    wxGraphicsPath mPath;
public:
    PolyDrawable(const std::wstring &name);
    PolyDrawable() = delete;

    /// Copy constructor (disabled)
    PolyDrawable(const PolyDrawable &) = delete;

    /// Assignment operator
    void operator=(const PolyDrawable &) = delete;

    /**
     * Getter for color
     * @return mColor
     */
    wxColour GetColor()  { return mColor; }

    /**
     * Setter for color
     * @param col
     */
    void SetColor(wxColour col) { mColor = col; }

    /**
     * Declaration of draw function
     * @param graphics
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override ;
    /**
     * Declaration of Hittest function
     * @param pos
     * @return true
     */

    virtual bool HitTest (wxPoint pos) override;

    /**
     * Declaration of function Add Point
     * @param point
     */
    void AddPoint(wxPoint point);




};


#endif //CANADIANEXPERIENCE_POLYDRAWABLE_H
