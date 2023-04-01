/**
 * @file VickyFactory.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_VICKYFACTORY_H
#define CANADIANEXPERIENCE_VICKYFACTORY_H

class Actor;

/**
 * Vicky Factory class for the Canadian Experience
 */

class VickyFactory {
public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};


#endif //CANADIANEXPERIENCE_VICKYFACTORY_H
