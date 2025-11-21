/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTitleBar.cpp
   Author : tao.jing
   Date   : 2024/6/8
   Brief  :
**************************************************************************/
#include "TTitleBar.h"
#include <QLabel>
#include <QFrame>
#include <QVBoxLayout>
#include <QSvgWidget>
#include <QMouseEvent>
#include "TDiv.h"
#include "TTitleButton.h"
#include "TException.h"


namespace T_QtBase {

    static TFormatString TStyleString = R"(
        QFrame {
            background-color: {bg_color};
            border-radius: {border_radius}px;
        }
    )";

    static std::map<std::string, std::string> TStyleDefaultParams{
            {"logo_width",              "100"},
            {"logo_image",              ":Images/tju.svg"},
            {"border_radius",           "8"},

            {"div_color",               "#3C4454"},
            {"title_font_size",         "10"},
            {"font_family",             "Segoe UI"},

            {"bg_color",                "#2C313C"},
            {"context_color",           "#6C99F4"},

            {"btn_height",              "30"},
            {"btn_width",               "30"},
            {"btn_bg_color",            "#343B48"},
            {"btn_bg_color_hover",      "#3C4454"},
            {"btn_bg_color_pressed",    "#2C313C"},
            {"icon_color",              "#C3CCDF"},
            {"icon_color_hover",        "#DCE1EC"},
            {"icon_color_pressed",      "#EDF0F5"},
            {"icon_color_active",       "#F5F6F9"},

            {"tooltip_bg_color",        "#1B1E23"},
            {"tooltip_text_foreground", "#8A95AA"},
    };


    TTitleBar::TTitleBar(QWidget *parent,
                         QWidget *app_parent,
                         TBase::TStrListParam args)
            : TDraggableWidget(parent, app_parent), mAppParent(app_parent), mInitArgs(args),
              TFormatWid(TStyleString, TStyleDefaultParams, args) {
        init(args);
    }

    void TTitleBar::init(TBase::TStrListParam args) {
        setupUi(args);
        formatStyleString();

        initActions();
    }

    void TTitleBar::setupUi(TBase::TStrListParam args) {
        mTitleBarLayout = new QVBoxLayout();
        setLayout(mTitleBarLayout);

        // Bg
        mBgFrame = new QFrame(this);
        mBgLayout = new QHBoxLayout(mBgFrame);
        mBgLayout->setContentsMargins(5, 0, 5, 0);
        mBgLayout->setSpacing(0);
        mTitleBarLayout->addWidget(mBgFrame);

        // Divs
        mLogoToLabelDiv = new TDiv(this, {
                {"color",    getParam<std::string>("div_color")},
                {"obj_name", "LogoToLabelDiv"}});
        mLabelToCustomBtnDiv = new TDiv(this, {
                {"color",    getParam<std::string>("div_color")},
                {"obj_name", "LabelToCustomBtnDiv"}});
        mCustomBtnToSysBtnDiv = new TDiv(this, {
                {"color",    getParam<std::string>("div_color")},
                {"obj_name", "CustomBtnToSysBtnDivDiv"}});

        // Logo
        mTopLogo = new QLabel(this);
        mTopLogo->setObjectName("TopLogo");
        mTopLogo->setMinimumWidth(getParam<int>("logo_width"));
        mTopLogo->setMaximumWidth(getParam<int>("logo_width"));
        mTopLogoLayout = new QVBoxLayout(mTopLogo);
        mTopLogoLayout->setContentsMargins(0, 0, 0, 0);
        mLogoSvg = new QSvgWidget();
        mLogoSvg->load(QString(getParam<std::string>("logo_image").c_str()));
        //mLogoSvg->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        mTopLogoLayout->addWidget(mLogoSvg, Qt::AlignCenter, Qt::AlignCenter);

        // Title label
        mTitleLabel = new QLabel(this);
        mTitleLabel->setObjectName("TitleLabel");
        mTitleLabel->setAlignment(Qt::AlignVCenter);
        mTitleLabel->setStyleSheet((
                                           "font: " + getParam<std::string>("title_font_size")
                                           + "pt " + getParam<std::string>("font_family")
                                   ).c_str());

        // Customized buttons
        mCustomBtnLayout = new QHBoxLayout();
        mCustomBtnLayout->setContentsMargins(0, 0, 0, 0);
        mCustomBtnLayout->setSpacing(3);

        // System buttons
        mSystemBtnLayout = new QHBoxLayout();
        mSystemBtnLayout->setContentsMargins(0, 0, 0, 0);
        mSystemBtnLayout->setSpacing(3);
        mMinimizeBtn = new TTitleButton(this, mAppParent, false, args, {
                {"obj_name",         "TitleBarMinimizeBtn"},
                {"radius",           "8"},
                {"tooltip_text",     "Minimize"},
                {"icon_path",        ":Icons/SystemButtons/png/Minimize.png"},

                {"top_margin",       "5"},
                {"height",           getParam<std::string>("btn_height")},
                {"width",            getParam<std::string>("btn_width")},
                {"bg_color",         getParam<std::string>("btn_bg_color")},
                {"bg_color_hover",   getParam<std::string>("btn_bg_color_hover")},
                {"bg_color_pressed", getParam<std::string>("btn_bg_color_pressed")}
        });
        mMaximizeBtn = new TTitleButton(this, mAppParent, false, args, {
                {"obj_name",         "TitleBarMaximumBtn"},
                {"radius",           "8"},
                {"tooltip_text",     "Maximum"},
                {"icon_path",        ":Icons/SystemButtons/png/Maximize.png"},

                {"top_margin",       "5"},
                {"height",           getParam<std::string>("btn_height")},
                {"width",            getParam<std::string>("btn_width")},
                {"bg_color",         getParam<std::string>("btn_bg_color")},
                {"bg_color_hover",   getParam<std::string>("btn_bg_color_hover")},
                {"bg_color_pressed", getParam<std::string>("btn_bg_color_pressed")}
        });
        mCloseBtn = new TTitleButton(this, mAppParent, false, args, {
                {"obj_name",         "TitleBarCloseBtn"},
                {"radius",           "8"},
                {"tooltip_text",     "Close"},
                {"icon_path",        ":Icons/SystemButtons/png/Close.png"},

                {"top_margin",       "5"},
                {"height",           getParam<std::string>("btn_height")},
                {"width",            getParam<std::string>("btn_width")},
                {"bg_color",         getParam<std::string>("btn_bg_color")},
                {"bg_color_hover",   getParam<std::string>("btn_bg_color_hover")},
                {"bg_color_pressed", getParam<std::string>("btn_bg_color_pressed")}
        });
        connect(mMinimizeBtn, SIGNAL(clicked()), this, SLOT(onHandlerBtnClicked()));
        connect(mMaximizeBtn, SIGNAL(clicked()), this, SLOT(onHandlerBtnClicked()));
        connect(mCloseBtn, SIGNAL(clicked()), this, SLOT(onHandlerBtnClicked()));

        mSystemBtnLayout->addWidget(mMinimizeBtn);
        mSystemBtnLayout->addWidget(mMaximizeBtn);
        mSystemBtnLayout->addWidget(mCloseBtn);

        mBgLayout->addWidget(mTopLogo);
        mBgLayout->addWidget(mLogoToLabelDiv);
        mBgLayout->addWidget(mTitleLabel);
        mBgLayout->addWidget(mLabelToCustomBtnDiv);
        mBgLayout->addLayout(mCustomBtnLayout);
        mBgLayout->addLayout(mSystemBtnLayout);
    }

    void TTitleBar::initActions() {
        mTopLogo->installEventFilter(this);
        mLogoToLabelDiv->installEventFilter(this);
        mTitleLabel->installEventFilter(this);
        mLabelToCustomBtnDiv->installEventFilter(this);
        mCustomBtnToSysBtnDiv->installEventFilter(this);

        connect(this, SIGNAL(deActiveAll()), this, SLOT(onDeActiveAll()));
        connect(this, SIGNAL(maximizeRestore()), this, SLOT(onMaximizeRestore()));
    }

    void TTitleBar::addCustomizedButtons(
            const std::vector<std::initializer_list<std::pair<std::string, std::string>>> &btn_args) {
        bool is_active = false;
        QString btn_obj_name;
        for (auto btn_arg: btn_args) {
            for (const auto &arg: btn_arg) {
                if (arg.first == "is_active") {
                    is_active = (arg.second == "true");
                } else if (arg.first == "obj_name") {
                    btn_obj_name = arg.second.c_str();
                }
            }
            auto menu_btn = new TTitleButton(this, mAppParent, is_active, mInitArgs, btn_arg);
            mCustomBtnMap[btn_obj_name] = menu_btn;
            // signals
            connect(menu_btn, SIGNAL(clicked()), this, SLOT(onHandlerBtnClicked()));
            connect(menu_btn, SIGNAL(released()), this, SLOT(onHandlerBtnReleased()));
            mCustomBtnLayout->addWidget(menu_btn);
        }
        mCustomBtnLayout->addWidget(mCustomBtnToSysBtnDiv);
    }

    void TTitleBar::onMaximizeRestore() {
        if (mAppParent == nullptr) {
            return;
        }

        if (mAppParent->isMaximized()) {
            mAppParent->showNormal();
            mMaximizeBtn->setIcon(":Icons/SystemButtons/png/Maximize.png");
        } else {
            mAppParent->showMaximized();
            mMaximizeBtn->setIcon(":Icons/SystemButtons/png/Restore.png");
        }
    }

    void TTitleBar::onHandlerBtnClicked() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnClicked(sender_btn);
        }
    }

    void TTitleBar::onHandlerBtnReleased() {
        QObject *sender_btn = sender();
        if (sender_btn) {
            emit btnReleased(sender_btn);
        }
    }

    bool TTitleBar::eventFilter(QObject *watched, QEvent *event) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            auto *mouseEvent = dynamic_cast<QMouseEvent *>(event);
            if (mouseEvent->button() == Qt::LeftButton) {
                if (watched == findChild<QLabel *>("TopLogo") ||
                    watched == findChild<QLabel *>("TitleLabel") ||
                    watched == findChild<TDiv *>("LogoToLabelDiv") ||
                    watched == findChild<TDiv *>("LabelToCustomBtnDiv")) {
                    onMaximizeRestore();
                    return true;
                }
            }
        }
        return TDraggableWidget::eventFilter(watched, event);
    }

    TTitleButton *TTitleBar::getTitleBtnByObjName(const QString &obj_name) {
        if (mCustomBtnMap.find(obj_name) != mCustomBtnMap.end()) {
            return mCustomBtnMap[obj_name];
        } else {
            TBASE_LOG_THROW_RUNTIME("Invalid TitleButton obj name %s", obj_name.toStdString().c_str());
        }
    }

    void TTitleBar::onDeActiveAll() {
        for (auto btn : mCustomBtnMap) {
            btn->setActive(false);
        }
    }


};
