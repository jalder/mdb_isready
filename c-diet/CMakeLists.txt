cmake_minimum_required(VERSION 3.11)
project(c-mdb_isready LANGUAGES C)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable (mdb_isready mdb_isready.c)

