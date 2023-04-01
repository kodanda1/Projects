/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include "ids.h"

#include "MainFrame.h"

#include "CityView.h"


/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"City", wxDefaultPosition,  wxSize( 1000,800 ));

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mCityView = new CityView();
    mCityView->Initialize(this);

    sizer->Add(mCityView,1, wxEXPAND | wxALL );

    SetSizer( sizer );
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto viewMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");
    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(viewMenu, L"&View");
    mCityView->AddMenus(this, menuBar, fileMenu, viewMenu);
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );
}



/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}

/**
 * Application about box menu handler
 */
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Welcome to the City!",
                 L"About the City",
                 wxOK,
                 this);
}


/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mCityView->Stop();
    Destroy();
}

