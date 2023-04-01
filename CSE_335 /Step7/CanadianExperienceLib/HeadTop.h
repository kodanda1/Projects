/**
 * @file HeadTop.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_HEADTOP_H
#define CANADIANEXPERIENCE_HEADTOP_H
#include "ImageDrawable.h"

/**
 * HeadTop class for the Canadian Experience
 */
class HeadTop : public ImageDrawable{

private:

    /// Member for pointchannel
    AnimChannelPoint mPointChannel;

public:
    /** Constructor
     *
     * @param name
     * @param filename
     */
    HeadTop(const std::wstring &name, const std::wstring &filename);
    HeadTop() = delete;
    /** Copy constructor disabled */
    HeadTop(const HeadTop &) = delete;
    /** Assignment operator disabled */
    void operator=(const HeadTop &) = delete;

    /**
     * shared pointer for selected actor
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics)override;

    /** Virtual Is movable function
     *
     * @return true
     */
    virtual bool IsMovable() override{ return true; }

   /**
    * Declaration of Transformpoint function
    * @param p
    * @return rotate point
    */

    wxPoint TransformPoint(wxPoint p);

    /**
     * Declaration of Eyebrow function
     * @param graphics
     * @param x
     * @param y
     */
    void EyeBrow(std::shared_ptr<wxGraphicsContext> graphics, int x,int y);

    /**
     * Declaration of Eye function
     * @param graphics
     * @param X
     * @param Y
     */
    void Eye(std::shared_ptr<wxGraphicsContext> graphics, int X, int Y);

    /**
     * SetKeyFrame function
     */
    virtual void SetKeyframe() override ;

    /**
     * GetKeyframe function
     */

    virtual void GetKeyframe()  override;

    /**
     * SetTimeline function
     * @param timeline
     */

    void SetTimeline(Timeline *timeline) override;

    /**
     * Delete keyframe function
     */

    void DeleteKeyframe();
};


#endif //CANADIANEXPERIENCE_HEADTOP_H
