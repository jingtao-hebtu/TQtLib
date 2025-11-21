# *  @Copyright (c) tao.jing
# *
# *

cmake_minimum_required(VERSION 3.26)
project(TQtLib)


# ---- Compilations ----
set(CMAKE_CXX_STANDARD 20)
set(BUILD_SHARED_LIBS ON)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


# --- Project Management ---
IF (NOT BASE_OUTPUT_DIR)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(BASE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin_debug)
    else ()
        set(BASE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin_release)
    endif ()
ELSE ()
    set(BASE_OUTPUT_DIR ${BASE_OUTPUT_DIR})
ENDIF ()

set(LIBRARY_OUTPUT_PATH ${BASE_OUTPUT_DIR}/${PROJECT_NAME})
set(EXECUTABLE_OUTPUT_PATH ${BASE_OUTPUT_DIR}/${PROJECT_NAME})
set(T_QT_LIB_OUTPUT_PATH ${BASE_OUTPUT_DIR}/${PROJECT_NAME})


set(T_QT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR})


if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(T_UTIL_LIB TUtilLibd)
    set(T_UTIL_LIB_PATH "E:/Code/Cpp/Base/TUtilLib_Github/build/bin_debug/TUtilLib/")
else ()
    set(T_UTIL_LIB TUtilLib)
    set(T_UTIL_LIB_PATH "E:/Code/Cpp/Base/TUtilLib_Github/build/bin_release/TUtilLib/")
endif ()


set(T_QT_LIB_QT_DEP_LIBS
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
        Qt::Svg
        Qt::SvgWidgets
        Qt::OpenGL
        Qt::OpenGLWidgets
)


include(${T_QT_LIB_PATH}/CMake/TQtLib.cmake)

add_subdirectory(Tests)