/**
 * @file Animal.h
 * @author Varuntej Kodandapuram
 * Declared all the required virtual functions.
 *
 */

#ifndef COW_CPP_ANIMAL_H
#define COW_CPP_ANIMAL_H


class Animal
{
public:
    virtual ~Animal();
    /** Display an animal. */
    virtual void DisplayAnimal() {}
    virtual bool isFemale() {}



};


#endif //COW_CPP_ANIMAL_H
