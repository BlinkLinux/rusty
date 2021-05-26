cmake_minimum_required(VERSION 3.12)
project(rusty)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 5.12 COMPONENTS Core Gui Svg Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(rusty/third_party/adwaita-qt)
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

    rusty/gui/color.cpp
    rusty/gui/color.h
    rusty/gui/image.cpp
    rusty/gui/image.h
    rusty/gui/theme_file.cpp
    rusty/gui/theme_file.h

    rusty/widgets/nav/left_panel_buttons.cpp
    rusty/widgets/nav/left_panel_buttons.h
    rusty/widgets/nav/nav_bar.cpp
    rusty/widgets/nav/nav_bar.h
    rusty/widgets/nav/tab_button.cpp
    rusty/widgets/nav/tab_button.h

    rusty/widgets/adwaita_style.h
    rusty/widgets/icon_button.cpp
    rusty/widgets/icon_button.h
    rusty/widgets/menu_row_actions.cpp
    rusty/widgets/menu_row_actions.h
    rusty/widgets/rusty_style.cpp
    rusty/widgets/rusty_style.h
    rusty/widgets/separator_line.cpp
    rusty/widgets/separator_line.h
    rusty/widgets/text_button.cpp
    rusty/widgets/text_button.h
    rusty/widgets/theme_manager.cpp
    rusty/widgets/theme_manager.h
    rusty/widgets/utils.cpp
    rusty/widgets/utils.h
    )

set(TEST_FILES
    rusty/tests/rusty_test_main.cpp

    rusty/gui/color_test.cpp
    rusty/gui/image_test.cpp
    rusty/gui/tests/tests.qrc
    rusty/gui/theme_file_test.cpp
    )

set(LINK_LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::GuiPrivate
    Qt5::Svg
    Qt5::Widgets

    adwaita-qt-static
    breakpad_static
    CuteLogger
    )

# NOTE(Shaohua): Disable shared lib.
#add_library(rusty SHARED
#    ${SOURCE_FILES}
#    )
#target_link_libraries(rusty
#    ${LINK_LIBS}
#    )
#target_include_directories(rusty
#    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
#    )

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
