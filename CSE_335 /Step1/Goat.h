/**
 * @file Goat.h
 * @author Varuntej Kodandapuram
 *
 * Declaration of Goat class.
 */
#ifndef STEP_1_GOAT_H
#define STEP_1_GOAT_H
#include <string>
#include "Animal.h"

class Goat : public Animal{
public:
    /// The types of cow we can have on our farm
    enum class Type {Nanny, Billy, Wether, Malekid, Femalekid};
    void ObtainGoatInformation();
    void DisplayAnimal() override;
    bool isFemale() override ;
private:
    /// The goat's name
    std::string mName;

    /// The type of goat: Nanny, Billy, Wether, Malekid, Femalekid
    Type mType =Type::Nanny;


};


#endif //STEP_1_GOAT_H
