/**
 * @file AnimChannel.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_ANIMCHANNEL_H
#define CANADIANEXPERIENCE_ANIMCHANNEL_H

/**
 * Base class for animation channels
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels.
 */
class Timeline;

/**
 * Class AnimChannel
 */
class AnimChannel {

private:


    /// Member variable name
    std::wstring mName;

    /// Member variable Keyframe1
    int mKeyFrame1 = -1;

    /// Member variable Keyframe2
    int mKeyFrame2 = -1;
    /// The timeline object
    Timeline *mTimeline = nullptr;



protected:
    /// Default constructor
    AnimChannel() { }

    /// Class that represents a keyframe
    class KeyFrame
    {
    protected:

        /// Member variable frame
        int mFrame;
        /**
        * Constructor
        * @param channel Channel we are associated with
        */
        KeyFrame(AnimChannel *channel) : mChannel(channel) {}
    private:
        /// The channel this keyframe is associated with
        AnimChannel *mChannel;

    public:

        /** Default constructor disabled */
        KeyFrame() = delete;

        /** Copy constructor disabled */
        KeyFrame(const KeyFrame &) = delete;

        /** Assignment operator disabled */
        void operator=(const KeyFrame &) = delete;

        /**
         * Getter for frame
         * @return mFrame
         */
        int GetFrame() const { return mFrame; }

        /**
         * Setter for frame
         * @param frame
         */
        void SetFrame(int frame) { mFrame = frame; }

        /**
         * KeyFrame function
         * @param channel
         */
        void Keyframe(AnimChannel* channel){}

        /// Virtual UseAs1 function
        virtual void UseAs1(){}

        /// Virtual UseAs2 function
        virtual void UseAs2(){}

        /// Virtual UseOnly function
        virtual void UseOnly(){}


    };

    void InsertKeyFrame(std::shared_ptr<KeyFrame> keyframe);

    /**
     * Virtual Tween function
     * @param t
     */
    virtual void Tween(double t);

private:
    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<KeyFrame>> mKeyframes;

public:
    /// Destructor
    virtual ~AnimChannel();

    /** Copy constructor disabled */
    AnimChannel(const AnimChannel &) = delete;
    /** Assignment operator disabled */
    void operator=(const AnimChannel &) = delete;

    /**
     * Getter for mName
     * @return mName
     */
    std::wstring GetName() const { return mName; }

    /**
     * Setter for name
     * @param name
     */

    void SetName(std::wstring name) { mName = name; }

    /**
     * Function IsValid
     * @return true
     */
    bool IsValid ();

    /**
     * SetFrame function
     * @param currFrame
     */
    void SetFrame(int currFrame);

    /**
     * Getter for timeline
     * @return mTimeline
     */

    Timeline*GetTimeline() {return mTimeline;}

    /**
     * Setter for timeline
     * @param timeline
     */

    void SetTimeline(Timeline* timeline) {mTimeline = timeline;}


    /**
     * DeleteFrame function
     */
    void DeleteFrame();
};


#endif //CANADIANEXPERIENCE_ANIMCHANNEL_H
