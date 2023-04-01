project(Tests)

set(TEST_FILES
    gtest_main.cpp
    EmptyTest.cpp AquariumTest.cpp ItemTest.cpp FishBetaTest.cpp)

# Get Google Tests
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include Google Test directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the Tests_run target
add_executable(Tests_run ${TEST_FILES})

# linking Tests_run with library which will be tested, wxWidgets, and gtest
target_link_libraries(Tests_run ${APPLICATION_LIBRARY} ${wxWidgets_LIBRARIES} gtest)

target_precompile_headers(Tests_run PRIVATE ../${APPLICATION_LIBRARY}/pch.h)
