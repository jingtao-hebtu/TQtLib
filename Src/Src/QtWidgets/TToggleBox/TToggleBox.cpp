/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TToggleBox.cpp
   Author : tao.jing
   Date   : 2024/5/30
   Brief  :
**************************************************************************/
#include "TToggleBox.h"

#include "TToggleBox.h"
#include <QPropertyAnimation>
#include <QPainter>
#include "TException.h"

#include <iostream>


namespace T_QtBase {

    TToggleBox::TToggleBox(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QCheckBox(parent), TFormatWid("", {
                {"bg_color", "#777"}, {"circle_color", "#DDD"}, {"active_color", "#00BCFF"}, {"width", "50"}
            }, args) {
        init();
    }

    void TToggleBox::init() {
        mBgColor = QColor(mParamHandler.get<std::string>("bg_color").c_str());
        mCircleColor = QColor(mParamHandler.get<std::string>("circle_color").c_str());
        mActiveColor = QColor(mParamHandler.get<std::string>("active_color").c_str());

        setFixedSize(mParamHandler.get<int>("width"), 28);
        setCursor(Qt::PointingHandCursor);

        mAnimation = new QPropertyAnimation(this, "position");
        mAnimation->setEasingCurve(QEasingCurve::OutBounce);
        mAnimation->setDuration(500);
        connect(this, &QCheckBox::stateChanged, this, &TToggleBox::setupAnimation);
    }

    void TToggleBox::setupAnimation(int value) {
        mAnimation->stop();
        if (value != 0) {
            mAnimation->setEndValue(width() - 26);
        } else {
            mAnimation->setEndValue(4);
        }
        mAnimation->start();
    }

    void TToggleBox::setPosition(int target_pos) {
        if (mPosition != target_pos) {
            mPosition = target_pos;
            emit positionChanged(mPosition);
            update();
        }
    }

    bool TToggleBox::hitButton(const QPoint &pos) const {
        return contentsRect().contains(pos);
    }

    void TToggleBox::paintEvent(QPaintEvent* event) {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setFont(QFont("Segoe UI", 9));
        painter.setPen(Qt::NoPen);

        QColor bg_color;
        if (!isChecked()) {
            bg_color = mBgColor;
        } else {
            bg_color = mActiveColor;
        }

        painter.setBrush(QColor(bg_color));
        painter.drawRoundedRect(0, 0, rect().width(), 28, 14, 14);
        painter.setBrush(QColor(mCircleColor));
        painter.drawEllipse(mPosition, 3, 22, 22);
        painter.end();
    }

}
