/**
 * @file AnimChannelAngle.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "AnimChannelAngle.h"
AnimChannelAngle::~AnimChannelAngle()
{
}

/**
 * Constructor
 */
AnimChannelAngle::AnimChannelAngle()
{

}

void AnimChannelAngle::SetKeyFrame(double angle)
{// Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    auto keyframe = std::make_shared<KeyFrameAngle>(this, angle);

    // Insert it into the collection
    InsertKeyFrame(keyframe);

}
void AnimChannelAngle::Tween(double t)
{
    mAngle = mKeyframe1->GetAngle() * (1 - t) +
             mKeyframe2->GetAngle() * t;

}


