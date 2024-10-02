set(SPDLOG_LIBRARY_NAME         "spdlog"        PARENT_SCOPE)
set(GOOGLE_TEST_LIBRARY_NAME    "googletest"    PARENT_SCOPE)

#[[
    This function is used to add library from externals directory.

    args:
        LIB_NAME name of library which is wanted to add.
#]]
function(enable_library LIB_NAME)
    if(NOT EXISTS ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/${LIB_NAME})
        message(FATAL_ERROR "Cannot find '${LIB_NAME}' library")
    endif()

    add_subdirectory(${CMAKE_CURRENT_FUNCTION_LIST_DIR}/${LIB_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME})
endfunction()
