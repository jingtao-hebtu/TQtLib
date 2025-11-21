/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenu.h
   Author : tao.jing
   Date   : 2024/6/18
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTMENU_H
#define QTONEDARK_TLEFTMENU_H

#include <QWidget>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


class QVBoxLayout;

class QFrame;

class QPropertyAnimation;


namespace T_QtBase {

    class TLeftMenuButton;

    class TLeftMenuDiv;

    class TAO_UTIL_API TLeftMenu : public QWidget, public TFormatWid {

    Q_OBJECT

    public:
        explicit TLeftMenu(QWidget *parent, QWidget *app_parent,
                           std::initializer_list<std::pair<std::string, std::string>> args = {});

    public:
        void
        addCustomizedButtons(const std::vector<std::initializer_list<std::pair<std::string, std::string>>> &btn_args);

        TLeftMenuButton* getLeftMenuBtnByObjName(const QString& obj_name);

    private:
        void init();

        void setupUi();

        void initAction();

    signals:

        void btnClicked(QObject *sender_btn);

        void btnReleased(QObject *sender_btn);

        void selectOne(const QString &name);

        void selectOneTab(const QString &name);

        void deselectAll();

        void deselectAllTab();


    public slots:

        void onHandleBtnClicked();

        void onHandleBtnReleased();

        void onToggleAnimation();

        void onSelectOne(const QString &name);

        void onSelectOneTab(const QString &name);

        void onDeselectAll();

        void onDeselectAllTab();

    private:
        QWidget *mParent{nullptr};
        QWidget *mAppParent{nullptr};

        std::initializer_list<std::pair<std::string, std::string>> mInitArgs;

        // Ui
        QVBoxLayout *mLeftMenuLayout{nullptr};

        QFrame *mBgFrame{nullptr};
        QFrame *mTopFrame{nullptr};
        QFrame *mBottomFrame{nullptr};

        QVBoxLayout *mBgVLayout{nullptr};
        QVBoxLayout *mTopVLayout{nullptr};
        QVBoxLayout *mBottomVLayout{nullptr};

        QPropertyAnimation *mToggleAnimation{nullptr};

        TLeftMenuButton *mToggleBtn{nullptr};
        QMap<QString, TLeftMenuButton *> mCustomBtnMap;

        TLeftMenuDiv *mTopDiv;
        TLeftMenuDiv *mBottomDiv;
    };

};


#endif //QTONEDARK_TLEFTMENU_H
