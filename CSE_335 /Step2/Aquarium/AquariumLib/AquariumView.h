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
    Aquarium  mAquarium;


public:


    void Initialize(wxFrame* parent);


};


#endif //AQUARIUM_AQUARIUMVIEW_H
