# *  @Copyright (c) tao.jing
# *
# *

cmake_minimum_required(VERSION 3.26)
project(TQtLib)


IF (NOT T_QT_LIB_PATH)
    set (T_QT_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR})
ELSE()
    set (T_QT_LIB_PATH ${T_QT_LIB_PATH})
ENDIF()

add_definitions(-DBUILDING_DLL)

# --- Qt ---
set(Qt6_Version "6.7.2")
include(${T_QT_LIB_PATH}/CMake/QtLib.cmake)

set(T_QT_LIB_SRC_PATH ${T_QT_LIB_PATH}/Src/Src)
set(T_QT_LIB_INC_PATH ${T_QT_LIB_PATH}/Src/Inc)

###################
## TUtilLib Src  ##
###################
include_directories(${T_QT_LIB_INC_PATH}/TUtilLib)


#################
## TQtLib Src  ##
#################
list(APPEND Qt_Wid_Src_Dirs
        #${T_QT_LIB_SRC_PATH}/QtWidgets
        ${T_QT_LIB_SRC_PATH}/QtCurve
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TToolTip
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TFormatWid
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TDraggableWidget
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TTitleBar
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TCreditsBar
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TCircularProgress
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TIconButton
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TLineEdit
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TPushButton
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TSlider
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TTableWidget
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TToggleBox
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TWindow
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TLeftMenu
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TGrips
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TLeftColumn
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TRightColumn
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TFramelessWidget
        ${T_QT_LIB_SRC_PATH}/QtWidgets/TWidHelpers
)

# Qt Helper
include_directories(${T_QT_LIB_INC_PATH}/QtHelpers)
aux_source_directory(${T_QT_LIB_SRC_PATH}/QtHelpers T_QT_HELPERS_SRC)


# Qt Widgets
#include_directories(${T_QT_LIB_INC_PATH}/QtWidgets)
foreach (Dir ${Qt_Wid_Src_Dirs})
    include_directories (${Dir})
    aux_source_directory (${Dir} T_QT_LIB_WIDGET_SRC)
endforeach ()

set(T_QT_LIB_WIDGET_SRC "${T_QT_LIB_WIDGET_SRC};${T_QT_LIB_SRC_PATH}/QtWidgets/TResources/rc.qrc;")
set(T_QT_LIB_WIDGET_SRC "${T_QT_LIB_WIDGET_SRC};${T_QT_LIB_SRC_PATH}/QtWidgets/TResources/img.qrc;")

set(T_QT_LIB_SRC "${T_QT_HELPERS_SRC};${T_QT_LIB_WIDGET_SRC};")


add_library(${PROJECT_NAME} ${T_QT_LIB_SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS OFF)
endif()

target_link_directories(${PROJECT_NAME} PUBLIC ${T_UTIL_LIB_PATH})


target_link_libraries(${PROJECT_NAME} PUBLIC
        ${T_QT_LIB_QT_DEP_LIBS}
        ${T_UTIL_LIB}
)
