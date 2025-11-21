/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuDiv.cpp
   Author : tao.jing
   Date   : 2024/6/15
   Brief  :
**************************************************************************/
#include "TLeftMenuDiv.h"
#include <QFrame>
#include <QHBoxLayout>


namespace T_QtBase {

    static TFormatString TStyleString = R"(
        #{obj_name} {
            background: {color};
        }
    )";

    static std::map<std::string, std::string> TStyleDefaultParams {
            {"obj_name", "TLeftMenuDiv"},
            {"color", "#777"},
    };

    TLeftMenuDiv::TLeftMenuDiv(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QWidget(parent), TFormatWid(TStyleString, TStyleDefaultParams, args) {
        init();
    }

    void TLeftMenuDiv::init() {
        setObjectName(getParam<std::string>("obj_name").c_str());

        mMainLayout = new QHBoxLayout();
        setLayout(mMainLayout);
        mMainLayout->setContentsMargins(5, 0, 5, 0);

        mFrame = new QFrame(this);
        mFrame->setMaximumHeight(1);
        mFrame->setMinimumHeight(1);
        mMainLayout->addWidget(mFrame);
        setMaximumHeight(1);

        formatStyleString();
    }

}




