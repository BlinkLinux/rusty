
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES
    resources/resources.qrc
    resources/resources.h

    internal/custom_style.cpp
    internal/custom_style.h
    internal/code_editor.cpp
    internal/code_editor.h
    internal/widgets_window.cpp
    internal/widgets_window.h
    )

add_executable(crash-demo
    crash_demo.cpp
    )
target_link_libraries(crash-demo
    Qt5::Core

    rusty-static
    )

add_executable(examples-main
    examples_main.cpp

    ${SOURCE_FILES}
    )
target_link_libraries(examples-main
    Qt5::Widgets
    rusty-static
    )