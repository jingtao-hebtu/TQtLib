/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QGripsTest.cpp
   Author : tao.jing
   Date   : 2024/6/21
   Brief  :
**************************************************************************/
#include <QApplication>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMainWindow>
#include "TTitleBar.h"
#include "TGrips.h"
#include "TDraggableWidget.h"
#include "TLog.h"


//class QMainWid : public T_QtBase::TDraggableWidget {
class QMainWid : public QMainWindow {

public:
    //explicit QMainWid(QWidget *parent = nullptr) : T_QtBase::TDraggableWidget(parent) {
    explicit QMainWid(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        init();
    }

protected:
    void resizeEvent(QResizeEvent *event) override {
        mLeftGrip->setGeometry(5, 10, 100, height());
        mRightGrip->setGeometry(width() - 15, 10, 10, height());
        mTopGrip->setGeometry(5, 5, width() - 10, 10);
        mBottomGrip->setGeometry(5, height() - 15, width() - 10, 10);

        mTopLeftGrip->setGeometry(5, 5, 15, 15);
        mTopRightGrip->setGeometry(width() - 20, 5, 15, 15);
        mBottomLeftGrip->setGeometry(5, height() - 20, 15, 15);
        mBottomRightGrip->setGeometry(width() - 20, height() - 20, 15, 15);
    }

private:
    void init() {
        bool is_transparent = false;
        mLeftGrip = new T_QtBase::TGrips(this, T_QtBase::LEFT, is_transparent);
        mRightGrip = new T_QtBase::TGrips(this, T_QtBase::RIGHT, is_transparent);
        mTopGrip = new T_QtBase::TGrips(this, T_QtBase::TOP, is_transparent);
        mBottomGrip = new T_QtBase::TGrips(this, T_QtBase::BOTTOM, is_transparent);

        mTopLeftGrip = new T_QtBase::TGrips(this, T_QtBase::TOP_LEFT, is_transparent);
        mTopRightGrip = new T_QtBase::TGrips(this, T_QtBase::TOP_RIGHT, is_transparent);
        mBottomLeftGrip = new T_QtBase::TGrips(this, T_QtBase::BOTTOM_LEFT, is_transparent);
        mBottomRightGrip = new T_QtBase::TGrips(this, T_QtBase::BOTTOM_RIGHT, is_transparent);
    }

private:
    T_QtBase::TGrips *mLeftGrip {nullptr};
    T_QtBase::TGrips *mRightGrip {nullptr};
    T_QtBase::TGrips *mTopGrip {nullptr};
    T_QtBase::TGrips *mBottomGrip {nullptr};

    T_QtBase::TGrips *mTopLeftGrip {nullptr};
    T_QtBase::TGrips *mTopRightGrip {nullptr};
    T_QtBase::TGrips *mBottomLeftGrip {nullptr};
    T_QtBase::TGrips *mBottomRightGrip {nullptr};
};


int main(int argc, char *argv[]) {

    TBase::initDateLog(argc, argv);

    QApplication a(argc, argv);

    // Dialog as container
    QMainWid main_w(nullptr);
    main_w.resize(800, 600);
    main_w.show();
    return QApplication::exec();

}
