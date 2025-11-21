/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnIcon.cpp
   Author : tao.jing
   Date   : 2024/6/24
   Brief  :
**************************************************************************/
#include "TLeftColumnIcon.h"
#include <utility>
#include <QLabel>
#include <QPainter>
#include <QVBoxLayout>


namespace T_QtBase {


    TLeftColumnIcon::TLeftColumnIcon(QWidget *parent, QString icon_path, QString icon_color) :
            QWidget(parent), mIconPath(std::move(icon_path)), mIconColor(std::move(icon_color)) {
        init();
    }

    void TLeftColumnIcon::init() {
        setupUi();
    }

    void TLeftColumnIcon::setupUi() {
        mVLayout = new QVBoxLayout(this);
        mVLayout->setContentsMargins(0, 0, 0, 0);

        mIcon = new QLabel();
        mIcon->setAlignment(Qt::AlignCenter);

        setIcon(mIconPath, mIconColor);

        mVLayout->addWidget(mIcon);
    }

    void TLeftColumnIcon::setIcon(const QString& icon_path, const QString& icon_color) {
        if (icon_path == mIconPath && !mIconPixmap.isNull()) {
            return;
        }

        mIconColor = icon_color == "" ? mIconColor : icon_color;
        mIconPath = icon_path;

        mIconPixmap = QPixmap(mIconPath);
        QPainter icon_painter(&mIconPixmap);
        icon_painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        icon_painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon_painter.fillRect(mIconPixmap.rect(), QColor(mIconColor));
        icon_painter.end();
        mIcon->setPixmap(mIconPixmap);
    }



};
