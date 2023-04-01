/**
 * @file CityView.h
 * @author Charles B. Owen
 *
 *  Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#ifndef CITY_EXAMPLEVIEW_H
#define CITY_EXAMPLEVIEW_H

#include "City.h"

class Tile;

/**
 * View class for our aquarium
 */
class CityView : public wxWindow {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftDoubleClick(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);
    void OnAddTileMenuOption(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);

    void AddTileMenuOption(wxFrame* mainFrame, wxMenu* menu, int id, std::wstring text, std::wstring help);
    void OnFileSaveAs(wxCommandEvent& event);
    void OnFileOpen(wxCommandEvent& event);

    void OnViewCityReport(wxCommandEvent &event);
    void OnUpdateViewCityReport(wxUpdateUIEvent &event);
    void OnViewOutlines(wxCommandEvent &event);
    void OnUpdateViewOutlines(wxUpdateUIEvent &event);


    /// The city
    City   mCity;

    /// Any item we are currently dragging
    std::shared_ptr<Tile> mGrabbedItem;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    std::unique_ptr<wxBitmap> mTrashcan; ///< Trashcan image to use
    int mTrashcanTop = 0;           ///< Top line of the trashcan in pixels
    int mTrashcanRight = 0;         ///< Right side of the trashcan in pixels

    bool mReport = false;           ///< Viewing the city report?
    bool mOutlines = false;         ///< Outline the tiles?



    ///Checking boost bool
    bool mBoostChecked = false;
    ///Enable boost bool
    //bool mBoostEnabled = true;

    //bool mChecked = false;          ///< Checking clicked

public:
    void Initialize(wxFrame *mainFrame);

    void AddMenus(wxFrame* mainFrame, wxMenuBar* menuBar, wxMenu* fileMenu, wxMenu* viewMenu);

    /**
     * Stop the timer so the window can close
     */
    void Stop() {mTimer.Stop();}

    void OnBuildingsCount(wxCommandEvent &event);

    /**
     * Declaring OnHaulCoal Function
     * @param event
     */
    void OnHaulCoal(wxCommandEvent &event);

    /**
     * Declaring OnBoost Function
     * @param event
     */
    void OnBoost(wxCommandEvent &event);



    void OnBoostUpdateUI(wxUpdateUIEvent &event);
};

#endif //CITY_EXAMPLEVIEW_H
