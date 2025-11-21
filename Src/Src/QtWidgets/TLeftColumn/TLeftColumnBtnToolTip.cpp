/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnBtnToolTip.cpp
   Author : tao.jing
   Date   : 2024/7/8
   Brief  :
**************************************************************************/
#include "TLeftColumnBtnToolTip.h"
#include <QGraphicsDropShadowEffect>


namespace T_QtBase {

    static TFormatString TTitleButtonToolTip_StyleString = R"(
        QLabel {
            background-color: {tooltip_bg_color};
            color: {text_foreground};
            padding-left: 10px;
            padding-right: 10px;
            border-radius: 17px;
            border: 0px solid transparent;
            border-right: 3px solid {context_color};
            font: 800 9pt "Segoe UI";
        }
    )";

    static std::map<std::string, std::string> TTitleButtonToolTip_StyleDefaultParams{
            {"tooltip_text", ""},
            {"tooltip_bg_color", "#1B1E23"},
            {"text_foreground", "#8A95AA"},
            {"context_color", "#568AF2"},
    };


    TLeftColumnBtnToolTip::TLeftColumnBtnToolTip(QWidget *parent,
                                                 std::initializer_list<std::pair<std::string, std::string>> args)
            : TToolTip(parent) {
        init();
        updateStyle(TTitleButtonToolTip_StyleString, TTitleButtonToolTip_StyleDefaultParams, args);
        updateText(getParam<std::string>("tooltip_text").c_str());
    }
}
