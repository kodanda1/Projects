/**
 * @file FishAngler.h
 * @author Varuntej Kodandapuram
 */

#ifndef AQUARIUM_FISHANGLER_H
#define AQUARIUM_FISHANGLER_H
#include "Item.h"
#include "Aquarium.h"
#include "Fish.h"

/**
 * Initializing class FishAngler.
 */
class FishAngler : public Fish {
private:


public:
    /// Default constructor (disabled)
    FishAngler() = delete;

    /// Copy constructor (disabled)
    FishAngler(const FishAngler &) = delete;

    FishAngler(Aquarium* aquarium);

/// Assignment operator
    void operator=(const FishAngler &) = delete;
    wxXmlNode* XmlSave(wxXmlNode* node) override;



};



#endif //AQUARIUM_FISHANGLER_H
