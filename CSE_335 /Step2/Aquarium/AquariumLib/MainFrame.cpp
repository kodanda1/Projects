/**
 * @file MainFrame.cpp
 * @author Varuntej Kodandapuram
 */

#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"

/**
 * Initialize the MainFrame window.
 */

void MainFrame::Initialize() {
    Create(nullptr, wxID_ANY, L"Aquarium",
           wxDefaultPosition, wxSize(1000, 800));

    // Create a sizer that will lay out child windows vertically
    // One above each other
    auto sizer = new wxBoxSizer(wxVERTICAL);

    // Create the view class object as a child of MainFrame
    auto aquariumView = new AquariumView();
    aquariumView->Initialize(this);

    // Add it to the sizer
    sizer->Add(aquariumView, 1, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer(sizer);

    //Layout (place) the child windows.
    Layout();
}
