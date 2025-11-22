cmake_minimum_required(VERSION 3.11)
project(c-mdb_isready LANGUAGES C)
set(BUILD_SHARED_LIBS OFF)
add_executable (mdb_isready mdb_isready.c)
find_package(mongoc-1.0 1.23.1 REQUIRED)
find_package(bson-1.0 REQUIRED)
#target_link_options(mdb_isready PRIVATE "-Wl,-Bstatic")
target_link_libraries(mdb_isready PRIVATE mongo::bson_static mongo::mongoc_static)

