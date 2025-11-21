/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TCreditsBar.cpp
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#include "TCreditsBar.h"
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include "TFormatString.h"


namespace T_QtBase {

    static TFormatString TCreditsBarStyleString = R"(
        #BgFrame {
            border-radius: {radius}px;
            background-color: {bg_two};
        }
        .QLabel {
            font: {font_size}pt "{font_family}";
            color: {text_description_color};
            padding-left: {padding}px;
            padding-right: {padding}px;
        }
    )";

    std::map<std::string, std::string> TCreditsBarDefaultParams = {
            {"copyright_text",         "tao.jing"},
            {"version_text",           "v0.1"},
            {"radius",                 "8"},
            {"padding",                "10"},
            {"font_size",              "9"},
            {"text_description_color", "#4f5b6e"},
            {"bg_two",                 "#1e2229"},
    };

    TCreditsBar::TCreditsBar(QWidget *parent,
                             std::initializer_list<std::pair<std::string, std::string>> args)
            : QWidget(parent), TFormatWid(TCreditsBarStyleString, TCreditsBarDefaultParams, args) {
        init();
    }

    void TCreditsBar::init() {
        setupUi();
        formatStyleString();
    }

    void TCreditsBar::setupUi() {
        auto wid_hlayout = new QHBoxLayout();
        setLayout(wid_hlayout);
        wid_hlayout->setContentsMargins(0, 0, 0, 0);

        auto bg_frame = new QFrame(this);
        bg_frame->setObjectName("BgFrame");
        bg_frame->setFixedSize(160, 24);
        wid_hlayout->addWidget(bg_frame);

        auto bg_hlayout = new QHBoxLayout();
        bg_frame->setLayout(bg_hlayout);
        bg_hlayout->setContentsMargins(0, 0, 0, 0);

        auto copyright_label = new QLabel();
        copyright_label->setText(mParamHandler.get<std::string>("copyright_text").c_str());
        copyright_label->setAlignment(Qt::AlignVCenter);

        auto version_label = new QLabel();
        version_label->setText(mParamHandler.get<std::string>("version_text").c_str());
        version_label->setAlignment(Qt::AlignVCenter);

        auto separator = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bg_hlayout->addWidget(copyright_label);
        bg_hlayout->addSpacerItem(separator);
        bg_hlayout->addWidget(version_label);
    }


};



