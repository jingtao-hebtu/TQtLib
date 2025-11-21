# *  @Copyright (c) tao.jing
# *
# *
cmake_minimum_required(VERSION 3.26)
project(TQtLibOneDarkTest)


# Project Management
IF (NOT BASE_OUTPUT_DIR)
    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        set(BASE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin_debug)
    else()
        set(BASE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/bin_release)
    endif()
ELSE()
    set (BASE_OUTPUT_DIR ${BASE_OUTPUT_DIR})
ENDIF()


remove_definitions(-DBUILDING_DLL)


set(EXECUTABLE_OUTPUT_PATH ${BASE_OUTPUT_DIR}/${PROJECT_NAME})


include_directories(${T_QT_LIB_PATH}/Src/Inc)
include_directories(${T_QT_LIB_PATH}/Src/Inc/QtHelpers)
include_directories(${T_QT_LIB_PATH}/Src/Inc/QtWidgets)
include_directories(${T_QT_LIB_PATH}/Src/Inc/TUtilLib)


if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(T_QT_LIB TQtLibd)
    set(T_UTIL_LIB TUtilLibd)
else ()
    set(T_QT_LIB TQtLib)
    set(T_UTIL_LIB TUtilLib)
endif ()


set(ONE_DARK_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR})
aux_source_directory(${ONE_DARK_TEST_PATH}/Src ONE_DARK_TEST_SRC)
add_executable(${PROJECT_NAME} ${ONE_DARK_TEST_SRC})

set(ONE_DARK_TEST_SRC "${ONE_DARK_TEST_SRC};${ONE_DARK_TEST_PATH}/Res/img.qrc;")
set(ONE_DARK_TEST_SRC "${ONE_DARK_TEST_SRC};${ONE_DARK_TEST_PATH}/Res/rc.qrc;")

target_link_directories(${PROJECT_NAME} PUBLIC ${T_QT_LIB_OUTPUT_PATH})
target_link_directories(${PROJECT_NAME} PUBLIC ${T_UTIL_LIB_PATH})

target_link_libraries(${PROJECT_NAME}
        ${T_QT_LIB_QT_DEP_LIBS}
        ${T_QT_LIB}
        ${T_UTIL_LIB}
)


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${Qt6_Base_DIR}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()

    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_target(CreatePlatformDir_OneDark ALL
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "${EXECUTABLE_OUTPUT_PATH}/plugins/platforms/")
        add_custom_target(CopyPlatformDir_OneDark ALL
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "${EXECUTABLE_OUTPUT_PATH}/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${T_QT_LIB_QT_DEP_LIBS})
        string(REPLACE "Qt::" "" QT_LIB_NAME ${QT_LIB})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB_NAME}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
