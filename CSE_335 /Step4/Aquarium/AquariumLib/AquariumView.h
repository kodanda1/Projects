/**
 * @file AquariumView.h
 * @author Varuntej Kodandapuram
 */

#ifndef AQUARIUM_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMVIEW_H
#include "Aquarium.h"

/**
* View class for our aquarium
*/

class AquariumView : public wxWindow {
private:
    void OnPaint(wxPaintEvent &event);
    /** An object that describes our aquarium
     *
     */
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

/// The last stopwatch time
    long mTime = 0;
    ///Member variable of aquarium
    Aquarium  mAquarium;
    void OnAddFishBetaFish(wxCommandEvent &event);
    void OnAddFishNemoFish(wxCommandEvent &event);
    void OnAddFishAnglerFish(wxCommandEvent &event);
    ///void OnAddFishCarpFish(wxCommandEvent &event);
    void OnAddDecorCastle(wxCommandEvent &event);

public:

    void Initialize(wxFrame* parent);

    void OnLeftDown(wxMouseEvent &event);

    void OnLeftUp(wxMouseEvent &event);

    void OnMouseMove(wxMouseEvent &event);

    /**
     * Declaring SaveAs function
     * @param event
     */
    void OnFileSaveAs(wxCommandEvent &event);

    void OnFileOpen(wxCommandEvent &event);
    /**
     * Declaring Clear function
     * @param event
     */
    void OnClear(wxCommandEvent &event);
    /**
     * Declaring TimerEvent function
     * @param event
     */
    void OnTimerEvent(wxTimerEvent &event);
};


#endif //AQUARIUM_AQUARIUMVIEW_H
