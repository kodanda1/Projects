project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h
        Polygon.cpp Polygon.h include/machine-api.h Shape.cpp Shape.h Machine1Factory.cpp Machine1Factory.h WorkingMachine.cpp WorkingMachine.h Component.cpp Component.h MachineActual.cpp MachineActual.h Motor.cpp Motor.h Machine2Factory.cpp Machine2Factory.h RotationSource.cpp RotationSource.h Gear.cpp Gear.h RotationSink.cpp RotationSink.h Arm.cpp Arm.h Lever.cpp Lever.h Rod.cpp Rod.h MovementSource.cpp MovementSource.h MovementSink.cpp MovementSink.h INegotiator.cpp INegotiator.h RodSink.cpp RodSink.h Piston.cpp Piston.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)