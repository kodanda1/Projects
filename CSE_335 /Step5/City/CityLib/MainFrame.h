/**
 * @file MainFrame.h
 * @author Charles B. Owen
 *
 * The top-level (main) frame of the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

class CityView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:
    /// View class for our aquarium
    CityView *mCityView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent&);
    void OnClose(wxCloseEvent &event);

public:
    void Initialize();

};

#endif //_MAINFRAME_H_
