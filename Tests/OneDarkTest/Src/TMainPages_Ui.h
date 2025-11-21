/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainPages_Ui.h
   Author : tao.jing
   Date   : 2024/7/24
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TMAINPAGES_UI_H
#define QTONEDARK_TMAINPAGES_UI_H

#include <QMainWindow>


class QVBoxLayout;
class QHBoxLayout;
class QStackedWidget;
class QFrame;
class QLabel;
class QScrollArea;


namespace T_QtBase {

    class TMainPages_Ui {

        friend class TMainWindow_Ui;

    public:
        TMainPages_Ui();

        void setupUi(QFrame *win);

    private:
        void initPages();
        void initHomePage();
        void initSettingPage();
        void initVideoPage();

    protected:
        QFrame *mWin {nullptr};

        QVBoxLayout *mMainPageVLayout {nullptr};
        QStackedWidget *mPages {nullptr};

        // Home Page
        QWidget *mHomePage {nullptr};
        QVBoxLayout *mHomePageVLayout {nullptr};
        QFrame *mWelcomeBase {nullptr};
        QVBoxLayout *mCenterPageVLayout {nullptr};
        QFrame *mLogo {nullptr};
        QVBoxLayout *mLogoVLayout {nullptr};
        QLabel *mLabel {nullptr};

        // Setting Page
        QWidget *mSettingPage {nullptr};
        QVBoxLayout *mSettingPageVLayout {nullptr};
        QScrollArea *mSettingPageScrollArea {nullptr};
        QWidget *mSettingPageContent {nullptr};
        QVBoxLayout *mSettingPageContentVLayout {nullptr};

        QLabel *mSettingPageContentTitleLabel {nullptr};
        QLabel *mSettingPageContentDescLabel {nullptr};

        QHBoxLayout *mRow1HLayout {nullptr};
        QHBoxLayout *mRow2HLayout {nullptr};
        QHBoxLayout *mRow3HLayout {nullptr};
        QHBoxLayout *mRow4HLayout {nullptr};
        QHBoxLayout *mRow5HLayout {nullptr};
        QHBoxLayout *mRow6HLayout {nullptr};

        // Video page
        QWidget *mVideoPage {nullptr};
        QHBoxLayout *mVideoPageHLayout {nullptr};
        QVBoxLayout *mVideoCtlBtnVLayout {nullptr};

        QVBoxLayout *mVideoVLayout {nullptr};
        QLabel *mVideoLabel {nullptr};
    };

};


#endif //QTONEDARK_TMAINPAGES_UI_H
