/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFramelessWidget.h
   Author : tao.jing
   Date   : 2023/11/21
   Brief  : 
**************************************************************************/
#ifndef QTONEDARK_TFRAMELESSWIDGET_H
#define QTONEDARK_TFRAMELESSWIDGET_H

#include <QWidget>
#include <QPointF>
#include <atomic>
#include "TaoUtilDefine.h"


class QVBoxLayout;

namespace T_QtBase {
    class TFramelessTopBar;
};


namespace T_QtBase {

    class TAO_UTIL_API TFramelessWidget : public QWidget {

        Q_OBJECT

    public:
        explicit TFramelessWidget(QWidget *parent = nullptr);

    public slots:
        void onCloseBtnClicked();
        void onMaximizeBtnClicked();
        void onMinimizeBtnClicked();

    private:
        void initUi();
        void initStyle();
        void initAction();

    protected:
        void mousePressEvent(QMouseEvent *event) override;
        void mouseReleaseEvent(QMouseEvent *event) override;
        void mouseMoveEvent(QMouseEvent *event) override;

    private:
        QVBoxLayout *mMainLayout;
        TFramelessTopBar *mTopBar;

        std::atomic<bool> mMousePressed {false};
        QPointF mStartPoint;
    };


};



#endif //QONEDARK_FRAMELESSWIDGET_H
