cmake_minimum_required(VERSION 3.1)
# Name of the project
set(PROJECT_NAME PutPixel)
project(${PROJECT_NAME})
# use C++ 14
set(CMAKE_CXX_STANDARD 14)
set(SOURCES PutPixel.cpp  )

# add exe and link libs that must be after the other defines
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} OpenImageIO OpenImageIO_Util )

