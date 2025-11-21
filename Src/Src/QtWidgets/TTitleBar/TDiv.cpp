/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDiv.cpp
   Author : tao.jing
   Date   : 2024/6/6
   Brief  :
**************************************************************************/
#include "TDiv.h"
#include <QFrame>
#include <QHBoxLayout>


namespace T_QtBase {

    static TFormatString TDivStyleString = R"(
        QFrame {
            background: {color};
        }
    )";

    static std::map<std::string, std::string> TDivStyleDefaultParams{
            {"obj_name", "TDiv"},
            {"color",    "#777"},
    };

    TDiv::TDiv(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QWidget(parent), TFormatWid(TDivStyleString, TDivStyleDefaultParams, args) {
        init();
    }

    void TDiv::init() {
        setObjectName(getParam<std::string>("obj_name").c_str());

        mMainLayout = new QHBoxLayout();
        setLayout(mMainLayout);
        mMainLayout->setContentsMargins(0, 5, 0, 5);

        mFrame = new QFrame(this);
        mFrame->setMaximumWidth(1);
        mFrame->setMinimumWidth(1);
        mMainLayout->addWidget(mFrame);
        setMaximumWidth(20);
        setMinimumWidth(20);

        formatStyleString();
    }

}



