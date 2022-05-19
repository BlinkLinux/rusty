
set(Adwaita_SRCS
    adwaitahelper.cpp
    adwaitastyle.cpp
)

add_definitions(-DQT_PLUGIN)

if (MSVC)
    add_definitions(-D_USE_MATH_DEFINES) # Needed for M_PI on MSVC
endif()

set(LIBRARY_NAME "adwaita-qt-static")

add_library(${LIBRARY_NAME} STATIC ${Adwaita_SRCS})
target_include_directories(${LIBRARY_NAME}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/../lib # for adwaita-config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib

    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${LIBRARY_NAME}
    adwaitaqt
    adwaitaqtpriv
    Qt5::Core
    Qt5::DBus
    Qt5::Gui
    Qt5::Widgets
)

if (ADWAITA_HAVE_X11)
    target_link_libraries(${LIBRARY_NAME} ${XCB_LIBRARIES} Qt5::X11Extras)

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(X11XCB REQUIRED x11-xcb)
    target_include_directories(${LIBRARY_NAME} PRIVATE ${X11xcb_INCLUDE_DIRS})
    target_link_libraries(${LIBRARY_NAME} ${X11XCB_LIBRARIES})
endif()

if (NOT APPLE AND NOT WIN32)
    set_target_properties(${LIBRARY_NAME} PROPERTIES
        LINK_FLAGS "-Wl,--no-undefined"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        OUTPUT_NAME "adwaita"
        PREFIX "")
endif()
