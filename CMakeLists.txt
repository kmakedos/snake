cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
project(Snake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework system filesystem date_time)
find_package(Curses REQUIRED)
include_directories (${Boost_INCLUDE_DIRS} ${CURSES_INCLUDE_DIR})

include_directories(.)
add_executable(Snake main.cpp Snake.cpp sWindow.cpp)
target_link_libraries(Snake ${Boost_LIBRARIES} ${CURSES_LIBRARIES})
add_subdirectory(test)
