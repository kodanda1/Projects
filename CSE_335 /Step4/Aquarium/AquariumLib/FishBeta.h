/**
 * @file FishBeta.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Item.h"
#include "Aquarium.h"
#include "Fish.h"
/**
 * Initializing class FishBeta.
 */

class FishBeta : public Fish {
private:

public:
    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    FishBeta(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishBeta &) = delete;
    wxXmlNode* XmlSave(wxXmlNode* node) override;



};


#endif //AQUARIUM_FISHBETA_H
