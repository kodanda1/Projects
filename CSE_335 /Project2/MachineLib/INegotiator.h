/**
 * @file INegotiator.h
 * @author Varuntej Kodandapuram
 */

#pragma once

#include "Rod.h"

/**
 * Class INegotiator declaration
 */
class INegotiator {
public:

    /**
     * Virtual negotiate function
     * @param rod
     */
    virtual void Negotiate(Rod *rod)=0;

};



