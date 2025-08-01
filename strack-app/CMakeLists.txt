cmake_minimum_required(VERSION 3.22)

project(strack-app LANGUAGES CXX)

# ─── Qt Automatic MOC/UIC/RCC ────────────────────────────────────────────────
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ─── Locate Qt6 Widgets ──────────────────────────────────────────────────────
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ─── Include directories ─────────────────────────────────────────────────────
# Header dosyaları "include/" altında, include/ klasörü derleyiciye tanıtılıyor
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# ─── Collect sources ─────────────────────────────────────────────────────────
set(STRACK_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/strack-gui.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/MainWindow/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/MainWindow/Components/ApplicationMenuBar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/MainWindow/Components/FileExplorerWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/MainWindow/Components/CodeEditorWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/MainWindow/Components/ControlStripWidget.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Themes/LightTheme.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Themes/DarkTheme.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/StartupWindow/Components/ProjectActionsWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/StartupWindow/Components/RecentProjectsWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/StartupWindow/StartupWindow.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Windows/SettingsWindow/SettingsWindow.cpp
)

set(STRACK_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/MainWindow/MainWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/MainWindow/Components/ApplicationMenuBar.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/MainWindow/Components/FileExplorerWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/MainWindow/Components/CodeEditorWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/MainWindow/Components/ControlStripWidget.h

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Themes/Theme.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Themes/LightTheme.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Themes/DarkTheme.h

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/StartupWindow/Components/ProjectActionsWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/StartupWindow/Components/RecentProjectsWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/StartupWindow/StartupWindow.h

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Windows/SettingsWindow/SettingsWindow.h
)

# ─── Build executable ─────────────────────────────────────────────────────────
add_executable(strack
    ${STRACK_SOURCES}
    ${STRACK_HEADERS}  # for IDE visibility
)

# ─── Link Qt ──────────────────────────────────────────────────────────────────
target_link_libraries(strack PRIVATE Qt6::Widgets)

# ─── MSVC specific warnings suppression ──────────────────────────────────────
if (MSVC)
    target_include_directories(strack SYSTEM PRIVATE
        $<TARGET_PROPERTY:Qt6::Widgets,INTERFACE_INCLUDE_DIRECTORIES>
    )
    target_compile_options(strack PRIVATE /external:W0)
endif()

# ─── Windows deployment ──────────────────────────────────────────────────────
if (WIN32)
    set(WINDEPLOYQT_EXE "C:/Qt/6.9.1/msvc2022_64/bin/windeployqt.exe")
    add_custom_command(TARGET strack POST_BUILD
        COMMAND "${WINDEPLOYQT_EXE}" "$<TARGET_FILE:strack>"
    )
endif()
