/**
 * @file AquariumView.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */

void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
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
    mAquarium.OnDraw(&dc);


}
