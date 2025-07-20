cmake_minimum_required(VERSION 3.22)
project(strack-gui LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(strack
    strack-gui.cpp
    
    "Windows/MainWindow/MainWindow.cpp" 
    "Windows/MainWindow/MainWindow.h" 
    "Windows/MainWindow/Components/ApplicationMenuBar.cpp" 
    "Windows/MainWindow/Components/ApplicationMenuBar.h" 
    "Windows/MainWindow/Components/FileExplorerWidget.h" 
    "Windows/MainWindow/Components/FileExplorerWidget.cpp" 
    "Windows/MainWindow/Components/CodeEditorWidget.cpp" 
    "Windows/MainWindow/Components/CodeEditorWidget.h" 
    "Themes/Theme.h" 
    "Themes/LightTheme.cpp" 
    "Themes/LightTheme.h"  
    "Themes/DarkTheme.h" 
    "Themes/DarkTheme.cpp"
    "Windows/StartupWindow/Components/ProjectActionsWidget.cpp" 
    "Windows/StartupWindow/Components/ProjectActionsWidget.h" 
    "Windows/StartupWindow/Components/RecentProjectsWidget.cpp" 
    "Windows/StartupWindow/Components/RecentProjectsWidget.h" 
    "Windows/StartupWindow/StartupWindow.h" 
    "Windows/StartupWindow/StartupWindow.cpp"
)

target_link_libraries(strack PRIVATE Qt6::Widgets)

# Replace the Qt path with the path on your machine.
if (WIN32)
    set(WINDEPLOYQT_EXE "C:/Qt/6.9.1/msvc2022_64/bin/windeployqt.exe")

    add_custom_command(TARGET strack POST_BUILD
        COMMAND "${WINDEPLOYQT_EXE}" "$<TARGET_FILE:strack>"
    )
endif()