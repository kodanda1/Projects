/**
 * @file AnimChannelPoint.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "AnimChannelPoint.h"

/**
* Constructor
*/
AnimChannelPoint::AnimChannelPoint()
{

}

void AnimChannelPoint::SetKeyFrame(wxPoint point)
{
    auto keyframe = std::make_shared<KeyFramePoint>(this, point);


    InsertKeyFrame(keyframe);

}
void AnimChannelPoint::Tween(double t)
{
    wxPoint a = mKeyFrame1->GetPoint();
    wxPoint b = mKeyFrame2->GetPoint();

    mPoint = wxPoint(int(a.x + t * (b.x - a.x)),
                     int(a.y + t * (b.y - a.y)));

}

