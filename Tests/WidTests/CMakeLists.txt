# *  @Copyright (c) tao.jing
# *
# *
cmake_minimum_required(VERSION 3.26)
project(TQtLibWidTests)


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
else ()
    set(T_QT_LIB TQtLib)
endif ()


# --- QtHelpersTest ---
add_executable(QtHelpersTest QtHelpersTest.cpp)

target_link_directories(QtHelpersTest PUBLIC ${T_QT_LIB_OUTPUT_PATH})
target_link_directories(QtHelpersTest PUBLIC ${T_UTIL_LIB_PATH})

target_link_libraries(QtHelpersTest
        ${T_QT_LIB_QT_DEP_LIBS}
        ${T_QT_LIB}
)


list(APPEND Qt_Wid_Tests
        QtWidgetsTest
        QLeftMenuTest
        QLeftColumnTest
        QTitleBarTest
        QGripsTest
)

foreach (Qt_Wid_Test ${Qt_Wid_Tests})
    add_executable(${Qt_Wid_Test} ${Qt_Wid_Test}.cpp)

    target_link_directories(${Qt_Wid_Test} PUBLIC ${T_QT_LIB_OUTPUT_PATH})
    target_link_directories(${Qt_Wid_Test} PUBLIC ${T_UTIL_LIB_PATH})

    target_link_libraries(${Qt_Wid_Test}
            ${T_QT_LIB_QT_DEP_LIBS}
            ${T_QT_LIB}
            ${T_UTIL_LIB}
    )
endforeach ()



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
        add_custom_target(CreatePlatformDir ALL
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "${EXECUTABLE_OUTPUT_PATH}/plugins/platforms/")
        add_custom_target(CopyPlatformDir ALL
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "${EXECUTABLE_OUTPUT_PATH}/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${T_QT_LIB_QT_DEP_LIBS})
        string(REPLACE "Qt::" "" QT_LIB_NAME ${QT_LIB})
        add_custom_target(CopyQtDll_${QT_LIB_NAME} ALL
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB_NAME}${DEBUG_SUFFIX}.dll"
                "${EXECUTABLE_OUTPUT_PATH}")
    endforeach (QT_LIB)
endif ()
