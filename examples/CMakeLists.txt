
add_executable(crash-demo
    crash_demo.cpp
    )
target_link_libraries(crash-demo
    Qt5::Core

    rusty-static
    )