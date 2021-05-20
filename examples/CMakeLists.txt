
add_executable(crash-demo
    crash_demo.cpp
    )
target_link_libraries(crash-demo
    Qt5::Core

    rusty-static
    )

add_executable(log-demo
    log_demo.cpp
    )
target_link_libraries(log-demo
    Qt5::Core

    rusty-static
    )

add_executable(style-demo
    style_demo.cpp
    edit/code_editor.cpp
    edit/code_editor.h
    )
target_link_libraries(style-demo
    Qt5::Widgets
    )