/**
 * @file RodSink.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "RodSink.h"
#include "Component.h"
#include "INegotiator.h"
#include "Rod.h"

/**
 * Constructor
 * @param component
 * @param negotiator
 */
RodSink::RodSink(Component *component, INegotiator *negotiator): mNegotiator(negotiator)
{


}

void RodSink::Negotiate(Rod *rod)
{
    mNegotiator->Negotiate(rod);

}