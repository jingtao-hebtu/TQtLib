/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainWindow_Ui.cpp
   Author : tao.jing
   Date   : 2024/8/2
   Brief  :
**************************************************************************/
#include "TMainWindow_Ui.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "TMainWindow.h"
#include "TWindow.h"
#include "TLeftMenu.h"
#include "TLeftMenuButton.h"
#include "TLeftColumn.h"
#include "TRightColumn.h"
#include "TTitleBar.h"
#include "TTitleButton.h"
#include "TMainPages_Ui.h"
#include "TCreditsBar.h"
#include "TDraggableWidget.h"
#include "TGrips.h"
#include "TConfig.h"


namespace T_QtBase {

    void TMainWindow_Ui::setupUi(TMainWindow *wid) {
        mWid = wid;
        initUiLayouts();
        initUiSettings();
    }

    void TMainWindow_Ui::initUiLayouts() {
        auto startup_w = GET_ARR_INT_CONFIG(0, "startup_size");
        auto startup_h = GET_ARR_INT_CONFIG(1, "startup_size");
        mWid->resize(startup_w, startup_h);

        auto minimum_w = GET_ARR_INT_CONFIG(0, "minimum_size");
        auto minimum_h = GET_ARR_INT_CONFIG(1, "minimum_size");
        mWid->setMinimumSize(minimum_w, minimum_h);

        // --- Central Widget
        auto font_size = GET_INT_CONFIG("font", "text_size");
        auto font_family = GET_STR_CONFIG("font", "family");
        auto central_wid_color = GET_STR_CONFIG("app_color", "text_foreground");
        mCentralWid = new QWidget();
        mCentralWid->setStyleSheet(QString("font: %1 pt %2; color: %3;")
                                           .arg(QString::number(font_size), font_family.c_str(),
                                                central_wid_color.c_str()));
        mCentralVLayout = new QVBoxLayout(mCentralWid);
        if (GET_BOOL_CONFIG("custom_title_bar")) {
            //mCentralVLayout->setContentsMargins(3, 3, 3, 3);
            mCentralVLayout->setContentsMargins(0, 0, 0, 0);
            mCentralVLayout->setSpacing(0);
        } else {
            mCentralVLayout->setContentsMargins(0, 0, 0, 0);
        }

        // --- Window frame
        mWindow = new TWindow(mWid, {
                {"layout_type", "horizontal"},
                {"margin",       "0"},
                {"spacing",      "2"},
                {"bg_color",     GET_STR_CONFIG("app_color", "bg_one")},
                {"border_color", GET_STR_CONFIG("app_color", "bg_two")},
                {"text_color",   GET_STR_CONFIG("app_color", "text_foreground")},
        });
        if (!GET_BOOL_CONFIG("custom_title_bar")) {
            mWindow->setStyle({
                                      {"border_radius", "0"},
                                      {"border_size",   "0"},
                              });
        }
        mCentralVLayout->addWidget(mWindow);

        // --- Left menu
        auto left_menu_margin = GET_INT_CONFIG("left_menu_content_margins");
        auto left_menu_minimum = GET_INT_CONFIG("lef_menu_size", "minimum");
        mLeftMenuFrame = new QFrame();
        mLeftMenuFrame->setMaximumSize(left_menu_minimum + (left_menu_margin * 2), 17280);
        mLeftMenuFrame->setMinimumSize(left_menu_minimum + (left_menu_margin * 2), 0);

        mLeftMenuHLayout = new QHBoxLayout(mLeftMenuFrame);
        mLeftMenuHLayout->setContentsMargins(left_menu_margin, left_menu_margin,
                                             left_menu_margin, left_menu_margin);

        mLeftMenu = new TLeftMenu(mLeftMenuFrame, mCentralWid, {});
        mLeftMenuHLayout->addWidget(mLeftMenu);

        // --- Left column
        mLeftColumnFrame = new QFrame();
        auto left_column_minimum = GET_INT_CONFIG("left_column_size", "minimum");
        auto left_column_maximum = GET_INT_CONFIG("left_column_size", "maximum");
        Q_UNUSED(left_column_maximum);
        mLeftColumnFrame->setMaximumWidth(left_column_minimum);
        mLeftColumnFrame->setMinimumWidth(left_column_minimum);
        auto left_column_frame_bg_color = GET_STR_CONFIG("app_color", "bg_two");
        mLeftColumnFrame->setStyleSheet(QString("background: %1").arg(left_column_frame_bg_color.c_str()));

        mLeftColumnVLayout = new QVBoxLayout(mLeftColumnFrame);
        mLeftColumnVLayout->setContentsMargins(0, 0, 0, 0);

        mLeftColumn = new TLeftColumn(mWid, mCentralWid, {
                {"text_title",      "Settings Left Frame"},
                {"icon_path",       ":Icons/Customized/png/Setting.png"},
                {"icon_close_path", ":Icons/LeftColumn/png/Close.png"},
        });
        mLeftColumnVLayout->addWidget(mLeftColumn);

        // --- Right frame
        mRightAppFrame = new QFrame();
        mRightAppVLayout = new QVBoxLayout(mRightAppFrame);
        mRightAppVLayout->setContentsMargins(3, 0, 3, 3);
        mRightAppVLayout->setSpacing(3);

        // -- Title bar
        mTitleBarFrame = new QFrame();
        mTitleBarFrame->setMinimumHeight(60);
        mTitleBarFrame->setMaximumHeight(60);
        mTitleBarVLayout = new QVBoxLayout(mTitleBarFrame);
        mTitleBarVLayout->setContentsMargins(0, 0, 0, 0);

        mTitleBar = new TTitleBar(mWid, mWid, {
                {"logo_width", "160"},
                {"radius",     "8"},
                {"btn_height", "32"},
                {"btn_width",  "32"},

                {"bg_color",   "#343B48"},
                {"div_color",  "#3C4454"},
        });
        mTitleBarVLayout->addWidget(mTitleBar);

        // -- Content frame
        mRightApp_ContentAreaFrame = new QFrame();
        mRightApp_ContentAreaHLayout = new QHBoxLayout(mRightApp_ContentAreaFrame);
        mRightApp_ContentAreaHLayout->setContentsMargins(0, 0, 0, 0);
        mRightApp_ContentAreaHLayout->setSpacing(0);

        // - mRightApp_ContentArea_LeftFrame
        mRightApp_ContentArea_LeftFrame = new QFrame();
        mRightApp_ContentArea_LeftFrame_Pages_Ui = new TMainPages_Ui();
        mRightApp_ContentArea_LeftFrame_Pages_Ui->setupUi(mRightApp_ContentArea_LeftFrame);

        // - RightApp_ContentArea_RightFrame
        mRightApp_ContentArea_RightFrame = new QFrame();
        auto content_area_right_frame_minimum = GET_INT_CONFIG("right_column_size", "minimum");
        auto content_area_right_frame_maximum = GET_INT_CONFIG("right_column_size", "maximum");
        Q_UNUSED(content_area_right_frame_maximum);
        mRightApp_ContentArea_RightFrame->setMinimumWidth(content_area_right_frame_minimum);
        mRightApp_ContentArea_RightFrame->setMaximumWidth(content_area_right_frame_minimum);

        mRightApp_ContentArea_RightVLayout = new QVBoxLayout(mRightApp_ContentArea_RightFrame);
        mRightApp_ContentArea_RightVLayout->setContentsMargins(5, 5, 5, 5);
        mRightApp_ContentArea_RightVLayout->setSpacing(0);

        mRightApp_ContentArea_RightBgFrame = new TRightColumn(mWid, mWid, {});
        mRightApp_ContentArea_RightVLayout->addWidget(mRightApp_ContentArea_RightBgFrame);

        mRightApp_ContentAreaHLayout->addWidget(mRightApp_ContentArea_LeftFrame);
        mRightApp_ContentAreaHLayout->addWidget(mRightApp_ContentArea_RightFrame);

        // Credits
        mCreditsFrame = new QFrame();
        mCreditsFrame->setMinimumHeight(26);
        mCreditsFrame->setMaximumHeight(26);

        mCreditsVLayout = new QVBoxLayout(mCreditsFrame);
        mCreditsVLayout->setContentsMargins(0, 0, 0, 0);

        mCredits = new TCreditsBar(mCreditsFrame);
        mCreditsVLayout->addWidget(mCredits);

        // -- Right app
        mRightAppVLayout->addWidget(mTitleBarFrame);
        mRightAppVLayout->addWidget(mRightApp_ContentAreaFrame);
        mRightAppVLayout->addWidget(mCreditsFrame);

        // --- Add widgets to TWindow
        mWindow->layout()->addWidget(mLeftMenuFrame);
        mWindow->layout()->addWidget(mLeftColumnFrame);
        mWindow->layout()->addWidget(mRightAppFrame);

        mWid->setCentralWidget(mCentralWid);
    }

    void TMainWindow_Ui::initUiSettings() {
        mWid->setWindowTitle(GET_STR_CONFIG("app_name").c_str());
        if (GET_BOOL_CONFIG("custom_title_bar")) {
            mWid->setWindowFlag(Qt::FramelessWindowHint);
            mWid->setAttribute(Qt::WA_TranslucentBackground);
        }

        initUiGrips();
        initLeftMenu();
        initAnimations();

        initTitleBar();
    }

    void TMainWindow_Ui::initUiGrips() {
        mLeftGrip = new TGrips(mWid, LEFT);
        mRightGrip = new TGrips(mWid, RIGHT);
        mTopGrip = new TGrips(mWid, TOP);
        mBottomGrip = new TGrips(mWid, BOTTOM);
        mTopLeftGrip = new TGrips(mWid, TOP_LEFT);
        mTopRightGrip = new TGrips(mWid, TOP_RIGHT);
        mBottomLeftGrip = new TGrips(mWid, BOTTOM_LEFT);
        mBottomRightGrip = new TGrips(mWid, BOTTOM_RIGHT);
    }

    void TMainWindow_Ui::initLeftMenu() {
        mLeftMenu->addCustomizedButtons({
                                                {
                                                        {"obj_name", "BtnHome"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Home.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Home.png"},
                                                        {"full_text", "Home"},
                                                        {"tooltip_text", "Home page"},
                                                        {"show_top", "true"},
                                                        {"is_active", "true"}
                                                },
                                                {
                                                        {"obj_name", "BtnWidgets"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Widgets.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Widgets.png"},
                                                        {"full_text", "Show Custom Widgets"},
                                                        {"tooltip_text", "Show Custom Widgets"},
                                                        {"show_top", "true"},
                                                        {"is_active", "false"}
                                                },
                                                {
                                                        {"obj_name", "BtnVideo"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Video.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Video.png"},
                                                        {"full_text", "Open video"},
                                                        {"tooltip_text", "Open video"},
                                                        {"show_top", "true"},
                                                        {"is_active", "false"}
                                                },
                                                {
                                                        {"obj_name", "BtnOpenFolder"},
                                                        {"icon_path", ":Icons/LeftMenu/png/OpenFolder.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/OpenFolder.png"},
                                                        {"full_text", "Open folder"},
                                                        {"tooltip_text", "Open folder"},
                                                        {"show_top", "true"},
                                                        {"is_active", "false"}
                                                },
                                                {
                                                        {"obj_name", "BtnSave"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Save.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Save.png"},
                                                        {"full_text", "Save"},
                                                        {"tooltip_text", "Save"},
                                                        {"show_top", "true"},
                                                        {"is_active", "false"}
                                                },
                                                {
                                                        {"obj_name", "BtnInfo"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Info.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Info.png"},
                                                        {"full_text", "Info"},
                                                        {"tooltip_text", "Info"},
                                                        {"show_top", "false"},
                                                        {"is_active", "false"}
                                                },
                                                {
                                                        {"obj_name", "BtnSettings"},
                                                        {"icon_path", ":Icons/LeftMenu/png/Settings.png"},
                                                        {"icon_path_active", ":Icons/LeftMenu/png/Settings.png"},
                                                        {"full_text", "Settings"},
                                                        {"tooltip_text", "Settings"},
                                                        {"show_top", "false"},
                                                        {"is_active", "false"}
                                                },
                                        });
    }

    void TMainWindow_Ui::initAnimations() {
        mLeftBoxAnimation = new QPropertyAnimation(mLeftColumnFrame, "minimumWidth");
        mRightBoxAnimation = new QPropertyAnimation(mRightApp_ContentArea_RightFrame, "minimumWidth");

        auto animation_time = GET_INT_CONFIG("animation_time");
        mLeftBoxAnimation->setDuration(animation_time);
        mLeftBoxAnimation->setEasingCurve(QEasingCurve::InOutQuart);
        mRightBoxAnimation->setDuration(animation_time);
        mRightBoxAnimation->setEasingCurve(QEasingCurve::InOutQuart);

        mGroupAnimation = new QParallelAnimationGroup();
        mGroupAnimation->stop();
        mGroupAnimation->addAnimation(mLeftBoxAnimation);
        mGroupAnimation->addAnimation(mRightBoxAnimation);
    }

    void TMainWindow_Ui::initTitleBar() {
        mTitleBar->addCustomizedButtons({
                                                {
                                                        {"name", "search"},
                                                        {"is_active", "false"},
                                                        {"obj_name", "TopBarSearchBtn"},
                                                        {"top_margin", "5"},
                                                        {"height", "32"},
                                                        {"width", "32"},
                                                        {"btn_height", "30"},
                                                        {"btn_width", "30"},
                                                        {"icon_path", ":Icons/Customized/png/Search.png"},
                                                        {"tooltip_text", "Search"},
                                                },
                                                {
                                                        {"name", "setting"},
                                                        {"is_active", "false"},
                                                        {"obj_name", "TopBarSettingBtn"},
                                                        {"top_margin", "5"},
                                                        {"height", "32"},
                                                        {"width", "32"},
                                                        {"btn_height", "30"},
                                                        {"btn_width", "30"},
                                                        {"icon_path", ":Icons/Customized/png/Setting.png"},
                                                        {"tooltip_text", "Setting"},
                                                },
                                        });
    }

    void TMainWindow_Ui::onLeftMenuClicked(const QString &name) {
        if (name == "BtnHome") {
            mLeftMenu->onSelectOne(name);
            mRightApp_ContentArea_LeftFrame_Pages_Ui->mPages->setCurrentWidget(
                    mRightApp_ContentArea_LeftFrame_Pages_Ui->mHomePage);
        } else if (name == "BtnWidgets") {
            mLeftMenu->onSelectOne(name);
            mRightApp_ContentArea_LeftFrame_Pages_Ui->mPages->setCurrentWidget(
                    mRightApp_ContentArea_LeftFrame_Pages_Ui->mSettingPage);
        } else if (name == "BtnVideo") {
            mLeftMenu->onSelectOne(name);
            mRightApp_ContentArea_LeftFrame_Pages_Ui->mPages->setCurrentWidget(
                    mRightApp_ContentArea_LeftFrame_Pages_Ui->mVideoPage);
        } else if (name == "BtnInfo") {
            if (!isLeftColumnVisible()) {
                onToggleLeftColumn();
            }
            mLeftMenu->selectOneTab(name);
            mLeftColumn->setMenu("Info", "Info", ":Icons/LeftMenu/png/Info.png");
        } else if (name == "BtnSettings") {
            if (!isLeftColumnVisible()) {
                onToggleLeftColumn();
            }
            mLeftMenu->selectOneTab(name);
            mLeftColumn->setMenu("Setting", "Setting", ":Icons/LeftMenu/png/Settings.png");
        }
    }

    void TMainWindow_Ui::onLeftColumnClicked(const QString &name) {
        // Left column close btn
        if (name == "LeftColumnBtnClose") {
            if (isLeftColumnVisible()) {
                mLeftMenu->onDeselectAllTab();
            }
            onToggleLeftColumn();
        }
    }

    void TMainWindow_Ui::onTitleBarClicked(const QString &name) {
        if (name == "TopBarSettingBtn") {
            bool right_column_state = onToggleRightColumn() == RightColumn_Activated;
            auto btn = mTitleBar->getTitleBtnByObjName(name);
            btn->setActive(right_column_state);
            if (isLeftColumnVisible()) {
                mLeftMenu->onDeselectAllTab();
            }
        } else if (name == "TitleBarCloseBtn") {
            emit mWid->closeWnd();
        } else if (name == "TitleBarMinimizeBtn") {
            emit mWid->minimizeWnd();
        } else if (name == "TitleBarMaximumBtn") {
            emit mTitleBar->maximizeRestore();
        }
    }

    bool TMainWindow_Ui::isLeftColumnVisible() {
        if (mLeftColumnFrame->width() == 0) {
            return false;
        }
        return true;
    }

    bool TMainWindow_Ui::isRightColumnVisible() {
        if (mRightApp_ContentArea_RightFrame->width() == 0) {
            return false;
        }
        return true;
    }

    TMainWindow_Ui::E_UiColumnState TMainWindow_Ui::startBoxAnimation(int left_box_width, int right_box_width, const QString &direction) {
        auto minimum_left = GET_INT_CONFIG("left_column_size", "minimum");
        auto maximum_left = GET_INT_CONFIG("left_column_size", "maximum");
        auto minimum_right = GET_INT_CONFIG("right_column_size", "minimum");
        auto maximum_right = GET_INT_CONFIG("right_column_size", "maximum");

        E_UiColumnState ret = NoColumn_Activated;
        int left_end_width, right_end_width = 0;
        if (minimum_left == left_box_width && direction == "left") {
            left_end_width = maximum_left;
            ret = LeftColumn_Activated;
        } else {
            left_end_width = minimum_left;
        }
        if (minimum_right == right_box_width && direction == "right") {
            right_end_width = maximum_right;
            ret = RightColumn_Activated;
        } else {
            right_end_width = minimum_right;
        }

        mLeftBoxAnimation->setStartValue(left_box_width);
        mLeftBoxAnimation->setEndValue(left_end_width);
        mRightBoxAnimation->setStartValue(right_box_width);
        mRightBoxAnimation->setEndValue(right_end_width);

        mGroupAnimation->start();
        return ret;
    }

    TMainWindow_Ui::E_UiColumnState TMainWindow_Ui::onToggleLeftColumn() {
        auto ret = startBoxAnimation(mLeftColumnFrame->width(), mRightApp_ContentArea_RightFrame->width(), "left");
        if (isRightColumnVisible()) {
            mTitleBar->deActiveAll();
        }
        return ret;
    }

    TMainWindow_Ui::E_UiColumnState TMainWindow_Ui::onToggleRightColumn() {
        auto ret = startBoxAnimation(mLeftColumnFrame->width(), mRightApp_ContentArea_RightFrame->width(), "right");
        if (isLeftColumnVisible()) {
            mLeftMenu->deselectAllTab();
        }
        return ret;
    }

};