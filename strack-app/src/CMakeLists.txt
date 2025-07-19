cmake_minimum_required(VERSION 3.22)
project(strack-gui LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(strack
    strack-gui.cpp
    strack-gui.h
)

target_link_libraries(strack PRIVATE Qt6::Widgets)

# Replace the Qt path with the path on your machine.
if (WIN32)
    set(WINDEPLOYQT_EXE "C:/Qt/6.9.1/msvc2022_64/bin/windeployqt.exe")

    add_custom_command(TARGET strack POST_BUILD
        COMMAND "${WINDEPLOYQT_EXE}" "$<TARGET_FILE:strack>"
    )
endif()