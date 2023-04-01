/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 * @author Varuntej Kodandapuram
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H
#include "PictureObserver.h"
#


/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

    /// Bitmap image for the pointer
    std::unique_ptr<wxImage> mPointerImage;

    /// Graphics bitmap to display
    wxGraphicsBitmap mPointerBitmap;
    /// Flag to indicate we are moving the pointer
    bool mMovingPointer = false;


public:
    static const int Height = 90;      ///< Height to make this window

    /**
     * Constructor
     * @param parent
     * @param imagesDir
     */
    ViewTimeline(wxFrame* parent, std::wstring imagesDir);
    void UpdateObserver() override;

    /**
     * Function Declaration for OnEditTimelineProperties
     * @param event
     */
    void OnEditTimelineProperties(wxCommandEvent &event);


    /**
     * Function Declaration for EditSetKeyframe
     * @param event
     */
    void EditSetKeyframe(wxCommandEvent& event);


    /**
     * Function Declaration for ditDeleteKeyframe
     * @param event
     */
    void EditDeleteKeyframe(wxCommandEvent& event);
};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
