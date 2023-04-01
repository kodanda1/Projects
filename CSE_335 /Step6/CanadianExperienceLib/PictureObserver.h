/**
 * @file PictureObserver.h
 * @author Varuntej Kodandapuram
 */
#ifndef CANADIANEXPERIENCE_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_PICTUREOBSERVER_H

#include <memory>

class Picture;

/**
 * PictureObserver class for the Canadian Experience
 */
class PictureObserver {
private:

    /// shared of pointer for picture
    std::shared_ptr<Picture> mPicture;
protected:
    /// Constructor
     PictureObserver() {}

    /// Copy Constructor (Disabled)
    PictureObserver(const PictureObserver &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const PictureObserver &) = delete;


public:
    virtual ~PictureObserver();


    /**
     * Getter for picture
     * @return mPicture
     */
    std::shared_ptr<Picture> GetPicture() { return mPicture; }
    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;

    /**
     * Setter for picture
     * @param picture
     */
    void SetPicture(std::shared_ptr<Picture> picture);
};


#endif //CANADIANEXPERIENCE_PICTUREOBSERVER_H
