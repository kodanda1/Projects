/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 * @author Varuntej Kodandapuram
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H
#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxWindow, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

public:
    static const int Height = 90;      ///< Height to make this window

    ViewTimeline(wxFrame* parent);
    void UpdateObserver() override;
};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
