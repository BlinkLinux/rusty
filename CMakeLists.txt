cmake_minimum_required(VERSION 3.12)
project(rusty)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 5.12 COMPONENTS Core Gui Svg Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(rusty/third_party/breakpad)
add_subdirectory(rusty/third_party/CuteLogger)

set(SOURCE_FILES
    rusty/base/crash_reporter.cpp
    rusty/base/crash_reporter.h
    rusty/base/file.cpp
    rusty/base/file.h
    rusty/base/log_manager.cpp
    rusty/base/log_manager.h
    rusty/base/process.cpp
    rusty/base/process.h
    rusty/base/zip.h

    rusty/gui/theme_file.cpp
    rusty/gui/theme_file.h
    )

set(TEST_FILES
    rusty/tests/rusty_test_main.cpp

    rusty/gui/tests/tests.qrc
    rusty/gui/theme_file_test.cpp
    )

set(LINK_LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::GuiPrivate
    Qt5::Svg

    breakpad_static
    CuteLogger
    )

add_library(rusty SHARED
    ${SOURCE_FILES}
    )
target_link_libraries(rusty
    ${LINK_LIBS}
    )
target_include_directories(rusty
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )

add_library(rusty-static STATIC
    ${SOURCE_FILES}
    )
target_link_libraries(rusty-static
    ${LINK_LIBS}
    )
target_include_directories(rusty-static
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )

if (BUILD_TESTING)
  # TODO(Shaohua): Replace with embedded version.
  find_package(GTest REQUIRED)
  add_executable(rusty-tests
      ${TEST_FILES}
      )
  target_link_libraries(rusty-tests
      Qt5::Core
      Qt5::Svg

      GTest::GTest

      rusty-static
      )
  add_test(rusty-tests rusty-tests)
endif ()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()