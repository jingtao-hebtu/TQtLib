/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TGrips.cpp
   Author : tao.jing
   Date   : 2024/6/21
   Brief  :
**************************************************************************/
#include "TGrips.h"
#include <QSizeGrip>
#include <QFrame>
#include <QMouseEvent>
#include <QEvent>
#include <iostream>


namespace T_QtBase {

    class GripEventFilter : public QObject {

    public:
        explicit GripEventFilter(QWidget *parent) : QObject(parent), mParent(parent) {}

    protected:
        QWidget *mParent{nullptr};
    };


    class TopGripEventFilter : public GripEventFilter {
    public:
        explicit TopGripEventFilter(QWidget *parent) : GripEventFilter(parent) {}

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override {
            if (event->type() == QEvent::MouseMove) {
                auto *mouse_event = dynamic_cast<QMouseEvent *>(event);
                auto delta = mouse_event->pos();
                auto height = std::max(mParent->minimumHeight(), mParent->height() - delta.y());
                auto geo = mParent->geometry();
                geo.setTop(geo.bottom() - height);
                mParent->setGeometry(geo);
                event->accept();
                return true;
            }
            return QObject::eventFilter(obj, event);
        }
    };

    class BottomGripEventFilter : public GripEventFilter {
    public:
        explicit BottomGripEventFilter(QWidget *parent) : GripEventFilter(parent) {}

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override {
            if (event->type() == QEvent::MouseMove) {
                auto *mouse_event = dynamic_cast<QMouseEvent *>(event);
                auto delta = mouse_event->pos();
                auto height = std::max(mParent->minimumHeight(), mParent->height() + delta.y());
                mParent->resize(mParent->width(), height);
                event->accept();
                return true;
            }
            return QObject::eventFilter(obj, event);
        }
    };

    class LeftGripEventFilter : public GripEventFilter {
    public:
        explicit LeftGripEventFilter(QWidget *parent) : GripEventFilter(parent) {}

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override {
            if (event->type() == QEvent::MouseMove) {
                auto *mouse_event = dynamic_cast<QMouseEvent *>(event);
                auto delta = mouse_event->pos();
                auto width = std::max(mParent->minimumWidth(), mParent->width() - delta.x());
                auto geo = mParent->geometry();
                geo.setLeft(geo.right() - width);
                mParent->setGeometry(geo);
                event->accept();
                return true;
            }
            return QObject::eventFilter(obj, event);
        }
    };

    class RightGripEventFilter : public GripEventFilter {
    public:
        explicit RightGripEventFilter(QWidget *parent) : GripEventFilter(parent) {}

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override {
            if (event->type() == QEvent::MouseMove) {
                auto *mouse_event = dynamic_cast<QMouseEvent *>(event);
                auto delta = mouse_event->pos();
                auto width = std::max(mParent->minimumWidth(), mParent->width() + delta.x());
                mParent->resize(width, mParent->height());
                event->accept();
                return true;
            }
            return QObject::eventFilter(obj, event);
        }
    };

    TGrips::TGrips(QWidget *parent, TGripType position, bool is_transparent)
            : mParent(parent), mIsTransparent(is_transparent) {
        setParent(parent);
        mWid = new TGripWidgets();
        initGrips(position);
    }

    void TGrips::initGrips(TGripType position) {
        switch (position) {
            case TOP_LEFT:
                mWid->setTopLeftGrip(this);
                setGeometry(5, 5, 15, 15);
                if (mIsTransparent) {
                    mWid->topLeftGrip()->setStyleSheet("background: transparent");
                }
                break;
            case TOP_RIGHT:
                mWid->setTopRightGrip(this);
                setGeometry(mParent->width() - 20, 5, 15, 15);
                if (mIsTransparent) {
                    mWid->topRightGrip()->setStyleSheet("background: transparent");
                }
                break;
            case BOTTOM_LEFT:
                mWid->setBottomLeftGrip(this);
                setGeometry(5, mParent->height() - 20, 15, 15);
                if (mIsTransparent) {
                    mWid->bottomLeftGrip()->setStyleSheet("background: transparent");
                }
                break;
            case BOTTOM_RIGHT:
                mWid->setBottomRightGrip(this);
                setGeometry(mParent->width() - 20, mParent->height() - 20, 15, 15);
                if (mIsTransparent) {
                    mWid->bottomRightGrip()->setStyleSheet("background: transparent");
                }
                break;
            case TOP:
                mWid->setTopGrip(this);
                setGeometry(0, 5, mParent->width(), 10);
                setMaximumHeight(10);
                mWid->topGrip()->installEventFilter(new TopGripEventFilter(mParent));

                if (mIsTransparent) {
                    mWid->topGrip()->setStyleSheet("background: transparent");
                }
                break;
            case BOTTOM:
                mWid->setBottomGrip(this);
                setGeometry(0, mParent->height() - 10, mParent->width(), 10);
                setMaximumHeight(10);
                mWid->bottomGrip()->installEventFilter(new BottomGripEventFilter(mParent));

                if (mIsTransparent) {
                    mWid->bottomGrip()->setStyleSheet("background: transparent");
                }
                break;
            case LEFT:
                mWid->setLeftGrip(this);
                setGeometry(10, 10, 10, mParent->height());
                setMaximumWidth(10);
                mWid->leftGrip()->installEventFilter(new LeftGripEventFilter(mParent));

                if (mIsTransparent) {
                    mWid->leftGrip()->setStyleSheet("background: transparent");
                }
                break;
            case RIGHT:
                mWid->setRightGrip(this);
                setGeometry(mParent->width() - 10, 10, 10, mParent->height());
                setMaximumWidth(10);
                mWid->rightGrip()->installEventFilter(new RightGripEventFilter(mParent));

                if (mIsTransparent) {
                    mWid->rightGrip()->setStyleSheet("background: transparent");
                }
                break;
            default:
                break;
        }
    }

    void TGrips::resizeEvent(QResizeEvent *event) {
        Q_UNUSED(event);
        if (mWid->topGrip()) {
            mWid->topGrip()->setGeometry(0, 0, width(), 10);
        } else if (mWid->bottomGrip()) {
            mWid->bottomGrip()->setGeometry(0, 0, width(), 10);
        } else if (mWid->leftGrip()) {
            mWid->leftGrip()->setGeometry(0, 0, 10, height() - 20);
        } else if (mWid->rightGrip()) {
            mWid->rightGrip()->setGeometry(0, 0, 10, height() - 20);
        } else if (mWid->topLeftGrip()) {
            mWid->topLeftGrip()->setGeometry(0, 0, 15, 15);
        } else if (mWid->topRightGrip()) {
            mWid->topRightGrip()->setGeometry(width() - 15, 0, 15, 15);
        } else if (mWid->bottomLeftGrip()) {
            mWid->bottomLeftGrip()->setGeometry(0, height() - 15, 15, 15);
        } else if (mWid->bottomRightGrip()) {
            mWid->bottomRightGrip()->setGeometry(width() - 15, height() - 15, 15, 15);
        }
    }

};