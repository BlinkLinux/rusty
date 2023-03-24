cmake_minimum_required(VERSION 3.12)
project(rusty VERSION 0.3.1)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 5.11 COMPONENTS Svg Widgets OpenGL REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(SOURCE_FILES
    rusty/base/file.cpp
    rusty/base/file.h
    rusty/base/process.cpp
    rusty/base/process.h

    rusty/formats/color_palette.cpp
    rusty/formats/color_palette.h
    rusty/formats/license_parser.cpp
    rusty/formats/license_parser.h

    rusty/gui/color.cpp
    rusty/gui/color.h
    rusty/gui/color_validator.cpp
    rusty/gui/color_validator.h
    rusty/gui/image.cpp
    rusty/gui/image.h
    rusty/gui/theme_file.cpp
    rusty/gui/theme_file.h

    rusty/opengl/fps_counter.cpp
    rusty/opengl/fps_counter.h

    rusty/widgets/color_channel_label.cpp
    rusty/widgets/color_channel_label.h
    rusty/widgets/color_channel_line_edit.cpp
    rusty/widgets/color_channel_line_edit.h
    rusty/widgets/color_chooser_button.cpp
    rusty/widgets/color_chooser_button.h
    rusty/widgets/color_chooser_dialog.cpp
    rusty/widgets/color_chooser_dialog.h
    rusty/widgets/color_chooser_widget.cpp
    rusty/widgets/color_chooser_widget.h
    rusty/widgets/color_line_edit.cpp
    rusty/widgets/color_line_edit.h
    rusty/widgets/color_palette_list_view.cpp
    rusty/widgets/color_palette_list_view.h
    rusty/widgets/delegates/color_palette_delegate.cpp
    rusty/widgets/delegates/color_palette_delegate.h
    rusty/widgets/delegates/software_license_delegate.cpp
    rusty/widgets/delegates/software_license_delegate.h
    rusty/widgets/flat_button.cpp
    rusty/widgets/flat_button.h
    rusty/widgets/form_section.cpp
    rusty/widgets/form_section.h
    rusty/widgets/form_section_title.cpp
    rusty/widgets/form_section_title.h
    rusty/widgets/grayscale_effect.cpp
    rusty/widgets/grayscale_effect.h
    rusty/widgets/hsv_color_picker.cpp
    rusty/widgets/hsv_color_picker.h
    rusty/widgets/icon_button.cpp
    rusty/widgets/icon_button.h
    rusty/widgets/line_edit.cpp
    rusty/widgets/line_edit.h
    rusty/widgets/menu_row_actions.cpp
    rusty/widgets/menu_row_actions.h
    rusty/widgets/models/color_palette_model.cpp
    rusty/widgets/models/color_palette_model.h
    rusty/widgets/models/software_license_model.cpp
    rusty/widgets/models/software_license_model.h
    rusty/widgets/nav/left_panel_buttons.cpp
    rusty/widgets/nav/left_panel_buttons.h
    rusty/widgets/nav/nav_bar.cpp
    rusty/widgets/nav/nav_bar.h
    rusty/widgets/nav/tab_button.cpp
    rusty/widgets/nav/tab_button.h
    rusty/widgets/rusty_style.cpp
    rusty/widgets/rusty_style.h
    rusty/widgets/separator_line.cpp
    rusty/widgets/separator_line.h
    rusty/widgets/software_license_window.cpp
    rusty/widgets/software_license_window.h
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
    rusty/formats/tests/tests.qrc
    rusty/formats/color_palette_test.cpp

    rusty/tests/rusty_test_main.cpp

    rusty/gui/tests/tests.qrc
    rusty/gui/color_test.cpp
    rusty/gui/image_test.cpp
    rusty/gui/theme_file_test.cpp
    )

set(LINK_LIBS
    Qt5::Svg
    Qt5::Widgets
    Qt5::OpenGL
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
if (CMAKE_BUILD_TYPE MATCHES Debug)
  # See https://fuzzing-project.org/tutorial-cflags.html.
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(rusty-static PRIVATE -Wall -Werror -Wextra -fno-exceptions)
  endif()
endif ()

if (BUILD_TESTING)
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
