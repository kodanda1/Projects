/**
 * @file TimelineDlg.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_TIMELINEDLG_H
#define CANADIANEXPERIENCE_TIMELINEDLG_H


#include "Timeline.h"
/**
 * Timeline dialog box
 */
class TimelineDlg final : public wxDialog {
private:
    /// Member for timeline
    Timeline* mTimeline;
    /// Number of frames in the animation
    int mNumberOfFrames;

    /// Member for FrameRate
    int mFrameRates;

public:
    /**
     * Constructor
     * @param parent
     * @param timeline
     */
    TimelineDlg(wxWindow *parent, Timeline *timeline);

    /**
     * Getter for number of frames
     * @return mNumberOfFrames
     */
    int GetNumberOFFrames() const {return mNumberOfFrames ;}

    /**
     * Setter for Number of frames
     * @param numberFrames
     */
    void SetNumberOFFrames(double numberFrames) {mNumberOfFrames = numberFrames;}

    /**
     * Getter for FrameRates
     * @return mFrameRates
     */
    int GetFrameRates() const {return mFrameRates;}

    /**
     * Setter for Frame Rates
     * @param frameRates
     */

    void SetFrameRates(double frameRates) {mFrameRates = frameRates;}


    /**
     * Function declaration for OnOk
     * @param event
     */
    void OnOK(wxCommandEvent &event);
};


#endif //CANADIANEXPERIENCE_TIMELINEDLG_H
