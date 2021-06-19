cmake_minimum_required(VERSION 3.12)
project(rusty VERSION 0.2.1)

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

    rusty/frames/delegates/software_license_delegate.cpp
    rusty/frames/delegates/software_license_delegate.h
    rusty/frames/models/license_parser.cpp
    rusty/frames/models/license_parser.h
    rusty/frames/models/software_license_model.cpp
    rusty/frames/models/software_license_model.h
    rusty/frames/software_license_window.cpp
    rusty/frames/software_license_window.h

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

    rusty/widgets/adwaita_style.cpp
    rusty/widgets/adwaita_style.h
    rusty/widgets/grayscale_effect.cpp
    rusty/widgets/grayscale_effect.h
    rusty/widgets/icon_button.cpp
    rusty/widgets/icon_button.h
    rusty/widgets/menu_row_actions.cpp
    rusty/widgets/menu_row_actions.h
    rusty/widgets/rusty_style.cpp
    rusty/widgets/rusty_style.h
    rusty/widgets/separator_line.cpp
    rusty/widgets/separator_line.h
    rusty/widgets/switch_button.cpp
    rusty/widgets/switch_button.h
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
    Qt5::Svg
    Qt5::Widgets

    adwaita-qt-static
    breakpad_static
    CuteLogger
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
  add_subdirectory(rusty/third_party/googletest)
  add_executable(rusty-tests
      ${TEST_FILES}
      )
  target_link_libraries(rusty-tests
      Qt5::Core
      Qt5::Svg
      gtest

      rusty-static
      )
  add_test(rusty-tests rusty-tests)
endif ()

if (BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
