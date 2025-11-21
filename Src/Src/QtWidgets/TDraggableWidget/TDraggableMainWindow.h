/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDraggableMainWindow.h
   Author : tao.jing
   Date   : 2024/6/9
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TDRAGGABLEMAINWINDOW_H
#define QTONEDARK_TDRAGGABLEMAINWINDOW_H

#include <QMainWindow>
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TDraggableMainWindow : public QMainWindow {

        friend class TDraggableWidget;

    Q_OBJECT

    public:
        TDraggableMainWindow(QWidget *parent = nullptr);

    protected:
        bool eventFilter(QObject *watched, QEvent *event) override;

    protected:
        QPointF mDragPos;
    };

}


#endif //QTONEDARK_TDraggableMainWindow_H
