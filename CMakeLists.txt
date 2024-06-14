cmake_minimum_required(VERSION 3.5)

project(MetaX-Win VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    registry_op.cc
    main_window.cc
    main.cc
)

add_executable(MetaX-Windows ${PROJECT_SOURCES})
target_link_libraries(MetaX-Windows Qt${QT_VERSION_MAJOR}::Widgets)
