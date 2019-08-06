cmake_minimum_required(VERSION 3.14)
project(Snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS -Wall )
set(CMAKE_C_FLAGS -Werror)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_executable(Snake main.cpp caterpillar.c field.c fonctions.c caterpillar.h field.h fonctions.h)
target_link_libraries( ${PROJECT_NAME}  ${CURSES_LIBRARIES} )
