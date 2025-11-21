/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDraggableWidget.h
   Author : tao.jing
   Date   : 2024/6/9
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TDRAGGABLEWIDGET_H
#define QTONEDARK_TDRAGGABLEWIDGET_H

#include <QWidget>
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TDraggableWidget : public QWidget {

    Q_OBJECT

    public:
        TDraggableWidget(QWidget *parent = nullptr, QWidget *app_parent = nullptr);

    protected:
        bool eventFilter(QObject *watched, QEvent *event) override;

    protected:
        QPointF mDragPos;

    private:
        QWidget *mAppParent {nullptr};
    };

}


#endif //QTONEDARK_TDRAGGABLEWIDGET_H
