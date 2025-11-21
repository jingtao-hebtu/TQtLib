/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenu.cpp
   Author : tao.jing
   Date   : 2024/6/18
   Brief  :
**************************************************************************/
#include "TLeftMenu.h"
#include <QVBoxLayout>
#include <QFrame>
#include <QPropertyAnimation>
#include "TLeftMenuButton.h"
#include "TLeftMenuDiv.h"
#include "TException.h"


namespace T_QtBase {

    static TFormatString TStyleString = R"(
        #LeftMenuBgFrame {
            background-color: {bg_color};
            border-radius: {border_radius}px;
        }
    )";

    static std::map<std::string, std::string> TStyleDefaultParams{
            {"minimum_width",           "50"},
            {"maximum_width",           "240"},
            {"duration_time",           "500"},
            {"border_radius",           "8"},

            {"icon_path",
                                        ":Icons/Base/png/NoImg.png"},
            {"icon_path_close",
                                        ":Icons/Base/png/NoImg.png"},

            {"bg_color",                "#1B1E23"},
            {"context_color",           "#568AF2"},
            {"text_active",             "#DCE1EC"},

            {"btn_width",               "50"},
            {"btn_bg_color",            "#1B1E23"},
            {"btn_bg_color_hover",      "#1B1E23"},
            {"btn_bg_color_pressed",    "#272C36"},
            {"div_color",               "#272C36"},

            {"icon_color",              "#C3CCDF"},
            {"icon_color_hover",        "#DCE1EC"},
            {"icon_color_pressed",      "#EDF0F5"},
            {"icon_color_active",       "#F5F6F9"},

            {"toggle_text",             "Hide Menu"},
            {"tooltip_bg_color",        "#1B1E23"},
            {"tooltip_text_foreground", "#8A95AA"},
    };


    TLeftMenu::TLeftMenu(QWidget *parent, QWidget *app_parent,
                         std::initializer_list<std::pair<std::string, std::string>> args)
            : QWidget(parent), TFormatWid(TStyleString, TStyleDefaultParams, args), mParent(parent),
              mAppParent(app_parent), mInitArgs(args) {
        init();
    }

    void TLeftMenu::init() {
        setupUi();
        formatStyleString();
        initAction();
    }

    void TLeftMenu::setupUi() {
        setObjectName("LeftMenu");
        mLeftMenuLayout = new QVBoxLayout();
        setLayout(mLeftMenuLayout);
        mLeftMenuLayout->setContentsMargins(0, 0, 0, 0);

        mBgFrame = new QFrame();
        mBgFrame->setObjectName("LeftMenuBgFrame");
        mTopFrame = new QFrame();
        mBottomFrame = new QFrame();

        mBgVLayout = new QVBoxLayout(mBgFrame);
        mBgVLayout->setContentsMargins(0, 0, 0, 0);
        mTopVLayout = new QVBoxLayout(mTopFrame);
        mTopVLayout->setContentsMargins(0, 0, 0, 0);
        mTopVLayout->setSpacing(1);
        mBottomVLayout = new QVBoxLayout(mBottomFrame);
        mBottomVLayout->setContentsMargins(0, 0, 0, 0);
        mBottomVLayout->setSpacing(1);

        mBgVLayout->addWidget(mTopFrame, Qt::AlignTop);
        mBgVLayout->addWidget(mBottomFrame, Qt::AlignTop);
        mLeftMenuLayout->addWidget(mBgFrame, Qt::AlignTop);

        mToggleBtn = new TLeftMenuButton(this, mAppParent, mInitArgs, {
                {"obj_name",         "MinimizeBtn"},
                {"full_text",        "Hide menu"},
                {"tooltip_text",     "Show menu"},
                {"radius",           "8"},
                {"width",            getParam<std::string>("btn_width")},
                {"bg_color",         getParam<std::string>("btn_bg_color")},
                {"bg_color_hover",   getParam<std::string>("btn_bg_color_hover")},
                {"bg_color_pressed", getParam<std::string>("btn_bg_color_pressed")},

                {"icon_path",        ":Icons/LeftMenu/png/Menu.png"},
                {"icon_close_path",  ":Icons/LeftMenu/png/MenuClose.png"},
                {"icon_active_path", ":Icons/LeftMenu/png/MenuActive.png"},
        });

        mTopDiv = new TLeftMenuDiv(this, {{"color",    getParam<std::string>("div_color")},
                                          {"obj_name", "LeftMenuTopDiv"}});

        mBottomDiv = new TLeftMenuDiv(this, {{"color",    getParam<std::string>("div_color")},
                                             {"obj_name", "LeftMenuBottomDiv"}});
        mBottomDiv->hide();

        mTopVLayout->addWidget(mToggleBtn);
        mTopVLayout->addWidget(mTopDiv);
        mBottomVLayout->addWidget(mBottomDiv);

        // Toggle animation
        mToggleAnimation = new QPropertyAnimation(mParent, "minimumWidth");
        mToggleAnimation->stop();
    }

    void TLeftMenu::initAction() {
        connect(mToggleBtn, SIGNAL(clicked()), this, SLOT(onToggleAnimation()));

        connect(this, SIGNAL(selectOne(const QString &)), this, SLOT(onSelectOne(const QString &)));
        connect(this, SIGNAL(selectOneTab(const QString &)), this, SLOT(onSelectOneTab(const QString &)));
        connect(this, SIGNAL(deselectAll()), this, SLOT(onDeselectAll()));
        connect(this, SIGNAL(deselectAllTab()), this, SLOT(onDeselectAllTab()));
    }

    void TLeftMenu::onToggleAnimation() {
        if (width() <= getParam<int>("minimum_width") + 10) {
            mToggleAnimation->setStartValue(width());
            mToggleAnimation->setEndValue(getParam<int>("maximum_width"));
            mToggleBtn->setActiveToggle(true);
        } else {
            mToggleAnimation->setStartValue(width());
            mToggleAnimation->setEndValue(getParam<int>("minimum_width"));
            mToggleBtn->setActiveToggle(false);
        }
        mToggleAnimation->setEasingCurve(QEasingCurve::InOutCubic);
        mToggleAnimation->setDuration(getParam<int>("duration_time"));
        mToggleAnimation->start();
    }

    void TLeftMenu::onSelectOne(const QString &name) {
        for (auto btn: findChildren<TLeftMenuButton *>()) {
            if (btn->objectName() == name) {
                btn->setActive(true);
            } else {
                btn->setActive(false);
            }
        }
    }

    void TLeftMenu::onSelectOneTab(const QString &name) {
        for (auto btn: findChildren<TLeftMenuButton *>()) {
            if (btn->objectName() == name) {
                btn->setActiveTab(true);
            } else {
                btn->setActiveTab(false);
            }
        }
    }

    void TLeftMenu::onDeselectAll() {
        for (auto btn: findChildren<TLeftMenuButton *>()) {
            btn->setActive(false);
        }
    }

    void TLeftMenu::onDeselectAllTab() {
        for (auto btn: findChildren<TLeftMenuButton *>()) {
            btn->setActiveTab(false);
        }
    }

    void TLeftMenu::addCustomizedButtons(
            const std::vector<std::initializer_list<std::pair<std::string, std::string>>> &btn_args) {
        bool show_top = false;
        QString btn_name;
        for (auto btn_arg: btn_args) {
            for (const auto &arg: btn_arg) {
                if (arg.first == "show_top") {
                    show_top = (arg.second == "true");
                } else if (arg.first == "obj_name") {
                    btn_name = arg.second.c_str();
                }
            }
            auto menu_btn = new TLeftMenuButton(this, mAppParent, mInitArgs, btn_arg);
            mCustomBtnMap[btn_name] = menu_btn;
            // signals
            connect(menu_btn, SIGNAL(clicked()), this, SLOT(onHandleBtnClicked()));
            connect(menu_btn, SIGNAL(released()), this, SLOT(onHandleBtnReleased()));
            if (show_top) {
                mTopVLayout->addWidget(menu_btn);
            } else {
                mBottomDiv->show();
                mBottomVLayout->addWidget(menu_btn);
            }
        }
    }

    void TLeftMenu::onHandleBtnClicked() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnClicked(sender_btn);
        }
    }

    void TLeftMenu::onHandleBtnReleased() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnReleased(sender_btn);
        }
    }

    TLeftMenuButton *TLeftMenu::getLeftMenuBtnByObjName(const QString &obj_name) {
        if (mCustomBtnMap.find(obj_name) != mCustomBtnMap.end()) {
            return mCustomBtnMap[obj_name];
        } else {
            TBASE_LOG_THROW_RUNTIME("Invalid LeftMenuBtn obj name %s.", obj_name.toStdString().c_str());
        }
    }


};

