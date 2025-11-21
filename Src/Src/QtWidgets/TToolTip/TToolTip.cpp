/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TToolTip.cpp
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#include "TToolTip.h"
#include <QGraphicsDropShadowEffect>


namespace T_QtBase {


    static TFormatString TToolTipStyleString = R"(
        QLabel {
            background-color: {tooltip_bg_color};
            color: {tooltip_text_foreground};
            padding-left: 10px;
            padding-right: 10px;
            border-radius: 17px;
            border: 0px solid {context_color};
            font: 800 9pt "Segoe UI";
        }
    )";

    static std::map<std::string, std::string> TToolTipStyleDefaultParams = {
            {"tooltip_text",            ""},
            {"tooltip_bg_color",        "#1b1e23"},
            {"tooltip_text_foreground", "#8a95aa"},
            {"context_color",           "transparent"},
    };

    TToolTip::TToolTip(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QLabel(parent), TFormatWid(TToolTipStyleString, TToolTipStyleDefaultParams, args) {
        init();
    }

    void TToolTip::init() {
        setObjectName("TToolTip");
        formatStyleString();
        setMinimumHeight(34);
        updateText(getParam<std::string>("tooltip_text").c_str());

        mShadow = new QGraphicsDropShadowEffect(this);
        mShadow->setBlurRadius(30);
        mShadow->setXOffset(0);
        mShadow->setYOffset(0);
        mShadow->setColor(QColor(0, 0, 0, 80));
        setGraphicsEffect(mShadow);
    }

    void TToolTip::updateText(QString text) {
        setText(text);
        adjustSize();
    }

};