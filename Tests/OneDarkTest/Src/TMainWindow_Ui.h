/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainWindow_Ui.h
   Author : tao.jing
   Date   : 2024/8/2
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TMAINWINDOW_UI_H
#define QTONEDARK_TMAINWINDOW_UI_H

#include <QString>

class QFrame;

class QWidget;

class QMainWindow;

class QVBoxLayout;

class QHBoxLayout;

class QPropertyAnimation;

class QParallelAnimationGroup;


namespace T_QtBase {

    class TWindow;

    class TLeftMenu;

    class TLeftColumn;

    class TRightColumn;

    class TTitleBar;

    class TMainPages_Ui;

    class TCreditsBar;

    class TGrips;

    class TDraggableWidget;

    class TMainWindow_Ui {

        friend class TMainWindow;

        enum E_UiColumnState {
            NoColumn_Activated = 0,
            LeftColumn_Activated = 1,
            RightColumn_Activated = 2,
        };

    public:
        void setupUi(TMainWindow *wid);

    public:
        void onLeftMenuClicked(const QString &name);

        void onLeftColumnClicked(const QString &name);

        void onTitleBarClicked(const QString &name);

        E_UiColumnState onToggleLeftColumn();

        E_UiColumnState onToggleRightColumn();

    private:
        void initUiLayouts();

        void initUiSettings();

        void initUiGrips();

        void initLeftMenu();

        void initAnimations();

        void initTitleBar();

        bool isLeftColumnVisible();

        bool isRightColumnVisible();

        E_UiColumnState startBoxAnimation(int left_box_width, int right_box_width, const QString &direction);

    protected:
        TMainWindow *mWid{nullptr};

        QWidget *mCentralWid{nullptr};
        QVBoxLayout *mCentralVLayout{nullptr};

        TWindow *mWindow{nullptr};

        // Left menu
        QFrame *mLeftMenuFrame{nullptr};
        QHBoxLayout *mLeftMenuHLayout{nullptr};
        TLeftMenu *mLeftMenu{nullptr};

        // Left column
        QFrame *mLeftColumnFrame{nullptr};
        QVBoxLayout *mLeftColumnVLayout{nullptr};
        TLeftColumn *mLeftColumn{nullptr};

        // Right frame
        QFrame *mRightAppFrame{nullptr};
        QVBoxLayout *mRightAppVLayout{nullptr};

        QFrame *mTitleBarFrame{nullptr};
        QVBoxLayout *mTitleBarVLayout{nullptr};
        TTitleBar *mTitleBar{nullptr};

        QFrame *mRightApp_ContentAreaFrame{nullptr};
        QHBoxLayout *mRightApp_ContentAreaHLayout{nullptr};

        QFrame *mRightApp_ContentArea_LeftFrame{nullptr};
        TMainPages_Ui *mRightApp_ContentArea_LeftFrame_Pages_Ui{nullptr};

        QFrame *mRightApp_ContentArea_RightFrame{nullptr};
        QVBoxLayout *mRightApp_ContentArea_RightVLayout{nullptr};

        TRightColumn *mRightApp_ContentArea_RightBgFrame{nullptr};

        QFrame *mCreditsFrame{nullptr};
        QVBoxLayout *mCreditsVLayout{nullptr};
        TCreditsBar *mCredits{nullptr};

        // Grips
        TGrips *mLeftGrip{nullptr};
        TGrips *mRightGrip{nullptr};
        TGrips *mTopGrip{nullptr};
        TGrips *mBottomGrip{nullptr};
        TGrips *mTopLeftGrip{nullptr};
        TGrips *mTopRightGrip{nullptr};
        TGrips *mBottomLeftGrip{nullptr};
        TGrips *mBottomRightGrip{nullptr};

        // Animation
        QPropertyAnimation *mLeftBoxAnimation{nullptr};
        QPropertyAnimation *mRightBoxAnimation{nullptr};
        QParallelAnimationGroup *mGroupAnimation{nullptr};
    };

};


#endif //QTONEDARK_TMAINWINDOW_UI_H
