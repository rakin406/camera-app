cmake_minimum_required(VERSION 3.16)

project(camera-app VERSION 1.0 LANGUAGES CXX)

# Explicitly opt in to modern CMake behaviors to avoid warnings with recent
# versions of CMake.
cmake_policy(SET CMP0063 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HEADERS
    include/api/controllers/cameraController.h
    include/api/models/camera.h
)

set(SOURCES
    src/api/controllers/cameraController.cpp
    src/api/models/camera.cpp
    src/app/main.cpp
)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Multimedia
    MultimediaWidgets
    Qml
    Quick
    QuickWidgets
    QuickControls2
)
qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_source_files_properties(views/camera.qml PROPERTIES
    QT_RESOURCE_ALIAS camera.qml
)

qt_add_qml_module(${PROJECT_NAME}
    URI views
    VERSION 1.0
    QML_FILES
        views/camera.qml
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
)

# MSVC flags
set(MSVC_DEBUG_FLAGS /W4 /Wall /WX /DEBUG /Z7)
set(MSVC_RELEASE_FLAGS
    /W4
    /Wall
    /Ox
    # WARNING: The following flags are not tested.
    /QT_NO_DEBUG_OUTPUT
    /QT_NO_INFO_OUTPUT
    /QT_NO_WARNING_OUTPUT
    /QT_NO_DEBUG
)

# GCC and other compiler flags
set(GCC_DEBUG_FLAGS
    -Wall
    -Wextra
    -Werror
    $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
    -Wno-unused-parameter
    -g3
    -ggdb
)
set(GCC_RELEASE_FLAGS
    -Wall
    -Wextra
    $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
    -Wno-unused-parameter
    -O3
    # Qt flags
    -QT_NO_DEBUG_OUTPUT
    -QT_NO_INFO_OUTPUT
    -QT_NO_WARNING_OUTPUT
    -QT_NO_DEBUG
)

if(MSVC)
  target_compile_options(${PROJECT_NAME}
                         PRIVATE "$<$<CONFIG:DEBUG>:SHELL:${MSVC_DEBUG_FLAGS}>")
  target_compile_options(
    ${PROJECT_NAME} PRIVATE "$<$<CONFIG:RELEASE>:SHELL:${MSVC_RELEASE_FLAGS}>")
else()
  target_compile_options(${PROJECT_NAME}
                         PRIVATE "$<$<CONFIG:DEBUG>:SHELL:${GCC_DEBUG_FLAGS}>")
  target_compile_options(
    ${PROJECT_NAME} PRIVATE "$<$<CONFIG:RELEASE>:SHELL:${GCC_RELEASE_FLAGS}>")
endif()
