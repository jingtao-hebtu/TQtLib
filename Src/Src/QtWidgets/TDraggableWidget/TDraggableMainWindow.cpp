/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDraggableMainWindow.cpp
   Author : tao.jing
   Date   : 2024/6/9
   Brief  :
**************************************************************************/
#include "TDraggableMainWindow.h"
#include <QMouseEvent>


namespace T_QtBase {


    TDraggableMainWindow::TDraggableMainWindow(QWidget *parent) : QMainWindow(parent) {

    }

    bool TDraggableMainWindow::eventFilter(QObject *watched, QEvent *event) {
        if (event->type() == QEvent::MouseMove) {
            auto *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent->buttons() & Qt::LeftButton) {
                QWidget *parent = this->parentWidget();
                if (parent) {
                    auto draggable_parent = dynamic_cast<TDraggableMainWindow*>(parent);
                    if (draggable_parent) {
                        auto pos = draggable_parent->pos() + mouseEvent->globalPosition() - draggable_parent->mDragPos;
                        draggable_parent->move(static_cast<int>(pos.x()), static_cast<int>(pos.y()));
                        draggable_parent->mDragPos = mouseEvent->globalPosition();
                        event->accept();
                        return true;
                    }

                }
            }
        } else if (event->type() == QEvent::MouseButtonPress) {
            auto *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                QWidget *parent = this->parentWidget();
                if (parent) {
                    auto draggable_parent = dynamic_cast<TDraggableMainWindow *>(parent);
                    if (draggable_parent) {
                        draggable_parent->mDragPos = mouseEvent->globalPosition();
                    }
                }
                return true;
            }
        }
        return QWidget::eventFilter(watched, event);
    }

}
