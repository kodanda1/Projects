/**
 * @file Adapter.h
 * @author Varuntej Kodandapuram
 */

#ifndef CANADIANEXPERIENCE_ADAPTER_H
#define CANADIANEXPERIENCE_ADAPTER_H

#include "Drawable.h"
#include <string>
#include<machine-api.h>

/**
 * Class adapter declaration
 */
class Adapter : public Drawable{
private:

    /// shared pointer mMachine
    std::shared_ptr<Machine> mMachine;

    /// Pointer to mTimeline
    Timeline *mTimeline = nullptr;


    /// Member variable for starting frame
    int mStartingFrame = 0;



public:

    /**
     * Constructor
     * @param name
     * @param imagesDir
     */
    Adapter(const std::wstring &name, const std::wstring imagesDir);

    /** Default constructor disabled */
    Adapter() = delete;

    /** Copy constructor disabled */
    Adapter(const Adapter &) = delete;
    /** Assignment operator disabled */
    void operator=(const Adapter &) = delete;

    /**
     * Override draw function
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Override Set timeline function declaration
     * @param timeline
     */
    void SetTimeline(Timeline *timeline)override;

    /**
     * Hittest override function
     * @param pos
     * @return
     */
    bool HitTest(wxPoint pos)override;

    /**
     * set machine number function declaration
     * @param x
     */
    void SetMachineNumber(int x);

    /**
     * Get machine number function declaration
     * @return
     */
    int GetMachineNumber();


    /**
     * Getter for starting frame
     * @return
     */
    int GetStart(){return mStartingFrame;}

    /**
     * Setter for starting frame
     * @param start
     */
    void SetStart(int start) {mStartingFrame= start;}

    /**
     * xml save function declaration
     * @param root
     */

    void Save(wxXmlNode *root);

    /**
     * xml load function declaration
     * @param root
     */

    void Load(wxXmlNode *root);

    /**
     * Getter for mMachine
     * @return
     */
    std::shared_ptr<Machine> GetMachine() {return mMachine;}
};


#endif //CANADIANEXPERIENCE_ADAPTER_H
