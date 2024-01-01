cmake_minimum_required(VERSION 3.19)

project(camera-app CXX)

# Explicitly opt in to modern CMake behaviors to avoid warnings with recent
# versions of CMake.
if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTORCC ON)

set(HEADERS
    # include/api/controllers/cameraController.h
    # include/api/models/camera.h
)

set(SOURCES
    # src/api/controllers/cameraController.cpp
    # src/api/models/camera.cpp
    src/main.cpp
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

qt_add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} public/main.qrc)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickWidgets
    Qt6::QuickControls2
)

# Compiler options
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE -W3)

    # Disable warnings that give too many false positives.
    target_compile_options(${PROJECT_NAME} PRIVATE -wd4311 -wd4146 -wd4003 -wd4715)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic
        -Wno-unused-parameter
        -Wstrict-prototypes -Wshadow -Wconversion -Wvla
        -Wdouble-promotion
        -Wmissing-noreturn
        -Wmissing-format-attribute
        -Wmissing-prototypes
        -fsigned-char)
endif()

# -fstack-protector breaks Mingw-w64 builds
if(NOT MINGW)
    check_cxx_compiler_flag(-fstack-protector-strong HAS_FSTACK_PROTECTOR_STRONG_FLAG)
    if(HAS_FSTACK_PROTECTOR_STRONG_FLAG)
        target_compile_options(${PROJECT_NAME} PRIVATE -fstack-protector-strong)
    else()
        check_cxx_compiler_flag(-fstack-protector HAS_FSTACK_PROTECTOR_FLAG)
        if(HAS_FSTACK_PROTECTOR_FLAG)
            target_compile_options(${PROJECT_NAME} PRIVATE -fstack-protector
                --param ssp-buffer-size=4)
        endif()
    endif()
endif()
