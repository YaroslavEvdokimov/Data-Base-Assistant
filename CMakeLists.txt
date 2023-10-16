cmake_minimum_required(VERSION 3.8)	

project(QtDb VERSION 1.0.0 LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR} ${CMAKE_SYSROOT}/usr/local/include)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB_RECURSE SOURCES handler/*.h handler/*.cpp)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp app.cpp libs/sqlite/sqlite3.c)

target_include_directories(${PROJECT_NAME} PRIVATE libs libs/sqlite)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)