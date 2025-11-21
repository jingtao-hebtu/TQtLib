/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TCircularProgress.cpp
   Author : tao.jing
   Date   : 2024/5/29
   Brief  :
**************************************************************************/
#include "TCircularProgress.h"
#include <QPainter>


namespace T_QtBase {

    TCircularProgress::TCircularProgress(QWidget *parent,
                                         std::initializer_list<std::pair<std::string, std::string>> args)
            : QWidget(parent), TFormatWid("", TBase::TStrListParam{
            {"value", "80"}, {"max_value", "100"}, {"progress_width", "10"},
            {"progress_color", "#ff79c6"}, {"bg_color", "#44475a"}, {"text_color", "#ff79c6"},
            {"font_size", "12"}, {"font_family", "Segoe UI"}, {"suffix", "%"},
            {"is_rounded", "true"}, {"enable_text", "true"}, {"enable_bg", "true"},
    }, args) {
        init();
    }

    void TCircularProgress::init() {
        initParams();
    }

    void TCircularProgress::initParams() {
        mValue = mParamHandler.get<int>("value");
        mMaxValue = mParamHandler.get<int>("max_value");

        mBgColor = QColor(mParamHandler.get<std::string>("bg_color").c_str());
        mTextColor = QColor(mParamHandler.get<std::string>("text_color").c_str());
        mProgressColor = QColor(mParamHandler.get<std::string>("progress_color").c_str());
    }

    void TCircularProgress::paintEvent(QPaintEvent *event) {
        Q_UNUSED(event);
        int outer_width = width() - mParamHandler.get<int>("progress_width");
        int outer_height = height() - mParamHandler.get<int>("progress_width");
        int margin = static_cast<int>(mParamHandler.get<int>("progress_width") / 2);
        int value = static_cast<int>(static_cast<float>(mValue) * 360.0f / static_cast<float>(mMaxValue));

        QPainter painter;
        painter.begin(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setFont(QFont(mParamHandler.get<std::string>("font_family").c_str(),
                              mParamHandler.get<int>("font_size")));
        painter.setPen(Qt::NoPen);

        QPen pen;
        pen.setWidth(mParamHandler.get<int>("progress_width"));
        if (mParamHandler.get<bool>("is_rounded")) {
            pen.setCapStyle(Qt::RoundCap);
        }
        if (mParamHandler.get<bool>("enable_bg")) {
            pen.setColor(mBgColor);
            painter.setPen(pen);
            painter.drawArc(margin, margin, outer_width, outer_height, 0, 360 * 16);
        }

        pen.setColor(mProgressColor);
        painter.setPen(pen);
        painter.drawArc(margin, margin, outer_width, outer_height, -90 * 16, -value * 16);

        if (mParamHandler.get<bool>("enable_text")) {
            pen.setColor(mTextColor);
            painter.setPen(pen);
            std::string cur_text = std::to_string(mValue) + mParamHandler.get<std::string>("suffix");
            painter.drawText(rect(), Qt::AlignCenter, cur_text.c_str());
        }

        painter.end();
    }

    void TCircularProgress::setValue(int value) {
        value = value > mMaxValue ? mMaxValue : value;
        value = value < 0 ? 0 : value;
        mValue = value;
        repaint();
    }


}
