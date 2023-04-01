/**
 * @file FishNemo.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_FISHNEMO_H
#define AQUARIUM_FISHNEMO_H
#include "Item.h"
#include "Aquarium.h"
#include "Fish.h"

/**
 * Initializing class FishNemo.
 */
class FishNemo : public Fish {
private:


public:
    /// Default constructor (disabled)
    FishNemo() = delete;

    /// Copy constructor (disabled)
    FishNemo(const FishNemo &) = delete;

    FishNemo(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishNemo &) = delete;
    wxXmlNode* XmlSave(wxXmlNode* node) override;



};



#endif //AQUARIUM_FISHNEMO_H
