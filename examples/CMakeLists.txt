
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES
    resources/resources.qrc
    resources/resources.h

    internal/widgets_window.cpp
    internal/widgets_window.h
    )

add_executable(examples-main
    examples_main.cpp

    ${SOURCE_FILES}
    )
target_link_libraries(examples-main
    Qt5::Widgets
    rusty-static
    )