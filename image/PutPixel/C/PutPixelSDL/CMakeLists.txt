cmake_minimum_required(VERSION 3.1)
# Name of the project
set(PROJECT_NAME PutPixel)
project(${PROJECT_NAME})
set(SOURCES PutPixel.c  )
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add exe and link libs that must be after the other defines
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image)

