# *  @Copyright (c) tao.jing
# *
# *

# ---- QT6 Package ----
set(Qt6_Version "6.9.1")

set(Qt6_Base_DIR "D:/Software/Qt/${Qt6_Version}/msvc2022_64")
set(Qt6_DIR "D:/Software/Qt/${Qt6_Version}/msvc2022_64")
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${Qt6_DIR};")
set(ENV{PATH} "${Qt6_DIR}/bin;$ENV{PATH}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        MultimediaWidgets
        Charts
        SerialPort
        Concurrent
        Network
        Svg
        SvgWidgets
        REQUIRED)


if (Qt6_FOUND)
    set(QT6_FOUND TRUE CACHE INTERNAL "Qt6 is found.")
else ()
    MESSAGE(FATAL_ERROR, "Qt6 not found.")
endif ()