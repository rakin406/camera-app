cmake_minimum_required(VERSION 3.25)
project(camera-app CXX)

# Explicitly opt in to modern CMake behaviors to avoid warnings with recent
# versions of CMake.
cmake_policy(SET CMP0063 NEW)

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

set(FORMS
    src/views/camera.ui
)

find_package(Qt6 REQUIRED COMPONENTS Core Multimedia MultimediaWidgets Widgets)
qt_standard_project_setup()

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    Qt6::Widgets
)

# MSVC flags
set(MSVC_DEBUG_FLAGS /W4 /Wall /WX /DEBUG /Z7)
set(MSVC_RELEASE_FLAGS /W4 /Wall /Ox)

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
set(GCC_RELEASE_FLAGS -Wall -Wextra $<$<COMPILE_LANGUAGE:CXX>:-Wold-style-cast>
                      -Wno-unused-parameter -O3)

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
