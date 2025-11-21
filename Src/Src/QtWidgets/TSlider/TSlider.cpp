/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TSlider.cpp
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#include "TSlider.h"


namespace T_QtBase {

    static TFormatString TSliderStyleString = R"(
        /* HORIZONTAL */
        QSlider { margin: {margin}px; }
        QSlider::groove:horizontal {
            border-radius: {bg_radius}px;
            height: {bg_size}px;
            margin: 0px;
            background-color: {bg_color};
        }
        QSlider::groove:horizontal:hover { background-color: {bg_color_hover}; }
        QSlider::handle:horizontal {
            border: none;
            height: {handle_size}px;
            width: {handle_size}px;
            margin: {handle_margin}px;
            border-radius: {handle_radius}px;
            background-color: {handle_color};
        }
        QSlider::handle:horizontal:hover { background-color: {handle_color_hover}; }
        QSlider::handle:horizontal:pressed { background-color: {handle_color_pressed}; }

        /* VERTICAL */
        QSlider::groove:vertical {
            border-radius: {bg_radius}px;
            width: {bg_size}px;
            margin: 0px;
            background-color: {bg_color};
        }
        QSlider::groove:vertical:hover { background-color: {bg_color_hover}; }
        QSlider::handle:vertical {
            border: none;
            height: {handle_size}px;
            width: {handle_size}px;
            margin: {handle_margin}px;
            border-radius: {handle_radius}px;
            background-color: {handle_color};
        }
        QSlider::handle:vertical:hover { background-color: {handle_color_hover}; }
        QSlider::handle:vertical:pressed { background-color: {handle_color_pressed}; }
    )";

    static std::map<std::string, std::string> TSliderStyleDefaultParams{
            {"margin",               "0"},
            {"bg_size",              "20"},
            {"bg_radius",            "10"},
            {"bg_color",             "#1b1e23"},
            {"bg_color_hover",       "#1e2229"},

            {"handle_margin",        "2"},
            {"handle_size",          "16"},
            {"handle_radius",        "8"},
            {"handle_color",         "#568af2"},
            {"handle_color_hover",   "#6c99f4"},
            {"handle_color_pressed", "#3f6fd1"},
    };

    TSlider::TSlider(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QSlider(parent), TFormatWid(TSliderStyleString, TSliderStyleDefaultParams, args) {
        init();
    }

    void TSlider::init() {
        formatStyleString();
    }

}
