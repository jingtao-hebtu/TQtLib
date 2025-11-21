/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TRightColumn.cpp
   Author : tao.jing
   Date   : 2024/7/20
   Brief  :
**************************************************************************/
#include "TRightColumn.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>


namespace T_QtBase {

    static TFormatString TStyleString = R"(
        #RightColumnBgFrame {
            border-radius: {border_radius};
            background-color: {bg_color};
        }
    )";

    static std::map<std::string, std::string> TStyleDefaultParams{
            {"bg_color",      "#343B48"},
            {"border_radius", "8"},
    };

    TRightColumn::TRightColumn(QWidget *parent, QWidget *app_parent,
                               std::initializer_list<std::pair<std::string, std::string>> args,
                               std::initializer_list<std::pair<std::string, std::string>> op_args)
            : QFrame(parent), TFormatWid(TStyleString, TStyleDefaultParams, args), mParent(parent),
              mAppParent(app_parent) {
        Q_UNUSED(op_args);
        init();
    }

    void TRightColumn::init() {
        setupUi();
        formatStyleString();
    }

    void TRightColumn::setupUi() {
        setObjectName("RightColumnBgFrame");

        resize(240, 600);
        mMainPagesLayout = new QVBoxLayout(this);
        mMainPagesLayout->setSpacing(0);
        mMainPagesLayout->setObjectName("MainPagesLayout");
        mMainPagesLayout->setContentsMargins(5, 5, 5, 5);
        mMenus = new QStackedWidget(this);
        mMenus->setObjectName("Menus");

        // Menu 1
        mMenu_1 = new QWidget(this);
        mMenu_1->setObjectName("Menu_1");
        mVerticalLayout_1 = new QVBoxLayout(mMenu_1);
        mVerticalLayout_1->setSpacing(5);
        mVerticalLayout_1->setObjectName("VerticalLayout_1");
        mVerticalLayout_1->setContentsMargins(5, 5, 5, 5);

        mBtn_1_Widget = new QWidget(this);
        mBtn_1_Widget->setObjectName("Btn_1_Widget");
        mBtn_1_Widget->setMinimumSize(QSize(0, 40));
        mBtn_1_Widget->setMaximumSize(QSize(16777215, 40));
        mBtn_1_Layout = new QVBoxLayout(mBtn_1_Widget);
        mBtn_1_Layout->setSpacing(0);
        mBtn_1_Layout->setObjectName("Btn_1_Layout");
        mBtn_1_Layout->setContentsMargins(0, 0, 0, 0);
        mVerticalLayout_1->addWidget(mBtn_1_Widget);

        mLabel_1 = new QLabel(mMenu_1);
        mLabel_1->setObjectName("Label_1");
        mLabel_1->setText("Menu 1 - Right Menu");
        QFont font;
        font.setPointSize(16);
        mLabel_1->setFont(font);
        mLabel_1->setStyleSheet("font-size: 16pt");
        mLabel_1->setAlignment(Qt::AlignCenter);
        mVerticalLayout_1->addWidget(mLabel_1);
        mMenus->addWidget(mMenu_1);

        // Menu 2
        mMenu_2 = new QWidget(this);
        mMenu_2->setObjectName("Menu_2");
        mVerticalLayout_2 = new QVBoxLayout(mMenu_2);
        mVerticalLayout_2->setSpacing(5);
        mVerticalLayout_2->setObjectName("VerticalLayout_2");
        mVerticalLayout_2->setContentsMargins(5, 5, 5, 5);
        mBtn_2_Widget = new QWidget(mMenu_2);
        mBtn_2_Layout = new QVBoxLayout(mBtn_2_Widget);
        mVerticalLayout_2->addWidget(mBtn_2_Widget);

        mLabel_2 = new QLabel(mBtn_2_Widget);
        mLabel_2->setObjectName("Label_2");
        mLabel_2->setText("Menu 2 - Right Menu");
        mLabel_2->setFont(font);
        mLabel_2->setStyleSheet("font-size: 16pt");
        mLabel_2->setAlignment(Qt::AlignCenter);
        mBtn_2_Layout->addWidget(mLabel_2);

        mLabel_3 = new QLabel(mBtn_2_Widget);
        mLabel_3->setObjectName("Label_3");
        mLabel_3->setText("Example Menu");
        font.setPointSize(9);
        mLabel_3->setFont(font);
        mLabel_3->setStyleSheet("font-size: 9pt");
        mLabel_3->setAlignment(Qt::AlignCenter);
        mLabel_3->setWordWrap(true);
        mBtn_2_Layout->addWidget(mLabel_3);
        mMenus->addWidget(mMenu_2);

        mMainPagesLayout->addWidget(mMenus);
        mMenus->setCurrentIndex(1);
    }


};