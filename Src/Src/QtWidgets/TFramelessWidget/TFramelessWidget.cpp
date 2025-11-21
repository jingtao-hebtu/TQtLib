/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFramelessWidget.cpp
   Author : tao.jing
   Date   : 2023/11/21
   Brief  : 
**************************************************************************/
#include "TFramelessWidget.h"
#include "TFramelessTopBar.h"
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QFile>


namespace T_QtBase {

    TFramelessWidget::TFramelessWidget(QWidget *parent) : QWidget(parent) {
        initUi();
        initStyle();
        initAction();
    }

    void TFramelessWidget::initUi() {
        setAttribute(Qt::WA_StyledBackground);
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

        mMainLayout = new QVBoxLayout();
        setLayout(mMainLayout);

        mTopBar = new TFramelessTopBar(this);
        mMainLayout->addWidget(mTopBar);
    }

    void TFramelessWidget::initStyle() {
        QFile style_file(QString(":/qss/qui/FramelessWidget.css"));
        if (style_file.open(QFile::ReadOnly))
        {
            QString styleStr = style_file.readAll();
            setStyleSheet(styleStr);
            style_file.close();
        }
    }

    void TFramelessWidget::initAction() {
        connect(mTopBar, SIGNAL(closeBtnClicked()), this, SLOT(onCloseBtnClicked()));
        connect(mTopBar, SIGNAL(maximumBtnClicked()), this, SLOT(onMaximizeBtnClicked()));
        connect(mTopBar, SIGNAL(minimumBtnClicked()), this, SLOT(onMinimizeBtnClicked()));
    }

    void TFramelessWidget::mousePressEvent(QMouseEvent *event) {
        if (event->buttons() & Qt::LeftButton) {
            updateGeometry();
            mMousePressed = true;
            mStartPoint = event->globalPosition();
        }
        QWidget::mousePressEvent(event);
    }

    void TFramelessWidget::mouseReleaseEvent(QMouseEvent *event) {
        if (event->buttons() & Qt::LeftButton) {
            mMousePressed = false;
        }
        QWidget::mouseReleaseEvent(event);
    }

    void TFramelessWidget::mouseMoveEvent(QMouseEvent *event) {
        if (mMousePressed && !isMaximized()) {
            QPointF point = event->globalPosition() - mStartPoint;
            mStartPoint = event->globalPosition();
            move(x() + static_cast<int>(point.x()), y() + static_cast<int>(point.y()));
        }
        QWidget::mouseMoveEvent(event);
    }

    void TFramelessWidget::onCloseBtnClicked() {
        close();
    }

    void TFramelessWidget::onMaximizeBtnClicked() {
        if (isMaximized()) {
            setWindowState(Qt::WindowNoState);
        } else {
            setWindowState(Qt::WindowMaximized);
        }
    }

    void TFramelessWidget::onMinimizeBtnClicked() {
        setWindowState(Qt::WindowMinimized);
    }


};


