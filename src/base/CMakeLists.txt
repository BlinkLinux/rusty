
set(SOURCES
    file.cpp
    file.h
    process.cpp
    process.h
    )
set(TEST_FILES
    )

add_library(base-static STATIC
    ${SOURCES}
    )
target_link_libraries(base-static
    Qt5::Core
    Qt5::Gui
    )

if (BUILD_TESTING)
  add_executable(base-tests
      ${TEST_FILES}
      )
  target_link_libraries(base-tests
      Qt5::Core
      Qt5::Svg

      base-static
      )
  add_test(base-tests base-tests)
endif()