/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TPushButton.cpp
   Author : tao.jing
   Date   : 2024/5/29
   Brief  :
**************************************************************************/
#include "TPushButton.h"

#include <utility>
#include "TException.h"
#include "TFormatString.h"


namespace T_QtBase {

    static TFormatString TPushButtonStyleString = R"(
        QPushButton {
            border: none;
            padding-left: 10px;
            padding-right: 5px;
            color: {color};
            border-radius: {radius};
            background-color: {bg_color};
            font-size: {font-size}pt;
        }
        QPushButton:hover {
            background-color: {bg_color_hover};
        }
        QPushButton:pressed {
            background-color: {bg_color_pressed};
        }
    )";

    static std::map<std::string, std::string> TPushButtonStyleDefaultParams{
            {"radius", "8"},
            {"color", "#8A95AA"},
            {"bg_color", "#1B1E23"},
            {"bg_color_hover", "#21252D"},
            {"bg_color_pressed", "#272C36"},
            {"font-size", "10"},
    };

    TPushButton::TPushButton(QWidget *parent, QString btn_text,
                             std::initializer_list<std::pair<std::string, std::string>> args)
            : QPushButton(parent), mBtnText(std::move(btn_text)),
              TFormatWid(TPushButtonStyleString, TPushButtonStyleDefaultParams, args) {
        init();
    }

    void TPushButton::init() {
        formatStyleString();

        setText(mBtnText);
        setCursor(Qt::PointingHandCursor);
    }

}
