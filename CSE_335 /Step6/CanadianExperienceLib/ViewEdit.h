/**
 * @file ViewEdit.h
 * @author Charles B. Owen
 *@author Varuntej Kodandapuram
 *
 * Basic edit view class for the Canadian Experience
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#ifndef CANADIANEXPERIENCE_VIEWEDIT_H
#define CANADIANEXPERIENCE_VIEWEDIT_H
#include "PictureObserver.h"

class Actor;
class Drawable;
/**
 * Basic edit view class for the Canadian Experience
 */
class ViewEdit final : public wxScrolledCanvas, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

    /// Points for last mouse
    wxPoint mLastMouse = wxPoint(0, 0);

    /// The current mouse mode
    enum class Mode {Move, Rotate};

    /// The currently set mouse mode
    Mode mMode = Mode::Move;

    /// shared pointer for selected actor
    std::shared_ptr<Actor> mSelectedActor;

    /// shared pointer for selected Drawable
    std::shared_ptr<Drawable> mSelectedDrawable;

public:
    ViewEdit(wxFrame* parent);
    void UpdateObserver() override;

    /**
     * Declaration of function On edit move
     * @param event
     */
    void OnEditMove(wxCommandEvent& event);
    /**
     * Declaration of function On edit rotate
     * @param event
     */
    void OnEditRotate(wxCommandEvent& event);
    /**
     * Declaration of function On update edit move
     * @param event
     */
    void OnUpdateEditMove(wxUpdateUIEvent& event);
    /**
     * Declaration of function On update edit rotate
     * @param event
     */
    void OnUpdateEditRotate(wxUpdateUIEvent& event);

};

#endif //CANADIANEXPERIENCE_VIEWEDIT_H
