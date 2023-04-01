/**
 * @file AnimChannel.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "AnimChannel.h"
#include "Timeline.h"


AnimChannel::~AnimChannel()
{
}


bool AnimChannel::IsValid()
{
    return mKeyFrame1 >= 0 || mKeyFrame2 >= 0;

}
/**
 * Ensure the keyframe indices are valid for the current time.
 *
 * The location pointed to by keyframe1 must be a time less than or
 * equal to the current time and the location pointed to by keyframe2
 * must be the next location and a location greater than the current
 * time. Note that the time may be before or after the first or last
 * item in the list.  We indicate that with values of -1 for the
 * indices.
 * @param currFrame The frame we are on.
 */
void AnimChannel::SetFrame(int currFrame)
{
    // Should we move forward in time?
    while (mKeyFrame2 >= 0 && mKeyframes[mKeyFrame2]->GetFrame() <= currFrame)
    {
        mKeyFrame1 = mKeyFrame2;
        mKeyFrame2++;
        if (mKeyFrame2 >= (int)mKeyframes.size())
            mKeyFrame2 = -1;
    }

    // Should we move backwards in time?
    while (mKeyFrame1 >= 0 && mKeyframes[mKeyFrame1]->GetFrame() > currFrame)
    {
        mKeyFrame2 = mKeyFrame1;
        mKeyFrame1--;
    }
    //
    // There are four possibilities here:
    // a) No keyframes  (mKeyframe1 < 0 and mKeyframe2 < 0)
    // b) Only a keyframe to the left (mKeyframe1 >= 0 and mKeyframe2 < 0)
    // c) Between two keyframes (mKeyframe1 >= 0 and mKeyframe2 >= 0)
    // d) Only a keyframe to the right (mKeyframe1 < 0 and mKeyframe2 >= 0)
    //
    if (mKeyFrame1 >= 0 && mKeyFrame2 >= 0)
    {
        // c) Between two keyframes
        // So we have to tween
        mKeyframes[mKeyFrame1]->UseAs1();
        mKeyframes[mKeyFrame2]->UseAs2();

        // Compute the t value
        double frameRate = GetTimeline()->GetFrameRate();
        double time1 = mKeyframes[mKeyFrame1]->GetFrame() / frameRate;
        double time2 = mKeyframes[mKeyFrame2]->GetFrame() / frameRate;
        double t = (GetTimeline()->GetCurrentTime() - time1) / (time2 - time1);

        // And tween
        Tween(t);
    }
    else if (mKeyFrame1 >= 0)
    {
        // b) Only a keyframe to the left
        // We are only using keyframe 1
        mKeyframes[mKeyFrame1]->UseOnly();
    }
    else if (mKeyFrame2 >= 0)
    {
        // d) Only a keyframe to the right
        // We are only using keyframe 2
        mKeyframes[mKeyFrame2]->UseOnly();
    }

}

/**
std::shared_ptr<KeyFrame> AnimChannel::InsertKeyFrame(KeyFrame)
{

}
 */

void AnimChannel::Tween(double t)
{


}
/**
 * Determine how we should insert a keyframe into our keyframe list.
 * @param keyframe The keyframe to insert
 */
void AnimChannel::InsertKeyFrame(std::shared_ptr<KeyFrame> keyframe)
{
    // Get the current frame and tell it to the keyframe we are setting.
    int currFrame = mTimeline->GetCurrentFrame();
    keyframe->SetFrame(currFrame);

    // The possible options for keyframe insertion
    enum { Append, Replace, Insert } action;

    // Determine the action we will do
    if (mKeyFrame1 < 0)
    {
        // There is no first keyframe. This means
        // we are before any keyframes or there are no keyframes.
        // If before a keyframe, we insert, otherwise, we append
        action = mKeyFrame2 >= 0 ? Insert : Append;
    }
    else
    {
        // We know mKeyframe1 is valid
        // So, we are after it.
        int frame1 = mKeyframes[mKeyFrame1]->GetFrame();

        if (mKeyFrame2 < 0)
        {
            // There is no second keyframe.
            // If we are after the current frame, we append.
            // If we are on the current frame, we replace.
            action = frame1 < currFrame ? Append : Replace;
        }
        else
        {
            // There is a second keyframe
            // If we are before the first frame, we insert
            // If not, we replace
            action = frame1 < currFrame ? Insert : Replace;
        }
    }

    //
    // And do the appropriate action
    //
    switch (action)
    {
        case Append:
            // Add to end and the keyframe to the left becomes the new keyframe
            mKeyframes.push_back(keyframe);
            mKeyFrame1 = (int)mKeyframes.size() - 1;
            break;

        case Replace:
            // Replace the current keyframe
            mKeyframes[mKeyFrame1] = keyframe;
            break;

        case Insert:
            // Insert after mKeyframe1
            // and mKeyframe1 becomes this new insertion (frame we are on)
            mKeyframes.insert(mKeyframes.begin() + (mKeyFrame1 + 1), keyframe);
            mKeyFrame1++;
            break;
    }

}
void AnimChannel::DeleteFrame() {

    if (mKeyFrame1 < 0)
    {
        return ;
    }

    int keyFrame1 = mKeyframes[mKeyFrame1]->GetFrame();

    int currFrame = GetTimeline()->GetCurrentFrame();

    if (keyFrame1 != currFrame)
    {
        return ;
    }
    mKeyframes.erase(mKeyframes.begin() + mKeyFrame1);

    mKeyFrame1--;

    if (mKeyFrame2 >= 0)
    {
        mKeyFrame2--;
    }
}

