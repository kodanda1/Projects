/**
 * @file MainFrame.h
 * @author Varuntej Kodandapuram
 */

#ifndef AQUARIUM_MAINFRAME_H
#define AQUARIUM_MAINFRAME_H

/**
* The top-level (main) frame of the application
*/
class MainFrame : public wxFrame{
private:
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
public:

    void Initialize();




};


#endif //AQUARIUM_MAINFRAME_H
