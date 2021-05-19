
find_package(Qt5 5.12 COMPONENTS Core Gui Svg Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set current directory as root of header files.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    base/file.cpp
    base/file.h
    base/process.cpp
    base/process.h
    base/zip.cpp
    base/zip.h
    )
set(TEST_FILES

    )

set(LINK_LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::GuiPrivate
    Qt5::Svg
    )

add_library(rusty SHARED
    ${SOURCE_FILES}
    )
target_link_libraries(rusty
    ${LINK_LIBS}
    )

add_library(rusty-static STATIC
    ${SOURCE_FILES}
    )
target_link_libraries(rusty-static
    ${LINK_LIBS}
    )

if (BUILD_TESTING)
  add_executable(rusty-tests
      ${TEST_FILES}
      )
  target_link_libraries(rusty-tests
      Qt5::Core
      Qt5::Svg

      rusty-static
      )
  add_test(rusty-tests rusty-tests)
endif()
