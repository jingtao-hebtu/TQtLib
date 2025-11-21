/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainWindow.cpp
   Author : tao.jing
   Date   : 2024/7/24
   Brief  :
**************************************************************************/
#include "TMainWindow.h"
#include "TMainWindow_Ui.h"
#include "TGrips.h"
#include "TLeftMenu.h"
#include "TLeftColumn.h"
#include "TTitleBar.h"
#include "TMainPages_Ui.h"
#include "TException.h"


namespace T_QtBase {


    TMainWindow::TMainWindow(QWidget *parent) : TDraggableMainWindow(parent) {
        mUi = new TMainWindow_Ui();
        mUi->setupUi(this);

        initAction();
    }

    void TMainWindow::initAction() {
        connect(mUi->mLeftMenu, SIGNAL(btnClicked(QObject*)), this, SLOT(onLeftMenuClicked(QObject*)));
        connect(mUi->mLeftMenu, SIGNAL(btnReleased(QObject*)), this, SLOT(onLeftMenuReleased(QObject*)));
        connect(mUi->mLeftColumn, SIGNAL(btnClicked(QObject*)), this, SLOT(onLeftColumnClicked(QObject*)));
        connect(mUi->mLeftColumn, SIGNAL(btnReleased(QObject*)), this, SLOT(onLeftColumnReleased(QObject*)));
        connect(mUi->mTitleBar, SIGNAL(btnClicked(QObject*)), this, SLOT(onTitleBarClicked(QObject*)));
        connect(mUi->mTitleBar, SIGNAL(btnReleased(QObject*)), this, SLOT(onTitleBarReleased(QObject*)));

        connect(this, SIGNAL(closeWnd()), this, SLOT(close()));
        connect(this, SIGNAL(minimizeWnd()), this, SLOT(showMinimized()));
    }

    void TMainWindow::resizeEvent(QResizeEvent *event) {
        Q_UNUSED(event);
        mUi->mLeftGrip->setGeometry(5, 10, 100, height());
        mUi->mRightGrip->setGeometry(width() - 15, 10, 10, height());
        mUi->mTopGrip->setGeometry(5, 5, width() - 10, 10);
        mUi->mBottomGrip->setGeometry(5, height() - 15, width() - 10, 10);

        mUi->mTopLeftGrip->setGeometry(5, 5, 15, 15);
        mUi->mTopRightGrip->setGeometry(width() - 20, 5, 15, 15);
        mUi->mBottomLeftGrip->setGeometry(5, height() - 20, 15, 15);
        mUi->mBottomRightGrip->setGeometry(width() - 20, height() - 20, 15, 15);
    }

    void TMainWindow::onLeftMenuClicked(QObject* sender_btn) {
        auto sender_name = sender_btn->objectName();
        LOG_F(INFO, "Sender name %s clicked.", sender_name.toStdString().c_str());
        mUi->onLeftMenuClicked(sender_name);
    }

    void TMainWindow::onLeftMenuReleased(QObject* sender_btn) {
        LOG_F(INFO, "Sender name %s released.", sender_btn->objectName().toStdString().c_str());
    }

    void TMainWindow::onLeftColumnClicked(QObject *sender_btn) {
        auto sender_name = sender_btn->objectName();
        LOG_F(INFO, "Sender name %s clicked.", sender_name.toStdString().c_str());
        mUi->onLeftColumnClicked(sender_name);
    }

    void TMainWindow::onLeftColumnReleased(QObject *sender_btn) {
        LOG_F(INFO, "Sender name %s released.", sender_btn->objectName().toStdString().c_str());
    }

    void TMainWindow::onTitleBarClicked(QObject *sender_btn) {
        auto sender_name = sender_btn->objectName();
        LOG_F(INFO, "Sender name %s clicked.", sender_name.toStdString().c_str());
        mUi->onTitleBarClicked(sender_name);
    }

    void TMainWindow::onTitleBarReleased(QObject *sender_btn) {
        LOG_F(INFO, "Sender name %s released.", sender_btn->objectName().toStdString().c_str());
    }


};
