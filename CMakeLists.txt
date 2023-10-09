cmake_minimum_required(VERSION 3.8)	

project(QtDb VERSION 1.0.0 LANGUAGES CXX)			

set(SOURCE main.cpp app.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    ${SOURCE}
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)