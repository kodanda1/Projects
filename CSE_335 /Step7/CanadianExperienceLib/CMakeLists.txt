project(CanadianExperienceLib)

set(SOURCE_FILES
        pch.h
        MainFrame.cpp MainFrame.h
        ViewEdit.cpp ViewEdit.h
        ViewTimeline.cpp ViewTimeline.h
        Picture.cpp Picture.h PictureObserver.cpp PictureObserver.h Actor.cpp Actor.h Drawable.cpp Drawable.h PolyDrawable.cpp PolyDrawable.h PictureFactory.cpp PictureFactory.h HaroldFactory.cpp HaroldFactory.h ImageDrawable.cpp ImageDrawable.h HeadTop.cpp HeadTop.h VickyFactory.cpp VickyFactory.h Timeline.cpp Timeline.h TimelineDlg.cpp TimelineDlg.h AnimChannel.cpp AnimChannel.h AnimChannelAngle.cpp AnimChannelAngle.h AnimChannelPoint.cpp AnimChannelPoint.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)