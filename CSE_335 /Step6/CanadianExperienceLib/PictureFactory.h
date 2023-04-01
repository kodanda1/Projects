/**
 * @file PictureFactory.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;

/**
 * Picture Factory class for the Canadian Experience
 */

class PictureFactory {
public:
    std::shared_ptr<Picture> Create(std::wstring imagesDir);
};


#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
