/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TGripWidgets.cpp
   Author : tao.jing
   Date   : 2024/6/20
   Brief  :
**************************************************************************/
#include "TGripWidgets.h"
#include <QFrame>
#include <QSizeGrip>


namespace T_QtBase {

    void TGripWidgets::setTopLeftGrip(QWidget *form) {
        setCornerGrip(mTopLeftGrip, form, "TopLeftGrip");
    }

    void TGripWidgets::setTopRightGrip(QWidget *form) {
        setCornerGrip(mTopRightGrip, form, "TopRightGrip");
    }

    void TGripWidgets::setBottomLeftGrip(QWidget *form) {
        setCornerGrip(mBottomLeftGrip, form, "BottomLeftGrip");
    }

    void TGripWidgets::setBottomRightGrip(QWidget *form) {
        setCornerGrip(mBottomRightGrip, form, "BottomRightGrip");
    }

    void TGripWidgets::setTopGrip(QWidget *form) {
        if (mTopGrip != nullptr) {
            return;
        }
        mTopGrip = new QFrame(form);
        mTopGrip->setObjectName("TopGrip");
        mTopGrip->setGeometry(QRect(0, 0, 500, 10));
        mTopGrip->setStyleSheet("background-color: rgb(85, 255, 255);");
        mTopGrip->setCursor(QCursor(Qt::SizeVerCursor));
    }

    void TGripWidgets::setBottomGrip(QWidget *form) {
        if (mBottomGrip != nullptr) {
            return;
        }
        mBottomGrip = new QFrame(form);
        mBottomGrip->setObjectName("BottomGrip");
        mBottomGrip->setGeometry(QRect(0, 0, 500, 10));
        mBottomGrip->setStyleSheet("background-color: rgb(255, 0, 0);");
        mBottomGrip->setCursor(QCursor(Qt::SizeVerCursor));
    }

    void TGripWidgets::setLeftGrip(QWidget *form) {
        if (mLeftGrip != nullptr) {
            return;
        }
        mLeftGrip = new QFrame(form);
        mLeftGrip->setObjectName("LeftGrip");
        mLeftGrip->setGeometry(QRect(0, 10, 10, 480));
        mLeftGrip->setMinimumSize(QSize(10, 0));
        mLeftGrip->setStyleSheet("background-color: rgb(255, 121, 198);");
        mLeftGrip->setCursor(QCursor(Qt::SizeHorCursor));
    }

    void TGripWidgets::setRightGrip(QWidget *form) {
        if (mRightGrip != nullptr) {
            return;
        }
        mRightGrip = new QFrame(form);
        mRightGrip->setObjectName("RightGrip");
        mRightGrip->setGeometry(QRect(0, 0, 10, 500));
        mRightGrip->setMinimumSize(QSize(10, 0));
        mRightGrip->setStyleSheet("background-color: rgb(255, 0, 127);");
        mRightGrip->setCursor(QCursor(Qt::SizeHorCursor));
    }

    void TGripWidgets::setCornerGrip(QFrame *&grip, QWidget *form, const std::string &obj_name) {
        if (grip == nullptr) {
            grip = new QFrame(form);

            auto size_grip = new QSizeGrip(grip);
            size_grip->setFixedSize(grip->size());

            grip->setObjectName(obj_name.c_str());
            grip->setFixedSize(15, 15);
            grip->setStyleSheet("background-color: #333; border: 2px solid #55FF00;");
        }
    }

};