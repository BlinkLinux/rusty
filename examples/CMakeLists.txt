
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES
    demo/code_editor.cpp
    demo/code_editor.h
    demo/widgets_window.cpp
    demo/widgets_window.h
    )

add_executable(crash-demo
    crash_demo.cpp
    )
target_link_libraries(crash-demo
    Qt5::Core

    rusty-static
    )

add_executable(style-demo
    style_demo.cpp

    ${SOURCE_FILES}
    )
target_link_libraries(style-demo
    Qt5::Widgets
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