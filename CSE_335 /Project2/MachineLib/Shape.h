/**
 * @file Shape.h
 *
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H
#include "Component.h"
#include "RotationSink.h"
#include "MovementSink.h"

/**
 * Shape class initialization
 */
class Shape: public Component {
private:

    /// Member variable for images directory
   // std::wstring mImagesDir;

    /// Rotation sink for this component
    RotationSink mSink;


public:

    /**
     * Constructor
     */
    Shape();
    /// Copy Constructor (Disabled)
    Shape(const Shape &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Shape &) = delete;

    /**
     * Draw function
     * @param graphics
     * @param x
     * @param y
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
     * Set image function
     * @param imagesDir
     */
    void SetImage(std::wstring imagesDir);

    /**
    * Getter for movement sink
    * @return mSink
    */
    RotationSink *GetSink() { return &mSink; }

};


#endif //CANADIANEXPERIENCE_SHAPE_H
