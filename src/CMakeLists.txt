
find_package(Qt5 5.12 COMPONENTS Core Gui Svg Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set current directory as root of header files.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(base)