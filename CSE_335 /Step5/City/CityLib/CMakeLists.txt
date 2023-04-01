project(CityLib)

set(SOURCE_FILES
        pch.h
        City.h City.cpp
        Tile.h Tile.cpp
        CityReport.h CityReport.cpp
        MemberReport.h MemberReport.cpp
        TileBuilding.h TileBuilding.cpp
        TileCoalmine.h TileCoalmine.cpp
        TileGarden.h TileGarden.cpp
        TileLandscape.h TileLandscape.cpp
        TileRoad.h TileRoad.cpp
        TileRocketPad.h TileRocketPad.cpp
        MainFrame.cpp MainFrame.h
        CityView.cpp CityView.h ids.h TileVisitor.cpp TileVisitor.h BuildingCounter.cpp BuildingCounter.h CoalmineVisitor.cpp CoalmineVisitor.h BoostVisitor.cpp BoostVisitor.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)