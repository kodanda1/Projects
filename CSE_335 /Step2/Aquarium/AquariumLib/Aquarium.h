/**
 * @file Aquarium.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H
#include<memory>

/**
 * initializing the Aquarium class.
 */
class Aquarium {
public:
    Aquarium(){
        mBackground = std::make_unique<wxBitmap>(
                L"images/background1.png", wxBITMAP_TYPE_ANY);
    }


    void OnDraw(wxDC *dc);


private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
};

#endif //AQUARIUM_AQUARIUM_H
