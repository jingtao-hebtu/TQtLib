/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuBtnToolTip.cpp
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#include "TLeftMenuBtnToolTip.h"
#include <QGraphicsDropShadowEffect>


namespace T_QtBase {


    static TFormatString TLeftMenuBtnToolTip_StyleString = R"(
        QLabel {
            background-color: {tooltip_bg_color};
            color: {tooltip_text_foreground};
            padding-left: 10px;
            padding-right: 10px;
            border-radius: 17px;
            border: 0px solid transparent;
            border-left: 3px solid {context_color};
            font: 800 9pt "Segoe UI";
        }
    )";

    static std::map<std::string, std::string> TLeftMenuBtnToolTip_StyleDefaultParams = {
            {"tooltip_text",            ""},
            {"tooltip_bg_color",        "#1b1e23"},
            {"tooltip_text_foreground", "#8a95aa"},
            {"context_color",           "transparent"},
    };

    TLeftMenuBtnToolTip::TLeftMenuBtnToolTip(QWidget *parent,
                                             std::initializer_list<std::pair<std::string, std::string>> args)
            : TToolTip(parent) {
        init();
        updateStyle(TLeftMenuBtnToolTip_StyleString, TLeftMenuBtnToolTip_StyleDefaultParams, args);
        updateText(getParam<std::string>("tooltip_text").c_str());
    }

};