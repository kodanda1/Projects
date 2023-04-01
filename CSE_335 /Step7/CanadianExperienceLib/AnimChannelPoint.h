/**
 * @file AnimChannelPoint.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNELPOINT_H
#define CANADIANEXPERIENCE_ANIMCHANNELPOINT_H
#include "AnimChannel.h"

/**
 * Animation channel for points.
 */
class AnimChannelPoint : public AnimChannel{

public:


/**
* Constructor
*/
    AnimChannelPoint();

    /** Copy constructor disabled */
    AnimChannelPoint(const AnimChannelPoint &) = delete;
    /** Assignment operator disabled */
    void operator=(const AnimChannelPoint &) = delete;

    /**
     * Getter for point
     * @return mPoint
     */
    wxPoint GetPoint (){return mPoint;}

    /**
     * Setter for keyframe
     * @param point
     */
    void SetKeyFrame(wxPoint point);

    /**
     * Tween function
     * @param t
     */
    void Tween(double t);




    /**
     * Class KeyFrame point
     */

    class KeyFramePoint : public KeyFrame
    {

    private:
        /// The channel this keyframe is associated with
        AnimChannelPoint *mChannel;

        /// Member point
        wxPoint mPoint = wxPoint(0,0);

    public:

        /**
         * Constructor
         * @param channel
         * @param point
         */
        KeyFramePoint(AnimChannelPoint *channel, wxPoint point) :
            KeyFrame(channel), mChannel(channel), mPoint(point) {}

            /**
             * Getter for point
             * @return
             */
        wxPoint GetPoint (){return mPoint;}


        /** Default constructor disabled */
        KeyFramePoint() = delete;

        /** Copy constructor disabled */
        KeyFramePoint(const KeyFramePoint &) = delete;

        /** Assignment operator disabled */
        void operator=(const KeyFramePoint &) = delete;


        //void KeyframePoint(AnimChannel* channel){}


        /// Virtual UseAs1 function
        virtual void UseAs1() override {mChannel->mKeyFrame1 = this;}

        /// Virtual UseAs2 function
        virtual void UseAs2() override{mChannel->mKeyFrame2 = this;}

        /// Virtual UseOnly function
        virtual void UseOnly() override{mChannel-> mPoint = mPoint;}


    };

private:

    /// Member keyframe1
    KeyFramePoint *mKeyFrame1 = nullptr;

    /// Member keyframe2
    KeyFramePoint *mKeyFrame2 = nullptr;

    /// Member point
    wxPoint mPoint = wxPoint(0,0);



};


#endif //CANADIANEXPERIENCE_ANIMCHANNELPOINT_H
