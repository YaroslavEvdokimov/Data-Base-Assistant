cmake_minimum_required(VERSION 3.8)	

project(DataBaseAssistant)			

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB_RECURSE SOURCES handler/*.h handler/*.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE ui/mainwindow.ui ui/mainwindow.h ui/mainwindow.cpp ui/tree.ui ui/tree.h ui/tree.cpp
    ui/status_bar_button.ui ui/status_bar_button.h ui/status_bar_button.cpp
    ui/Item.ui ui/Item.h ui/Item.cpp
    ui/ItemTable.ui ui/ItemTable.h ui/ItemTable.cpp)

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCE}
    main.cpp libs/sqlite/sqlite3.c 
    libs/sqlite/sqlite3.h
)

target_include_directories(${PROJECT_NAME} PRIVATE libs)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets)