/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFramelessTopBar.cpp
   Author : tao.jing
   Date   : 2023/11/21
   Brief  : 
**************************************************************************/
#include "TFramelessTopBar.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>


namespace T_QtBase {

    TFramelessTopBar::TFramelessTopBar(QWidget *parent) : QWidget(parent) {
        initUi();
        initStyle();
        initAction();
    }

    void TFramelessTopBar::initUi() {

        setObjectName("FramelessTopBar");
        mHLayout = new QHBoxLayout();
        mHLayout->setSpacing(6);
        mHLayout->setContentsMargins(0, -1, -1, -1);
        setLayout(mHLayout);

        mLogoBtn = new QPushButton(this);
        mLogoBtn->setObjectName("TopBarLogoBtn");
        mHLayout->addWidget(mLogoBtn);

        mBarNameLabel = new QLabel(this);
        mBarNameLabel->setObjectName("TopBarNameLabel");
        mHLayout->addWidget(mBarNameLabel);

        mMaximizeBtn = new QPushButton(this);
        mMaximizeBtn->setObjectName("TopBarMaximizeBtn");
        mMaximizeBtn->setToolTip("Maximize");
        mHLayout->addWidget(mMaximizeBtn);

        mMinimizeBtn = new QPushButton(this);
        mMinimizeBtn->setObjectName("TopBarMinimizeBtn");
        mMinimizeBtn->setToolTip("Minimize");
        mHLayout->addWidget(mMinimizeBtn);

        mCloseBtn = new QPushButton(this);
        mCloseBtn->setObjectName("TopBarCloseBtn");
        mCloseBtn->setToolTip("Close");
        mHLayout->addWidget(mCloseBtn);
    }

    void TFramelessTopBar::initStyle() {
        QFile style_file(QString(":/qss/qui/FramelessWidget.css"));
        if (style_file.open(QFile::ReadOnly)) {
            QString styleStr = style_file.readAll();
            setStyleSheet(styleStr);
            mLogoBtn->setStyleSheet(styleStr);
            style_file.close();
        }
    }

    void TFramelessTopBar::initAction() {
        connect(mCloseBtn, SIGNAL(clicked()), this, SIGNAL(closeBtnClicked()));
        connect(mMaximizeBtn, SIGNAL(clicked()), this, SIGNAL(maximumBtnClicked()));
        connect(mMinimizeBtn, SIGNAL(clicked()), this, SIGNAL(minimumBtnClicked()));
    }

};
