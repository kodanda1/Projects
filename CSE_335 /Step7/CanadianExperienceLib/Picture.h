/**
 * @file Picture.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_PICTURE_H
#define CANADIANEXPERIENCE_PICTURE_H

#include <vector>
#include "Timeline.h"

class PictureObserver;
class Actor;

/**
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of
 * our actors, which then contains the drawables.
 */
class Picture {


private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);
    /// The observers of this picture
    std::vector<PictureObserver *> mObservers;
    /// The actors of this picture
    std::vector<std::shared_ptr<Actor>> mActors ;

    /// The animation timeline
    Timeline mTimeline;


public:
/**
 * Constructor
*/
    Picture() {}
    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;
    /**
     * Get the picture size
     * @return Picture size in pixels
     */
    wxSize GetSize() {return mSize;}

    /**
     * Set the picture size
     * @param size Picture size in pixels
     */
    void SetSize(wxSize size) {mSize = size;}
    void AddObserver(PictureObserver *observer);
    void RemoveObserver(PictureObserver *observer);
    void UpdateObservers();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Declaration of Function Add Actor
     * @param actor
     */
    void AddActor(std::shared_ptr<Actor> actor);

    /**
     * Get a pointer to the Timeline object
     * @return Pointer to the Timeline object
     */
    Timeline *GetTimeline() {return &mTimeline;}

 /**
 * Actor iterator class for the Canadian Experience
 */
    class Iter
    {
    public:
        /**
         * Constructor
         * @param picture
         * @param pos
         */

        Iter(Picture* picture, int pos) : mPicture(picture), mPos(pos) {}


        /**
         * Compare two iterators
         * @param other
         * @return true
         */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }


        /**
         * Value of current position
         * @return position
         */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }


        /**
         * Increment the iterator
         * @return reference to this iterator
         */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        /// Picture we are iterating over
        Picture* mPicture;

        /// position
        int mPos;
    };
    /** Iterator starting point
     * @return Start point
     * */
    Iter begin() { return Iter(this, 0); }

    /** Iterator ending point
     * @return End point
     * */
    Iter end() { return Iter(this, mActors.size()); }

    void SetAnimationTime(double time);

    /**
     *  Get Animation function declaration
     * @return Current time
     */
    double GetAnimationTime();
};



#endif //CANADIANEXPERIENCE_PICTURE_H
