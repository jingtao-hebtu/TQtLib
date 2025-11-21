/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TWindow.cpp
   Author : tao.jing
   Date   : 2024/6/3
   Brief  :
**************************************************************************/
#include "TWindow.h"
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "TException.h"


namespace T_QtBase {

    static TFormatString TWindowStyleString = R"(
        #PodBgApp {
            background-color: {bg_color};
            border-radius: {border_radius};
            border: {border_size}px solid {border_color};
        }
        QFrame {
            color: {text_color};
            font: {text_font};
        }
    )";

    static std::map<std::string, std::string> TWindowStyleDefaultParams{
            {"enable_shadow", "true"},
            {"margin",        "0"},
            {"spacing",       "2"},
            {"border_radius", "10"},
            {"border_size",   "2"},
            {"bg_color",      "#2C313C"},
            {"text_color",    "#FFF"},
            {"border_color",  "#343B48"},
            {"text_font",     "9pt 'Segoe UI'"},
            {"layout_type",   "vertical"},
    };


    TWindow::TWindow(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QFrame(parent), TFormatWid(TWindowStyleString, TWindowStyleDefaultParams, args) {
        init();
    }

    void TWindow::init() {
        setObjectName("PodBgApp");

        setStyle();

        auto layout_type = mParamHandler.get<std::string>("layout_type");
        if (layout_type == "vertical") {
            mMainLayout = new QVBoxLayout();
        } else if (layout_type == "horizontal") {
            mMainLayout = new QHBoxLayout();
        } else {
            TBASE_LOG_THROW_RUNTIME("Invalid layout_type %s", layout_type.c_str());
        }
        int margin = mParamHandler.get<int>("margin");
        mMainLayout->setContentsMargins(margin, margin, margin, margin);
        mMainLayout->setSpacing(mParamHandler.get<int>("spacing"));
        setLayout(mMainLayout);

        formatStyleString();

        if (mParamHandler.get<bool>("enable_shadow")) {
            if (mShadow == nullptr) {
                mShadow = new QGraphicsDropShadowEffect();
                mShadow->setBlurRadius(20);
                mShadow->setXOffset(0);
                mShadow->setYOffset(0);
                mShadow->setColor(QColor(0, 0, 0, 160));
                setGraphicsEffect(mShadow);
            }
        }
    }

    void TWindow::setStyle(std::initializer_list<std::pair<std::string, std::string>> args) {
        mergeParams(args);
        formatStyleString();
    }

}

