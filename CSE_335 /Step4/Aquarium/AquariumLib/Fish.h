/**
 * @file Fish.h
 * @author Varuntej Kodandapuram
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H
#include "Item.h"

/**
 * initializing the Fish class.
 */
class Fish : public Item {
protected:
/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
    Fish(Aquarium *aquarium, const std::wstring &filename);
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;



/// Assignment operator
    void operator=(const Fish &) = delete;
    wxXmlNode *XmlSave(wxXmlNode *node) override;



private:
    /// Fish speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY;

    void Update(double elapsed) override;

public:
    /**
     * Setter for accessing private
     * member variable SpeedX
     * @param speedX
     */
    void setSpeedx(double speedX){
        mSpeedX = speedX;
    }

    /**
     * Setter for accessing private
     * member variable SpeedY
     * @param speedY
     */
    void setSpeedy(double speedY){
        mSpeedY = speedY;
    }




};


#endif //AQUARIUM_FISH_H
