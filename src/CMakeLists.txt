target_sources(
    ${PROJECT_NAME}
    PRIVATE
    app_info.cpp
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_SOURCE_DIR}
)