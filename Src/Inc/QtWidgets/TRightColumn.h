/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TRightColumn.h
   Author : tao.jing
   Date   : 2024/7/20
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TRIGHTCOLUMN_H
#define QTONEDARK_TRIGHTCOLUMN_H

#include <QFrame>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


class QWidget;
class QLabel;
class QVBoxLayout;
class QStackedWidget;


namespace T_QtBase {

    class TAO_UTIL_API TRightColumn : public QFrame, public TFormatWid {

    Q_OBJECT

    public:
        TRightColumn(QWidget *parent, QWidget *app_parent,
                std::initializer_list<std::pair<std::string, std::string>> args = {},
                std::initializer_list<std::pair<std::string, std::string>> op_args = {});

    private:
        void init();

        void setupUi();

    private:
        QWidget *mParent {nullptr};
        QWidget *mAppParent {nullptr};

        QVBoxLayout *mMainPagesLayout {nullptr};
        QStackedWidget *mMenus {nullptr};

        // Menu 1
        QWidget *mMenu_1 {nullptr};
        QVBoxLayout *mVerticalLayout_1 {nullptr};
        QWidget *mBtn_1_Widget {nullptr};
        QVBoxLayout *mBtn_1_Layout {nullptr};
        QLabel *mLabel_1 {nullptr};

        // Menu 2
        QWidget *mMenu_2 {nullptr};
        QVBoxLayout *mVerticalLayout_2 {nullptr};
        QWidget *mBtn_2_Widget {nullptr};
        QVBoxLayout *mBtn_2_Layout {nullptr};
        QLabel *mLabel_2 {nullptr};

        QLabel *mLabel_3 {nullptr};
    };

};

#endif //QTONEDARK_TRIGHTCOLUMN_H


