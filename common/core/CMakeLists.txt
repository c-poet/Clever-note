list_include_file(INC_FILE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/inc")
list_source_file(SRC_FILE_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_library(core SHARED ${INC_FILE_LIST} ${SRC_FILE_LIST})
target_link_libraries(core PUBLIC Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(core PUBLIC logger)
add_subdirectory(test)
