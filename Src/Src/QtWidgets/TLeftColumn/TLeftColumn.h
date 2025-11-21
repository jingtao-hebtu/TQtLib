/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumn.h
   Author : tao.jing
   Date   : 2024/7/11
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTCOLUMN_H
#define QTONEDARK_TLEFTCOLUMN_H

#include <QWidget>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"

class QFrame;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;


namespace T_QtBase {

    class TLeftColumnIcon;
    class TLeftColumnButton;

    class TAO_UTIL_API TLeftColumn : public QWidget, public TFormatWid {

    Q_OBJECT

    public:
        TLeftColumn(QWidget *parent, QWidget *app_parent,
                    std::initializer_list<std::pair<std::string, std::string>> args = {},
                    std::initializer_list<std::pair<std::string, std::string>> op_args = {});

        void setMenu(const QString& name, const QString& title, const QString& icon_path);

    signals:

        void btnClicked(QObject *sender_btn);

        void btnReleased(QObject *sender_btn);

    public slots:

        void onHandleBtnClicked();

        void onHandleBtnReleased();

    private:
        void init();

        void setupUi();

        void setupContentUi();

    private:
        QWidget *mParent {nullptr};
        QWidget *mAppParent {nullptr};

        QVBoxLayout *mBaseLayout {nullptr};

        QFrame *mTitleFrame {nullptr};
        QVBoxLayout *mTitleBaseLayout {nullptr};
        QFrame *mTitleBgFrame {nullptr};
        QHBoxLayout *mTitleBgLayout {nullptr};

        QFrame *mIconFrame {nullptr};
        QVBoxLayout *mIconLayout {nullptr};
        TLeftColumnIcon *mIcon {nullptr};

        QLabel *mTitleLabel {nullptr};

        QFrame *mBtnFrame {nullptr};
        TLeftColumnButton *mBtnClose {nullptr};

        // Content
        QFrame *mContentFrame {nullptr};
        QVBoxLayout *mMainPagesVLayout {nullptr};
        QStackedWidget *mMenus {nullptr};

        // Menu 1
        QWidget *mMenu1 {nullptr};
        QVBoxLayout *mMenuVLayout1 {nullptr};
        QWidget *mMenu1_BtnWidget1 {nullptr};
        QVBoxLayout *mMenu1_BtnVLayout1 {nullptr};
        QWidget *mMenu1_BtnWidget2 {nullptr};
        QVBoxLayout *mMenu1_BtnVLayout2 {nullptr};
        QWidget *mMenu1_BtnWidget3 {nullptr};
        QVBoxLayout *mMenu1_BtnVLayout3 {nullptr};
        QLabel *mMenu1_Label1 {nullptr};

        // Menu 2
        QWidget *mMenu2 {nullptr};
        QVBoxLayout *mMenuVLayout2 {nullptr};
        QWidget *mMenu2_BtnWidget1 {nullptr};
        QVBoxLayout *mMenu2_BtnVLayout1 {nullptr};
        QLabel *mMenu2_Label1 {nullptr};
        QLabel *mMenu2_Label2 {nullptr};

        QMap<QString, QWidget*> mMenuMap;
    };

};


#endif //QTONEDARK_TLEFTCOLUMN_H
