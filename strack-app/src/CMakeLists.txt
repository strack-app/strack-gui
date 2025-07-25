cmake_minimum_required(VERSION 3.22)
project(strack-app LANGUAGES CXX)

# ─── Qt Automatic MOC/UIC/RCC ────────────────────────────────────────────────
set(CMAKE_AUTOMOC   ON)
set(CMAKE_AUTOUIC   ON)
set(CMAKE_AUTORCC   ON)

# ─── Locate Qt6 Widgets ────────────────────────────────────────────────────
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# ─── Collect our sources ───────────────────────────────────────────────────
set(STRACK_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/strack-gui.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/ApplicationMenuBar.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/FileExplorerWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/CodeEditorWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/ControlStripWidget.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Themes/LightTheme.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Themes/DarkTheme.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/Components/ProjectActionsWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/Components/RecentProjectsWidget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/StartupWindow.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/SettingsWindow/SettingsWindow.cpp
)

set(STRACK_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/MainWindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/ApplicationMenuBar.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/FileExplorerWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/CodeEditorWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/MainWindow/Components/ControlStripWidget.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Themes/Theme.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Themes/LightTheme.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Themes/DarkTheme.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/Components/ProjectActionsWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/Components/RecentProjectsWidget.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/StartupWindow/StartupWindow.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Windows/SettingsWindow/SettingsWindow.h
)

# ─── Build the executable ──────────────────────────────────────────────────
add_executable(strack
    ${STRACK_SOURCES}
    ${STRACK_HEADERS}   # so that IDEs see them
)

# ─── Suppress Qt warnings on MSVC ──────────────────────────────────────────
if (MSVC)
    # Treat Qt include dirs as SYSTEM to silence warnings like C26495/C26813
    target_include_directories(strack SYSTEM PRIVATE
        $<TARGET_PROPERTY:Qt6::Widgets,INTERFACE_INCLUDE_DIRECTORIES>
    )
    # Globally disable external warnings
    target_compile_options(strack PRIVATE
        /external:W0
    )
endif()

# ─── Link against Qt6 Widgets ──────────────────────────────────────────────
target_link_libraries(strack PRIVATE Qt6::Widgets)

# ─── Windows deployment helper ─────────────────────────────────────────────
if (WIN32)
    set(WINDEPLOYQT_EXE "C:/Qt/6.9.1/msvc2022_64/bin/windeployqt.exe")
    add_custom_command(TARGET strack POST_BUILD
        COMMAND "${WINDEPLOYQT_EXE}" "$<TARGET_FILE:strack>"
    )
endif()
