/**
 * @file HeadTop.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "HeadTop.h"
#include "ImageDrawable.h"
#include "Actor.h"
#include "Timeline.h"

HeadTop::HeadTop(const std::wstring &name, const std::wstring &filename) :
        ImageDrawable(name, filename)
{

}

wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{



    ImageDrawable::Draw(graphics);

    int x =30;
    int y = 60;
    this->EyeBrow(graphics, x,y);
     x = 65;
     y = 60;
    this->EyeBrow(graphics, x,y);

    int X = 37;
    int Y = 77;
    wxBrush brush_DrawEllipse(wxColour(0, 0, 0));
    graphics->SetBrush(brush_DrawEllipse);

    this->Eye(graphics, X,Y);


    X = 72;
    Y = 76;
    wxBrush brush_DrawEllipse2(wxColour(0, 0, 0));
    graphics->SetBrush(brush_DrawEllipse2);
    this->Eye(graphics, X,Y);


}
void HeadTop::EyeBrow(std::shared_ptr<wxGraphicsContext> graphics, int x,int y)

{
    wxPoint p1 = TransformPoint (wxPoint(x,y));
    wxPoint p2 = TransformPoint (wxPoint(x+15,y));



    wxPen eyebrowPen(*wxBLACK, 2);
    //graphics->Rotate(-mPlacedR);
    graphics->SetPen(eyebrowPen);

    graphics->StrokeLine(p1.x, p1.y, p2.x, p2.y);

}
void HeadTop::Eye(std::shared_ptr<wxGraphicsContext> graphics, int X,int Y)
{
    float wid = 15.0f;
    float hit = 20.0f;
    wxPoint e1 = TransformPoint(wxPoint(X,Y));

    graphics->PushState();
    graphics->Translate(e1.x, e1.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);

    graphics->PopState();


}
/**
 * Add the channels for this drawable to a timeline
 * @param timeline The timeline class.
 */
void HeadTop::SetTimeline(Timeline *timeline)
{
    Drawable::SetTimeline(timeline);

    timeline->AddChannel(&mPointChannel);
}

void HeadTop::SetKeyframe()
{
    Drawable::SetKeyframe();

    mPointChannel.SetKeyFrame(GetPosition());

}

/**
 * Get a keyframe update from the animation system.
 */
void HeadTop::GetKeyframe()
{
    Drawable::GetKeyframe();

    if (mPointChannel.IsValid())
        SetPosition(mPointChannel.GetPoint()) ;
}
/**
void HeadTop::DeleteKeyframe()
{
    Drawable::DeleteKeyframe();

    mPointChannel.DeleteFrame();

}
 */