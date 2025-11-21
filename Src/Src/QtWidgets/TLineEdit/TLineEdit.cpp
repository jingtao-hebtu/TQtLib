/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLineEdit.cpp
   Author : tao.jing
   Date   : 2024/5/27
   Brief  :
**************************************************************************/
#include "TLineEdit.h"
#include "TException.h"
#include "TFormatString.h"


namespace T_QtBase {

    static TFormatString TLineEditStyleString = R"(
        QLineEdit {
            background-color: {bg_color};
            border-radius: {radius}px;
            border: {border_size}px solid transparent;
            padding-left: 10px;
            padding-right: 10px;
            selection-color: {selection_color};
            selection-background-color: {context_color};
            color: {color};
            font-size: {font_size}px;
            font-family: "微软雅黑";
        }
        QLineEdit:focus {
            border: {border_size}px solid {context_color};
            background-color: {bg_color_active};
        }
    )";

    static std::map<std::string, std::string> TLineEditStyleDefaultParams {
            {"radius",          "8"},
            {"border_size",     "2"},
            {"color",           "#FFF"},
            {"selection_color", "#FFF"},
            {"bg_color",        "#333"},
            {"bg_color_active", "#222"},
            {"context_color",   "#00ABE8"},

            {"font_size",       "14"},
    };

    TLineEdit::TLineEdit(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QLineEdit(parent), TFormatWid(TLineEditStyleString, TLineEditStyleDefaultParams, args) {
        init();
    }

    void TLineEdit::init() {
        formatStyleString();
    }

};
