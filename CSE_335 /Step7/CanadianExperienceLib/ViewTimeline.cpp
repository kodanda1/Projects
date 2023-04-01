/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include "ViewTimeline.h"
#include "TimelineDlg.h"
#include "Picture.h"
#include "Timeline.h"
#include <sstream>
#include "Actor.h"
#include "Drawable.h"


/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
const std::wstring PointerImageFile = L"/pointer.png";

/**
 * Constructor
 * @param parent The main wxFrame object
 */
ViewTimeline::ViewTimeline(wxFrame* parent, std::wstring imagesDir) :
    wxScrolledCanvas(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(100, Height),
            wxBORDER_SIMPLE)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::EditSetKeyframe, this, XRCID("EditSetKeyframe"));
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &ViewTimeline::EditDeleteKeyframe, this, XRCID("EditDeleteKeyframe"));

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
                 &ViewTimeline::OnEditTimelineProperties, this,
                 XRCID("EditTimelineProperties"));

    mPointerImage = std::make_unique<wxImage>(imagesDir + PointerImageFile, wxBITMAP_TYPE_ANY);


}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
    Timeline *timeline = GetPicture()->GetTimeline();
    wxAutoBufferedPaintDC dc(this);
    auto size = GetPicture()->GetTimeline();
    SetVirtualSize(TickSpacing*size->GetNumFrames()+BorderLeft+BorderRight,0);
    SetScrollRate(1, 0);
    DoPrepareDC(dc);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    wxPen pen(wxColour(0, 0, 0), 1);
    graphics->SetPen(pen);
    /*graphics->DrawRectangle(10, 10, 200, 60);*/
    wxFont font(wxSize(0, 16),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);
/*    graphics->DrawText(L"Timeline!", 15, 15);

    auto time = wxDateTime::Now();
    auto timeStr = time.Format(L"%x %T");
    graphics->DrawText(timeStr, 15, 40);*/

    int y2 = TickTop;
    for(int tickNum =0; tickNum<=300;tickNum++)
    {
        int x1 = BorderLeft+TickSpacing*tickNum;
        int x2 = x1;
        int y1 = y2+TickShort;

        bool onSecond = (tickNum % timeline->GetFrameRate()) == 0;

        // Convert the tick number to seconds in a string
        if(onSecond){
            std::wstringstream str;
            str << tickNum / timeline->GetFrameRate();
            std::wstring wstr = str.str();

            y1 = y2 + TickLong;

            double w, h;
            graphics->GetTextExtent(wstr, &w, &h);


            graphics->DrawText(wstr, x1-w/2, y1+5);


        }

        graphics->StrokeLine(x1, y1, x2, y2);


    }
    if(mPointerBitmap.IsNull()){

        mPointerBitmap = graphics->CreateBitmapFromImage(*mPointerImage);

    }

    graphics->DrawBitmap(mPointerBitmap,
                         (double)(mPointerImage->GetWidth()/2)+TickSpacing*timeline-> GetCurrentFrame(), TickTop,
                         mPointerImage->GetWidth(),
                         mPointerImage->GetHeight());


}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());
    //GetPicture()->GetTimeline()->SetCurrentTime(5);
    //GetPicture()->UpdateObservers();
    int x = click.x;

    // Get the timeline
    Timeline *timeline = GetPicture()->GetTimeline();
    int pointerX = (int)(timeline->GetCurrentTime() *
                         timeline->GetFrameRate() * TickSpacing + BorderLeft);

    //mMovingPointer = x >= pointerX - mPointerImage->GetWidth() / 2 &&
                    // x <= pointerX + mPointerImage->GetWidth() / 2;

   // if(mMovingPointer)
    //{
        //int xx= 0;
    //}
}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{
    auto click = CalcUnscrolledPosition(event.GetPosition());

    Timeline *timeline = GetPicture()->GetTimeline();

    //double time = ((click.x-BorderLeft)/timeline->GetFrameRate() * TickSpacing);
    //GetPicture()->SetAnimationTime(time);
    if (mMovingPointer != true) {
        if (event.LeftIsDown()) {
            double PointerTime = ((double)(click.x - BorderLeft) / (timeline->GetFrameRate() * TickSpacing));
            //GetPicture()->SetAnimationTime(PointerTime);

            if (PointerTime<=0){
                PointerTime = 0;
            }
            else if(PointerTime>timeline->GetDuration()){
                PointerTime = timeline->GetDuration();


            }
            GetPicture()->SetAnimationTime(PointerTime);
        }
        else{
            mMovingPointer = false;
        }

    }


}
/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
    Refresh();
}
/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{
    TimelineDlg dlg(this->GetParent(), GetPicture()->GetTimeline());
    if(dlg.ShowModal() == wxID_OK)
    {
        // The dialog box has changed the Tmeline settings
        GetPicture()->UpdateObservers();


    }

}
void ViewTimeline::EditSetKeyframe(wxCommandEvent& event)
{
    auto picture = GetPicture();
    for (auto actor : *picture)
    {
        actor->SetKeyframe();
    }

}
void ViewTimeline::EditDeleteKeyframe(wxCommandEvent& event)
{
    auto picture = GetPicture();

    //for (auto actor : *picture)
    //{
        //actor->DeleteKeyframe();
    //}
    //picture->SetAnimationTime(picture->GetTimeline()->GetCurrentTime());

    picture->GetTimeline()->DeleteKeyFrame();
    picture->SetAnimationTime(picture->GetAnimationTime());


}