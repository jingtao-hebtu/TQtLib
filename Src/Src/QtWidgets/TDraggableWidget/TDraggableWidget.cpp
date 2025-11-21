/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDraggableWidget.cpp
   Author : tao.jing
   Date   : 2024/6/9
   Brief  :
**************************************************************************/
#include "TDraggableWidget.h"
#include "TDraggableMainWindow.h"
#include <QMouseEvent>


namespace T_QtBase {


    TDraggableWidget::TDraggableWidget(QWidget *parent, QWidget *app_parent)
            : QWidget(parent), mAppParent(app_parent) {

    }

    bool TDraggableWidget::eventFilter(QObject *watched, QEvent *event) {
        if (event->type() == QEvent::MouseMove) {
            auto *mouseEvent = dynamic_cast<QMouseEvent *>(event);
            if (mouseEvent->buttons() & Qt::LeftButton) {
                //QWidget *parent = this->parentWidget();
                QWidget *app_parent = mAppParent;
                if (app_parent) {
                    auto draggable_parent = dynamic_cast<TDraggableWidget *>(app_parent);
                    if (draggable_parent) {
                        auto pos = draggable_parent->pos() + mouseEvent->globalPosition() - draggable_parent->mDragPos;
                        draggable_parent->move(static_cast<int>(pos.x()), static_cast<int>(pos.y()));
                        draggable_parent->mDragPos = mouseEvent->globalPosition();
                        event->accept();
                        return true;
                    } else {
                        auto draggable_parent_mw = dynamic_cast<TDraggableMainWindow *>(app_parent);
                        if (draggable_parent_mw) {
                            auto pos = draggable_parent_mw->pos() +
                                       mouseEvent->globalPosition() - draggable_parent_mw->mDragPos;
                            draggable_parent_mw->move(static_cast<int>(pos.x()), static_cast<int>(pos.y()));
                            draggable_parent_mw->mDragPos = mouseEvent->globalPosition();
                            event->accept();
                            return true;
                        }
                    }

                }
            }
        } else if (event->type() == QEvent::MouseButtonPress) {
            auto *mouseEvent = dynamic_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                //QWidget *parent = this->parentWidget();
                QWidget *app_parent = mAppParent;
                if (app_parent) {
                    auto draggable_parent = dynamic_cast<TDraggableWidget *>(app_parent);
                    if (draggable_parent) {
                        draggable_parent->mDragPos = mouseEvent->globalPosition();
                    } else {
                        auto draggable_parent_mw = dynamic_cast<TDraggableMainWindow *>(app_parent);
                        if (draggable_parent_mw) {
                            draggable_parent_mw->mDragPos = mouseEvent->globalPosition();
                        }
                    }
                }
                return true;
            }
        }
        return QWidget::eventFilter(watched, event);
    }

}
