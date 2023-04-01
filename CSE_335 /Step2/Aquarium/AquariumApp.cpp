/**
 * @file AquariumApp.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "AquariumApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return
 */

bool AquariumApp::OnInit() {
    if (!wxApp::OnInit())
        return false;
    // Add image type handlers
    wxInitAllImageHandlers();
    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}
