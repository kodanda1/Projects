/**
 * @file Cow.h
 * @author Varuntej Kodandapuram
 *
 * Declaration of Cow class
 */
#ifndef STEP_1_COW_H
#define STEP_1_COW_H
#include <string>
#include "Animal.h"


class Cow : public Animal {

public:
    /// The types of cow we can have on our farm
    enum class Type {Bull, BeefCow, MilkCow};
    void ObtainCowInformation();
    void DisplayAnimal() override;
    bool isFemale() override ;
private:
    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType =Type::MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;


};


#endif //STEP_1_COW_H
