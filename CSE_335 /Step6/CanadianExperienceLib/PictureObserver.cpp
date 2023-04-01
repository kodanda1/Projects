/**
 * @file PictureObserver.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "PictureObserver.h"
#include "Picture.h"


/**
 * Destructor
 *
 * Must be declared as virtual:
 * virtual ~PictureObserver();
 */
PictureObserver::~PictureObserver()
{
    if (mPicture != nullptr)
    {
        mPicture->RemoveObserver(this);
    }

}
/**
 * Set the picture for this observer
 * @param picture The picture to set
 */
void PictureObserver::SetPicture(std::shared_ptr<Picture> picture)
{
    mPicture = picture;
    mPicture->AddObserver(this);
}
