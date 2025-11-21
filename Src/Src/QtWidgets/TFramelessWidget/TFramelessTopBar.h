/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFramelessTopBar.h
   Author : tao.jing
   Date   : 2023/11/21
   Brief  : 
**************************************************************************/
#ifndef QTONEDARK_TFRAMELESSTOPBAR_H
#define QTONEDARK_TFRAMELESSTOPBAR_H


#include <QWidget>

class QHBoxLayout;
class QLabel;
class QPushButton;


namespace T_QtBase {

    class TFramelessTopBar : public QWidget {

        Q_OBJECT

    signals:
        void closeBtnClicked();
        void maximumBtnClicked();
        void minimumBtnClicked();

    public:
        explicit TFramelessTopBar(QWidget *parent = nullptr);

        void initUi();
        void initStyle();
        void initAction();

    private:
        QHBoxLayout *mHLayout;

        QPushButton *mLogoBtn;
        QLabel *mBarNameLabel;

        QPushButton *mMaximizeBtn;
        QPushButton *mMinimizeBtn;
        QPushButton *mCloseBtn;
    };


};


#endif //QONEDARK_FRAMELESSTOPBAR_H
