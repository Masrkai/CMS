cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_COLOR_MAKEFILE ON)

project(CMS)
add_executable(CMS Project.cpp )
install(TARGETS CMS RUNTIME DESTINATION bin)