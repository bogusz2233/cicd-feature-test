cmake_minimum_required(VERSION 3.18)

# =====================================
#   Project flags
# =====================================
option(BUILD_UNIT_TESTS         "If this flag is enabled, unit tests will be built"                 OFF)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(BUILD_UNIT_TESTS)
    set(TARGET_NAME "unit_test")
else()
    set(TARGET_NAME "ccw_collector")
endif()

project(${TARGET_NAME} VERSION 0.7.2 LANGUAGES CXX)

find_package(Threads)
add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

add_subdirectory(externals)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    -Wall
    -Wextra

    # Enable colorized output
    $<$<CXX_COMPILER_ID:GNU>:-fdiagnostics-color=always>
)

target_link_options(
    ${PROJECT_NAME}
    PRIVATE
    -Wl,-Map=${PROJECT_NAME}.map
)


if(BUILD_UNIT_TESTS)
    enable_library(${GOOGLE_TEST_LIBRARY_NAME})
    include(CTest)
    include(GoogleTest)
    enable_testing()

    add_subdirectory(unit_tests)

    gtest_discover_tests(${PROJECT_NAME})
else()
    target_sources(
        ${PROJECT_NAME}
        PRIVATE
        src/main.cpp
    )
endif()

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    include
)

add_subdirectory(src)
