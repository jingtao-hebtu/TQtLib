/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainWindow.h
   Author : tao.jing
   Date   : 2024/7/24
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TMAINWINDOW_H
#define QTONEDARK_TMAINWINDOW_H

#include <QMainWindow>
#include "TDraggableMainWindow.h"


namespace T_QtBase {

    class TMainWindow_Ui;

    class TMainWindow : public TDraggableMainWindow {

    Q_OBJECT

    public:
        TMainWindow(QWidget *parent = nullptr);

    signals:
        void closeWnd();

        void minimizeWnd();

    public slots:

        void onLeftMenuClicked(QObject *sender_btn);

        void onLeftMenuReleased(QObject *sender_btn);

        void onLeftColumnClicked(QObject *sender_btn);

        void onLeftColumnReleased(QObject *sender_btn);

        void onTitleBarClicked(QObject *sender_btn);

        void onTitleBarReleased(QObject *sender_btn);

    protected:
        void resizeEvent(QResizeEvent *event) override;

    private:
        void initAction();

    private:
        TMainWindow_Ui *mUi{nullptr};
    };

};


#endif //QTONEDARK_TMAINWINDOW_H
