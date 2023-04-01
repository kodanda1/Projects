/**
 * @file HaroldFactory.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_HAROLDFACTORY_H
#define CANADIANEXPERIENCE_HAROLDFACTORY_H

class Actor;
/**
 * Harold Factory class for the Canadian Experience
 */
class HaroldFactory {

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};


#endif //CANADIANEXPERIENCE_HAROLDFACTORY_H
