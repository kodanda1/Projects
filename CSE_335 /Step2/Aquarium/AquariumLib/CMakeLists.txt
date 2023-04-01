project(AquariumLib)

set(SOURCE_FILES)
set(SOURCE_FILES pch.h MainFrame.cpp MainFrame.h AquariumView.cpp AquariumView.h Aquarium.cpp Aquarium.h Item.cpp Item.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)