#creating new library
add_library(ansi ansi.cpp)

# importing include directory
target_include_directories(ansi
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)