/**
 * @file ImageDrawable.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#include "Drawable.h"

/**
 * ImageDrawable class for the Canadian Experience
 */

class ImageDrawable : public Drawable{
protected:

    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

private:

    /// The center
    wxPoint mCenter;

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;


public:

    ImageDrawable(const std::wstring &name, const std::wstring &filename);

    /** Default constructor disabled */
    ImageDrawable() = delete;
    /** Copy constructor disabled */
    ImageDrawable(const ImageDrawable &) = delete;
    /** Assignment operator disabled */
    void operator=(const ImageDrawable &) = delete;

    /**
     * Getter for Center
     * @return mCenter
     */
    wxPoint GetCenter() const { return mCenter; }

    /**
     * Setter for Center
     * @param center
     */

    void SetCenter(wxPoint center) { mCenter = center; }


    bool HitTest(wxPoint pos);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
};


#endif //CANADIANEXPERIENCE_IMAGEDRAWABLE_H
