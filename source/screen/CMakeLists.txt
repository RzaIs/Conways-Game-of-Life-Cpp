#creating new library
add_library(screen screen.cpp)

# finding required package
find_package(
  SDL2 REQUIRED
)

# linking included libraries
target_link_libraries(screen
  ${SDL2_LIBRARIES}
)

# importing include directory
target_include_directories(screen
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} 
  PUBLIC ${SDL2_INCLUDE_DIRS}
)
