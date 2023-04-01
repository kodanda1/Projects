/**
 * @file DecorCastle.h
 * @author Varuntej Kodandapuram
 */
#ifndef AQUARIUM_DECORCASTLE_H
#define AQUARIUM_DECORCASTLE_H
#include "Item.h"
#include "Aquarium.h"
/**
 * Initializing class FishBeta.
 */



class DecorCastle: public Item {
private:

public:
    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;

    DecorCastle(Aquarium* aquarium);

/// Assignment operator
    void operator=(const DecorCastle &) = delete;
    wxXmlNode* XmlSave(wxXmlNode* node) override;




};





#endif //AQUARIUM_DECORCASTLE_H
