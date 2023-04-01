/**
 * @file Timeline.h
 * @author Varuntej Kodandapuram
 */


#ifndef CANADIANEXPERIENCE_TIMELINE_H
#define CANADIANEXPERIENCE_TIMELINE_H

/**
 * This class implements a timeline that manages the animation
 *
 * A timeline consists of animation channels for different parts of our
 * actors, each with keyframes that set the position, orientation, etc
 * at that point in time.
 */


class AnimChannel;

/**
 * Class Timeline
 */
class Timeline {
private:

    /// Member Numframes
    int mNumFrames =300;

    /// Member Framerate
    int mFrameRate =30;

    /// Meber currenttime
    double mCurrentTime = 0;
   // double mDuration = 10 ;
   // int mCurrentFrame = 0;
   /// List of all animation channels
   std::vector<AnimChannel *> mChannels;


public:
/**
 * Constructor
*/
    Timeline();

/** Copy constructor disabled */
    Timeline(const Timeline &) = delete;
    /** Assignment operator disabled */
    void operator=(const Timeline &) = delete;

    /**
    * Get the number of frames in the animation
    * @return Number of frames in the animation
    */
    int GetNumFrames() const {return mNumFrames;}

    /**
     * Set the number of frames in the animation
     * @param numFrames Number of frames in the animation
     */
    void SetNumFrames(double numFrames) {mNumFrames = numFrames;}

    /**
     * Get the frame rate
     * @return Animation frame rate in frames per second
     */
    int GetFrameRate() const {return mFrameRate;}

    /**
     * Set the frame rate
     * @param frameRate Animation frame rate in frames per second
     */
    void SetFrameRate(double frameRate) {mFrameRate = frameRate;}

    /**
     * Get the current time
     * @return Current animation time in seconds
     */
    double GetCurrentTime() const {return mCurrentTime;}


    //void SetCurrentTime(double currentTime) { mCurrentTime = currentTime; }

    /**
     * Get the animation duration
     * @return Animation duration in seconds
     */
    double GetDuration() const { return (double)mNumFrames/mFrameRate ; }

    /** Get the current frame.
     *
     * This is the frame associated with the current time
     * @return Current frame
     */
    int GetCurrentFrame() const { return mCurrentTime * mFrameRate ; }


    /**
     * Function declaration for AddChannel
     * @param channel
     */
    void AddChannel(AnimChannel *channel);

    /**
     * Function declaration for SetCurrrentTime
     * @param t
     */

    void SetCurrentTime(double t);

    /// Delete keyframe function declaration
    void DeleteKeyFrame();
};


#endif //CANADIANEXPERIENCE_TIMELINE_H
