cmake_minimum_required (VERSION 3.0)

project(BZ205_Odev)
set(CMAKE_CXX_STANDARD 17)
file(GLOB PROJECT_SOURCES "*.cpp")

add_executable (BZ205_Odev ${PROJECT_SOURCES})
