/**
 * @file Goat.cpp
 * @author Varuntej Kodandapuram
 */
#include <iostream>
#include "Goat.h"

using namespace std;
/**
 * Obtain information from the user about this goat.
 *
 * Asks the user for the information that describes a goat.
 */
void Goat::ObtainGoatInformation() {
    cout << endl;
    cout << "Input information about the goat" << endl;

    // Obtain the name. This is easy, since it's just a
    // string.
    cout << "Name: ";
    cin >> mName;

    // Obtain the type using a menu. We have a loop so
    // we can handle errors.
    bool valid = false;
    while (!valid) {
        cout << "1: Nanny Goat" << endl;
        cout << "2: Billy Goat" << endl;
        cout << "3: Wether Goat" << endl;
        cout << "4: Malekid Goat" << endl;
        cout << "5: Femalekid Goat" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin) {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option) {
            case 1:
                mType = Type::Nanny;
                valid = true;
                break;

            case 2:
                mType = Type::Billy;
                valid = true;
                break;

            case 3:
                mType = Type::Wether;
                valid = true;
                break;

            case 4:
                mType = Type::Malekid;
                valid = true;
                break;

            case 5:
                mType = Type::Femalekid;
                valid = true;
                break;

        }

    }
}
/**
 * Display information about this goat.
 */
void Goat::DisplayAnimal()
{
    cout << mName << ": ";
    switch (mType)
    {
        case Type::Nanny:
            cout << "Nanny Goat" << endl;
            break;

        case Type::Billy:
            cout << "Billy Goat" << endl;
            break;

        case Type:: Wether:
            cout << "Wether Goat" << endl;
            break;
        case Type:: Malekid:
            cout << "Malekid Goat" << endl;
            break;
        case Type:: Femalekid:
            cout << "Femalekid Goat" << endl;
            break;
    }

}
/**
 * Check for two types of goat which are female.
 *
 * @return true for two female goats or else false.
 */

bool Goat::isFemale()
{
    if (mType == Type::Nanny || mType == Type::Femalekid)
    {
        return true;
    }
    return false;
}
