cmake_minimum_required(VERSION 3.20)

idf_component_register()

tiny_library_named(tiny)
tiny_library_include_directories_public(${PROJECT_DIR}/include)
add_subdirectory(${PROJECT_DIR}/src)
target_link_libraries(${COMPONENT_LIB} INTERFACE tiny)
