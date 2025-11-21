/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumn.cpp
   Author : tao.jing
   Date   : 2024/7/11
   Brief  : 
**************************************************************************/
#include "TLeftColumn.h"
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "TleftColumnIcon.h"
#include "TLeftColumnButton.h"
#include "TException.h"


namespace T_QtBase {

    static TFormatString TStyleString = R"(
        #TitleBgFrame {
            background-color: {bg_color};
            border-radius: {border_radius}px;
        }
        #IconFrame {
            background: none;
        }
        #TitleLabel {
            font-size: {text_title_size}pt;
            color: {text_title_color};
            padding-bottom: 2px;
            background: none;
        }
        #BtnFrame {
            background: none;
        }
        #ContentFrame {
            background: none;
        }
    )";

    static std::map<std::string, std::string> TStyleDefaultParams{
            {"bg_color",           "#1B1E23"},
            {"border_radius",      "8"},

            {"text_title",         "Settings Left Frame"},
            {"text_title_size",    "10"},
            {"text_title_color",   "#8A95AA"},

            {"icon_path",          ":Icons/Customized/png/Setting.png"},
            {"icon_close_path",    ":Icons/LeftColumn/png/Close.png"},

            {"bg_color",           "#3C4454"},
            {"border_radius",      "8"},

            {"btn_color",          "#3C4454"},
            {"btn_color_hover",    "#343B48"},
            {"btn_color_pressed",  "#2C313C"},

            {"icon_color",         "#C3CCDF"},
            {"icon_color_hover",   "#DCE1EC"},
            {"icon_color_pressed", "#6C99F4"},
    };

    TLeftColumn::TLeftColumn(QWidget *parent, QWidget *app_parent,
                             std::initializer_list<std::pair<std::string, std::string>> args,
                             std::initializer_list<std::pair<std::string, std::string>> op_args)
            : QWidget(parent), TFormatWid(TStyleString, TStyleDefaultParams, args), mParent(parent),
              mAppParent(app_parent) {
        Q_UNUSED(op_args);
        init();
    }

    void TLeftColumn::init() {
        setupUi();
        formatStyleString();
    }

    void TLeftColumn::setupUi() {
        // Base layout
        mBaseLayout = new QVBoxLayout(this);
        mBaseLayout->setContentsMargins(0, 0, 0, 0);
        mBaseLayout->setSpacing(0);

        // Title frame
        mTitleFrame = new QFrame();
        mTitleFrame->setMaximumHeight(47);
        mTitleFrame->setMinimumHeight(47);

        // Title base layout
        mTitleBaseLayout = new QVBoxLayout(mTitleFrame);
        mTitleBaseLayout->setContentsMargins(5, 3, 5, 3);

        // Title BG
        mTitleBgFrame = new QFrame();
        mTitleBgFrame->setObjectName("TitleBgFrame");

        // Layout title BG
        mTitleBgLayout = new QHBoxLayout(mTitleBgFrame);
        mTitleBgLayout->setContentsMargins(5, 5, 5, 5);
        mTitleBgLayout->setSpacing(3);

        // Icon
        mIconFrame = new QFrame();
        mIconFrame->setObjectName("IconFrame");
        mIconFrame->setFixedSize(30, 30);
        mIconFrame->setStyleSheet("background: none;");

        mIconLayout = new QVBoxLayout(mIconFrame);
        mIconLayout->setContentsMargins(0, 0, 0, 0);
        mIconLayout->setSpacing(5);

        mIcon = new TLeftColumnIcon(this, getParam<std::string>("icon_path").c_str(),
                                    getParam<std::string>("icon_color").c_str());
        mIconLayout->addWidget(mIcon, Qt::AlignCenter, Qt::AlignCenter);

        // Label
        mTitleLabel = new QLabel(getParam<std::string>("text_title").c_str());
        mTitleLabel->setObjectName("TitleLabel");

        // Btn frame
        mBtnFrame = new QFrame();
        mBtnFrame->setObjectName("BtnFrame");
        mBtnFrame->setFixedSize(30, 30);

        mBtnClose = new TLeftColumnButton(mParent, mAppParent, false, {
                {"width",        "30"},
                {"height",       "30"},
                {"tooltip_text", "Hide"},
                {"icon_path",    getParam<std::string>("icon_close_path")},
        });
        mBtnClose->setObjectName("LeftColumnBtnClose");
        mBtnClose->setParent(mBtnFrame);
        connect(mBtnClose, SIGNAL(clicked()), this, SLOT(onHandleBtnClicked()));
        connect(mBtnClose, SIGNAL(released()), this, SLOT(onHandleBtnReleased()));

        mTitleBgLayout->addWidget(mIconFrame);
        mTitleBgLayout->addWidget(mTitleLabel);
        mTitleBgLayout->addWidget(mBtnFrame);

        mTitleBaseLayout->addWidget(mTitleBgFrame);

        // Content frame
        mContentFrame = new QFrame();
        mContentFrame->setObjectName("ContentFrame");

        mBaseLayout->addWidget(mTitleFrame);
        mBaseLayout->addWidget(mContentFrame);

        setupContentUi();
    }

    void TLeftColumn::setupContentUi() {
        if (mContentFrame == nullptr) {
            return;
        }

        if (mContentFrame->objectName().isEmpty()) {
            mContentFrame->setObjectName("LeftColumn");
        }
        mContentFrame->resize(240, 600);
        mContentFrame->setWindowTitle("LeftColumn");

        mMainPagesVLayout = new QVBoxLayout(mContentFrame);
        mMainPagesVLayout->setSpacing(0);
        mMainPagesVLayout->setObjectName("MainPagesLayout");
        mMainPagesVLayout->setContentsMargins(5, 5, 5, 5);

        mMenus = new QStackedWidget(mContentFrame);
        mMenus->setObjectName("Menus");

        // Menu 1
        mMenu1 = new QWidget(this);
        mMenu1->setObjectName("Menu1");
        mMenuMap["Info"] = mMenu1;

        mMenuVLayout1 = new QVBoxLayout(mMenu1);
        mMenuVLayout1->setSpacing(5);
        mMenuVLayout1->setObjectName("MenuVLayout1");
        mMenuVLayout1->setContentsMargins(5, 5, 5, 5);

        mMenu1_BtnWidget1 = new QWidget(mMenu1);
        mMenu1_BtnWidget1->setObjectName("Menu1_BtnWidget1");
        mMenu1_BtnWidget1->setMinimumSize(QSize(0, 40));
        mMenu1_BtnWidget1->setMaximumSize(QSize(16777215, 40));
        mMenu1_BtnVLayout1 = new QVBoxLayout(mMenu1_BtnWidget1);
        mMenu1_BtnVLayout1->setSpacing(0);
        mMenu1_BtnVLayout1->setObjectName("Menu1_BtnVLayout1");
        mMenu1_BtnVLayout1->setContentsMargins(0, 0, 0, 0);
        mMenuVLayout1->addWidget(mMenu1_BtnWidget1);

        mMenu1_BtnWidget2 = new QWidget(mMenu1);
        mMenu1_BtnWidget2->setObjectName("Menu1_BtnWidget2");
        mMenu1_BtnWidget2->setMinimumSize(QSize(0, 40));
        mMenu1_BtnWidget2->setMaximumSize(QSize(16777215, 40));
        mMenu1_BtnVLayout2 = new QVBoxLayout(mMenu1_BtnWidget2);
        mMenu1_BtnVLayout2->setSpacing(0);
        mMenu1_BtnVLayout2->setObjectName("Menu1_BtnVLayout2");
        mMenu1_BtnVLayout2->setContentsMargins(0, 0, 0, 0);
        mMenuVLayout1->addWidget(mMenu1_BtnWidget2);

        mMenu1_BtnWidget3 = new QWidget(mMenu1);
        mMenu1_BtnWidget3->setObjectName("Menu1_BtnWidget3");
        mMenu1_BtnWidget3->setMinimumSize(QSize(0, 40));
        mMenu1_BtnWidget3->setMaximumSize(QSize(16777215, 40));
        mMenu1_BtnVLayout3 = new QVBoxLayout(mMenu1_BtnWidget3);
        mMenu1_BtnVLayout3->setSpacing(0);
        mMenu1_BtnVLayout3->setObjectName("Menu1_BtnVLayout3");
        mMenu1_BtnVLayout3->setContentsMargins(0, 0, 0, 0);
        mMenuVLayout1->addWidget(mMenu1_BtnWidget3);

        mMenu1_Label1 = new QLabel(mMenu1);
        mMenu1_Label1->setObjectName("Menu1_Label1");
        mMenu1_Label1->setText("Menu 1 - Left Menu");
        QFont font_1;
        font_1.setPointSize(16);
        mMenu1_Label1->setFont(font_1);
        mMenu1_Label1->setStyleSheet("font-size: 16pt");
        mMenu1_Label1->setAlignment(Qt::AlignCenter);
        mMenuVLayout1->addWidget(mMenu1_Label1);

        mMenus->addWidget(mMenu1);

        // Menu 2
        mMenu2 = new QWidget(this);
        mMenu2->setObjectName("Menu2");
        mMenuMap["Setting"] = mMenu2;
        mMenuVLayout2 = new QVBoxLayout(mMenu2);
        mMenuVLayout2->setSpacing(5);
        mMenuVLayout2->setObjectName("MenuVLayout2");
        mMenuVLayout2->setContentsMargins(5, 5, 5, 5);

        mMenu2_BtnWidget1 = new QWidget(mMenu2);
        mMenu2_BtnWidget1->setObjectName("Menu2_BtnWidget1");
        mMenu2_BtnWidget1->setMinimumSize(QSize(0, 40));
        mMenu2_BtnWidget1->setMaximumSize(QSize(16777215, 40));
        mMenu2_BtnVLayout1 = new QVBoxLayout(mMenu2_BtnWidget1);
        mMenu2_BtnVLayout1->setSpacing(0);
        mMenu2_BtnVLayout1->setObjectName("Menu2_BtnVLayout1");
        mMenu2_BtnVLayout1->setContentsMargins(0, 0, 0, 0);
        mMenuVLayout2->addWidget(mMenu2_BtnWidget1);

        mMenu2_Label1 = new QLabel(mMenu2);
        mMenu2_Label1->setObjectName("Menu2_Label1");
        mMenu2_Label1->setText("Menu 2 - Left Menu");
        mMenu2_Label1->setFont(font_1);
        mMenu2_Label1->setStyleSheet("font-size: 16pt");
        mMenu2_Label1->setAlignment(Qt::AlignCenter);
        mMenuVLayout2->addWidget(mMenu2_Label1);

        mMenu2_Label2 = new QLabel(mMenu2);
        mMenu2_Label2->setObjectName("Menu2_Label2");
        mMenu2_Label2->setText("Menu 3 - Left Menu");
        QFont font_2;
        font_2.setPointSize(16);
        mMenu2_Label2->setFont(font_2);
        mMenu2_Label2->setStyleSheet("font-size: 16pt");
        mMenu2_Label2->setAlignment(Qt::AlignCenter);
        mMenu2_Label2->setWordWrap(true);
        mMenuVLayout2->addWidget(mMenu2_Label2);

        mMenus->addWidget(mMenu2);

        mMainPagesVLayout->addWidget(mMenus);
        mMenus->setCurrentIndex(0);
    }

    void TLeftColumn::setMenu(const QString &name, const QString &title, const QString &icon_path) {
        if (!mMenuMap.contains(name)) {
            TBASE_LOG_THROW_RUNTIME("TLeftColumn not having menu name %s.", name.toStdString().c_str());
        }
        mMenus->setCurrentWidget(mMenuMap[name]);
        mTitleLabel->setText(title);
        mIcon->setIcon(icon_path);
    }

    void TLeftColumn::onHandleBtnClicked() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnClicked(sender_btn);
        }
    }

    void TLeftColumn::onHandleBtnReleased() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnReleased(sender_btn);
        }
    }


};
