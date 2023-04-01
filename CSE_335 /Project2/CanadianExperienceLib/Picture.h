/**
 * @file Picture.h
 *
 * @author Charles B. Owen
 *
 *  Class that represents our animation picture
 */

#pragma once

#include "Timeline.h"

#include "Adapter.h"

class PictureObserver;
class Actor;

/**
 *  Class that represents our animation picture
 */
class Picture
{
private:
    /// The picture size
    wxSize mSize = wxSize(1500, 800);

    /// The observers of this picture
    std::vector<PictureObserver *> mObservers;

    /// The actors associated with this picture
    std::vector<std::shared_ptr<Actor>> mActors;

    /// The animation timeline
    Timeline mTimeline;

    ///Machine drawable 1
    std::shared_ptr<Adapter> mMachine1;

    ///Machine drawable 2
    std::shared_ptr<Adapter> mMachine2;

public:
    Picture();

    /// Copy Constructor (Disabled)
    Picture(const Picture &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Picture &) = delete;

    /**
     * Destructor
    */
    virtual ~Picture() = default;

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

    /**
     * Get a pointer to the Timeline object
     * @return Pointer to the Timeline object
     */
    Timeline *GetTimeline() {return &mTimeline;}

    void AddObserver(PictureObserver *observer);
    void RemoveObserver(PictureObserver *observer);
    void UpdateObservers();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void AddActor(std::shared_ptr<Actor> actor);

    /** Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /**
         * Constructor
         * @param picture Picture we are iterating
         * @param pos Starting position \
         */
        ActorIter(Picture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /**
         * Test for end of the iterator
         * @param other Other object to test against
         * @return True if we this position equals not equal to the other position
         */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Actor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
        * @return Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        Picture *mPicture;  ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    ActorIter begin() { return ActorIter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    /**
     * Set Animation function
     * @param time
     */
    void SetAnimationTime(double time);

    /**
     * Get Animation function
     * @return
     */
    double GetAnimationTime();

    /**
     * Load function declaration
     * @param filename
     */
    void Load(const wxString& filename);

    /**
     * Save function declaration
     * @param filename
     */
    void Save(const wxString& filename);

    /**
     * Set machine function declaration
     * @param machine1
     * @param machine2
     */
    void SetMachines(std::shared_ptr<Adapter> machine1, std::shared_ptr<Adapter> machine2);

    /**
     * Set start frame function declaration
     */
    void SetStartFrame();

    /**
     * Getter for mMachine1
     * @return mMachine2
     */
    std::shared_ptr<Adapter> GetMachine1() {return mMachine1;}

    /**
     * Getter for mMachine2
     * @return mMachine2
     */
    std::shared_ptr<Adapter> GetMachine2() {return mMachine2;}
};

