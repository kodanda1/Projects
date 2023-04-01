/**
 * @file AquariumView.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "ids.h"
#include "AquariumView.h"
#include "FishBeta.h"
#include <wx/dcbuffer.h>
#include <algorithm>
#include "FishNemo.h"
#include "FishAngler.h"
///#include "FishCarp.h"
#include "DecorCastle.h"
#include "Item.h"


using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishNemoFish, this, IDM_ADDFISHNEMO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishAnglerFish, this, IDM_ADDFISHANGLER);
    ///parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishCarpFish, this, IDM_ADDFISHCARP);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddDecorCastle, this, IDM_ADDDECORCASTLE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileSaveAs, this, wxID_SAVEAS);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileOpen, this, wxID_OPEN);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnClear, this, wxID_CLEAR);
    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
    Bind(wxEVT_TIMER, &AquariumView::OnTimerEvent, this);
    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}
/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mAquarium.Update(elapsed);

    mAquarium.OnDraw(&dc);


}


/**
 * Menu hander for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBeta>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();

}
/**
**
* Menu hander for Add Fish>Nemo Fish
* @param event Mouse event
*/
void AquariumView::OnAddFishNemoFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishNemo>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();

}
/**
**
* Menu hander for Add Fish>Angler Fish
* @param event Mouse event
*/
void AquariumView::OnAddFishAnglerFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishAngler>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();

}
/**
**
* Menu hander for Add Fish>Carp Fish
* @param event Mouse event
*/
/**
void AquariumView::OnAddFishCarpFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishCarp>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();

}
*/
void AquariumView::OnAddDecorCastle(wxCommandEvent& event)
{
    auto castle = make_shared<DecorCastle>(&mAquarium);
    castle->SetLocation(InitialX, InitialY);
    mAquarium.Add(castle);
    Refresh();

}
void AquariumView::OnFileSaveAs(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save Aquarium file"), "", "",
                                "Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();
    mAquarium.Save(filename);
}
/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event) {
    {
        wxFileDialog loadFileDialog(this, _("Load Aquarium file"), "", "",
                                    "Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
        if (loadFileDialog.ShowModal() == wxID_CANCEL) {
            return;
        }

        auto filename = loadFileDialog.GetPath();
        mAquarium.Load(filename);
        Refresh();

    }
}
void AquariumView::OnClear(wxCommandEvent& event) {
    mAquarium.Clear();
    Refresh();
}

///Shared pointer type to initialize Grabbed item
std::shared_ptr<Item> mGrabbedItem;
/**
 * Handle the left mouse button down event
 * @param event
 */
/// Any item we are currently dragging
void AquariumView::OnLeftDown(wxMouseEvent &event)
{

    mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());
    if (mGrabbedItem != nullptr)
    {
        //We have selected an item
        //Move it to the end of the list of items
        // you'll need code here to do that...
        mAquarium.MoveFront(mGrabbedItem);

    }
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event) {
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr) {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown()) {
            mGrabbedItem->SetLocation(event.GetX(), event.GetY());
        } else {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}
void AquariumView::OnTimerEvent(wxTimerEvent &event) {
    Refresh();
}