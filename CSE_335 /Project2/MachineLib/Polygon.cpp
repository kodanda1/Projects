/**
 * @file Polygon.cpp
 *
 * @author Charles Owen
 */

#include "pch.h"

#include <sstream>
#include <wx/hyperlink.h>

#include "Polygon.h"

using namespace std;

/**
 * Constructor
 */
Polygon::Polygon() : mBrush(*wxBLACK)
{
}

/**
 * Destructor
 */
Polygon::~Polygon()
{
}

void Polygon::AddPoint(int x, int y)
{
    if(mHasDrawn)
    {
        // Our polygon MUST have at least three points
        Assert(false,
               L"You cannot add points to the polygon after it has been drawn.",
               L"https://facweb.cse.msu.edu/cbowen/cse335/polygon/o/");
        return;
    }

    mPoints.push_back(wxPoint(x, y));
}


/**
 * Create a rectangle
 * @param x Left side X
 * @param y Bottom left Y
 * @param wid Width of the rectangle
 * @param hit Height of the rectangle
 */
void Polygon::Rectangle(int x, int y, int wid, int hit)
{
    AddPoint(x, y);
    AddPoint(x, y-hit);
    AddPoint(x+wid, y-hit);
    AddPoint(x+wid, y);
}


/**
 * Create a centered square at location 0,0
 * @param size Width and height of the square
 */
void Polygon::CenteredSquare(int size)
{
    Rectangle(-size / 2, size / 2, size, size);
}


/**
 * Set the color of the polygon. If we set a color, images are not used.
 * @param color A Gdiplus Color object.
 */
void Polygon::SetColor(wxColour color)
{
    mBrush.SetColour(color);
    mMode = Mode::Color;
}

/**
 * Set an image we will use as a texture for the polygon
 * @param filename Image filename
 */
void Polygon::SetImage(std::wstring filename)
{
    mImage = std::make_unique<wxImage>();
    if(mImage->LoadFile(filename, wxBITMAP_TYPE_ANY))
    {
        mMode = Mode::Image;
    }
    else
    {
        std::wstringstream str;
        str << L"Unable to load '" << filename << "'" << std::endl;
        wxMessageBox(str.str(), L"Polygon Image File Load Failure!");
        mImage = nullptr;
    }
}



/**
 * Draw the polygon
 * @param graphics Graphics object to draw on
 * @param x X location to draw in pixels
 * @param y Y location to draw in pixels
 */
void Polygon::DrawPolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if(mPoints.size() < 3)
    {
        // Our polygon MUST have at least three points
        Assert(false,
               L"You must specify a shape when using Polygon. At least three points must be provided.",
               L"https://facweb.cse.msu.edu/cbowen/cse335/polygon/c/");
        return;
    }

    mHasDrawn = true;

    switch (mMode) {
        case Mode::Color:
            DrawColorPolygon(graphics, x, y);
            break;

        case Mode::Image:
            DrawImagePolygon(graphics, x, y);
            break;

        default:
            // If this assertion fails, the no color or image was
            // indicated for this polygon. Be sure to call
            Assert(false,
                   L"You must specify either a color or an image when using Polygon",
                   L"https://facweb.cse.msu.edu/cbowen/cse335/polygon/c/");
            break;
    }
}

/**
 * Draw the polygon as a solid color-filled polygon
 * @param graphics Graphics object to draw on
 * @param x X location to draw in pixels
 * @param y Y location to draw in pixels
 */
void Polygon::DrawColorPolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if(mPath.IsNull())
    {
        // Create the graphics path
        mPath = graphics->CreatePath();

        mPath.MoveToPoint(mPoints[0].x, mPoints[0].y);
        for(size_t i=1; i<mPoints.size(); i++)
        {
            mPath.AddLineToPoint(mPoints[i].x, mPoints[i].y);
        }
        mPath.CloseSubpath();
    }

    graphics->PushState();

    graphics->Translate(x, y);
    graphics->Rotate(mRotation * M_PI * 2);

    graphics->SetBrush(mBrush);
    graphics->FillPath(mPath);

    graphics->PopState();
}

/**
 * Draw the polygon as a texture mapped image.
 *
 * This is accomplished by drawing the bitmap image clipped
 * by the supplied polygon points.
 *
 * @param graphics Graphics object to draw on
 * @param x X location to draw in pixels
 * @param y Y location to draw in pixels
 */
void Polygon::DrawImagePolygon(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    if(mGraphicsBitmap.IsNull())
    {
        mGraphicsBitmap = graphics->CreateBitmapFromImage(*mImage);

        //
        // Determine the top left and the size of the
        // region covered by our polygon
        //
        mImageClipRegionTopLeft = mPoints[0];
        auto imageClipRegionBottomRight = mPoints[0];

        for(auto point : mPoints)
        {
            if(point.x < mImageClipRegionTopLeft.x) {
                mImageClipRegionTopLeft.x = point.x;
            }

            if(point.y < mImageClipRegionTopLeft.y) {
                mImageClipRegionTopLeft.y = point.y;
            }

            if(point.x > imageClipRegionBottomRight.x) {
                imageClipRegionBottomRight.x = point.x;
            }

            if(point.y > imageClipRegionBottomRight.y) {
                imageClipRegionBottomRight.y = point.y;
            }
        }

        mImageClipRegionSize = imageClipRegionBottomRight - mImageClipRegionTopLeft;

        mImageClipRegion.Clear();
        std::vector<wxPoint> points;
        for(auto point : mPoints)
        {
            points.push_back(wxPoint(point.x - mImageClipRegionTopLeft.x,
                                     point.y - mImageClipRegionTopLeft.y));
        }

        mImageClipRegion = wxRegion(points.size(), &points[0]);
    }

    graphics->PushState();

    graphics->Translate(x, y);
    graphics->Rotate(mRotation * M_PI * 2);

    graphics->Translate(mImageClipRegionTopLeft.x, mImageClipRegionTopLeft.y);
    graphics->Clip(mImageClipRegion);
    graphics->DrawBitmap(mGraphicsBitmap, 0, 0, mImageClipRegionSize.x, mImageClipRegionSize.y);
    graphics->ResetClip();

    graphics->PopState();
}


/**
 * Assertion for Polygon that provides pop-up help.
 * @param condition Condition that is expected to the true.
 * @param msg Message that is provide if the condition is not true
 * @param url Optional URL to display with the error
 */
void Polygon::Assert(bool condition, wxString msg, const wxString &url)
{
    if(condition)
    {
        return;
    }

    // Set a breakpoint on this line to determine where
    // in your code the error comes from.
    if(mDelayedMessage == nullptr)
    {
        mDelayedMessage = std::make_shared<DelayedMessage>();
    }

    mDelayedMessage->Fire(msg, url);
}

//editor-fold desc="Code to support the deferred assertion message box" defaultstate="collapsed">

/**
 * Fire a message display after a delay. This is done since it is not
 * possible to bring up a dialog box in a Draw function, which is
 * where most errors occur.
 * @param msg Message to display
 * @param url Optional URL for help
 */
void Polygon::DelayedMessage::Fire(const wxString& msg, const wxString& url) {
    if(mFired)
    {
        return;
    }

    mMessage = msg;
    mURL = url;
    StartOnce(10);
    mFired = true;
}


/**
 * Handle the timer event so we can display the dialog box.
 */
void Polygon::DelayedMessage::Notify()
{
    wxDialog dialog(wxTheApp->GetTopWindow(), wxID_ANY, L"Polygon Class Usage Error");

    dialog.SetSizeHints( wxDefaultSize, wxDefaultSize );

    auto sizer = new wxBoxSizer( wxVERTICAL );

    auto m_staticText1 = new wxStaticText( &dialog, wxID_ANY, mMessage, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
    m_staticText1->Wrap( 300 );
    sizer->Add( m_staticText1, 0, wxALL|wxEXPAND, 15 );

    if(!mURL.IsEmpty())
    {
        auto m_staticText2 = new wxHyperlinkCtrl( &dialog, wxID_ANY, mURL, mURL);
        sizer->Add( m_staticText2, 0, wxALL, 5 );
    }

    auto m_button1 = new wxButton( &dialog, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    sizer->Add( m_button1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


    dialog.SetSizer( sizer );
    dialog.Layout();
    sizer->Fit( &dialog );

    dialog.Centre(wxBOTH);
    dialog.ShowModal();
}
///editor-fold>

