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
    void OnAddFishBetaFish(wxCommandEvent &event);
    void OnAddFishNemoFish(wxCommandEvent &event);
    void OnAddFishAnglerFish(wxCommandEvent &event);
    void OnAddFishCarpFish(wxCommandEvent &event);

public:

    void Initialize(wxFrame* parent);

    void OnLeftDown(wxMouseEvent &event);

    void OnLeftUp(wxMouseEvent &event);

    void OnMouseMove(wxMouseEvent &event);



};


#endif //AQUARIUM_AQUARIUMVIEW_H
