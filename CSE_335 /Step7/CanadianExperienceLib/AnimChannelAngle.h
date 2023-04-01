/**
 * @file AnimChannelAngle.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
#define CANADIANEXPERIENCE_ANIMCHANNELANGLE_H

#include "AnimChannel.h"

/**
 * Animation channel for angles.
 */
class AnimChannelAngle : public AnimChannel {

private:

    /// Member Angle
    double mAngle =0 ;


protected:


    /// Class that represents a keyframe
    class KeyFrameAngle:public KeyFrame
    {
    private:
        /// Member Angle
        double mAngle;
        /// The channel this keyframe is associated with
        AnimChannelAngle *mChannel;

    public:
        /**
        * Constructor
        * @param channel The channel we are for
        * @param angle The angle for the keyframe
        */
        KeyFrameAngle(AnimChannelAngle *channel, double angle) :
            KeyFrame(channel), mChannel(channel), mAngle(angle) {}

        /** Default constructor disabled */
        KeyFrameAngle() = delete;

        /** Copy constructor disabled */
        KeyFrameAngle(const KeyFrameAngle &) = delete;

        /**
         * Getter for Angle
         * @return mAngle
         */
        double GetAngle() const {return mAngle;}

        /**
         * Setter for Angle
         * @param angle
         */
        void SetAngle(double angle) { mAngle = angle; }

        /// Use this keyframe as keyframe 1
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /// Use this keyframe as keyfraem 2
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /// Use this keyframe as the angle
        void UseOnly() override { mChannel->mAngle = mAngle; }
    };

private:

    /// The first angle keyframe
    KeyFrameAngle *mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyFrameAngle *mKeyframe2 = nullptr;



public:

    ///Destructor
    virtual ~AnimChannelAngle();
    /**
 * Constructor
 */
    AnimChannelAngle();



    /** Copy constructor disabled */
    AnimChannelAngle(const AnimChannelAngle &) = delete;
    /** Assignment operator disabled */
    void operator=(const AnimChannelAngle &) = delete;

         /**
         * Getter for Angle
         * @return mAngle
         */
    double GetAngle() const {return mAngle;}


    /**
     * Function Setkeyframe
     * @param angle
     */
    void SetKeyFrame(double angle);

    /**
     * Function tween
     * @param t
     */
    void Tween(double t);

};


#endif //CANADIANEXPERIENCE_ANIMCHANNELANGLE_H
