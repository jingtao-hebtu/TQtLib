/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TMainPages_Ui.cpp
   Author : tao.jing
   Date   : 2024/7/24
   Brief  :
**************************************************************************/
#include "TMainPages_Ui.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include "TException.h"


namespace T_QtBase {

    TMainPages_Ui::TMainPages_Ui() {

    }

    void TMainPages_Ui::setupUi(QFrame *win) {
        mWin = win;
        mWin->setObjectName("MainWindow");
        mWin->resize(860, 600);

        mMainPageVLayout = new QVBoxLayout(mWin);
        mMainPageVLayout->setSpacing(0);
        mMainPageVLayout->setObjectName("MainPageLayout");
        mMainPageVLayout->setContentsMargins(5, 5, 5, 5);

        initPages();
    }

    void TMainPages_Ui::initPages() {
        mPages = new QStackedWidget(mWin);
        mPages->setObjectName("Pages");

        initHomePage();
        initSettingPage();
        initVideoPage();

        mMainPageVLayout->addWidget(mPages);
        mPages->setCurrentIndex(0);
    }

    void TMainPages_Ui::initHomePage() {
        // Home Page
        mHomePage = new QWidget(mWin);
        mHomePage->setObjectName("HomePage");
        mHomePage->setStyleSheet("font-size: 14pt");

        mHomePageVLayout = new QVBoxLayout(mHomePage);
        mHomePageVLayout->setSpacing(5);
        mHomePageVLayout->setObjectName("Page1VLayout");
        mHomePageVLayout->setContentsMargins(5, 5, 5, 5);

        mWelcomeBase = new QFrame(mHomePage);
        mWelcomeBase->setObjectName("WelcomeBase");
        mWelcomeBase->setMinimumSize(QSize(300, 150));
        mWelcomeBase->setMaximumSize(QSize(300, 150));
        mWelcomeBase->setFrameShape(QFrame::NoFrame);
        mWelcomeBase->setFrameShadow(QFrame::Raised);

        mCenterPageVLayout = new QVBoxLayout(mWelcomeBase);
        mCenterPageVLayout->setSpacing(10);
        mCenterPageVLayout->setObjectName("CenterPageVLayout");
        mCenterPageVLayout->setContentsMargins(0, 0, 0, 0);

        mLogo = new QFrame(mWelcomeBase);
        mLogo->setObjectName("Logo");
        mLogo->setMinimumSize(QSize(300, 90));
        mLogo->setMaximumSize(QSize(300, 90));
        mLogo->setFrameShape(QFrame::NoFrame);
        mLogo->setFrameShadow(QFrame::Raised);

        mLogoVLayout = new QVBoxLayout(mLogo);
        mLogoVLayout->setSpacing(0);
        mLogoVLayout->setObjectName("LogoVLayout");
        mLogoVLayout->setContentsMargins(0, 0, 0, 0);

        mCenterPageVLayout->addWidget(mLogo);

        mLabel = new QLabel(mWelcomeBase);
        mLabel->setObjectName("Label");
        mLabel->setAlignment(Qt::AlignCenter);
        mLabel->setText("@TJU AI Powered");

        mCenterPageVLayout->addWidget(mLabel);
        mHomePageVLayout->addWidget(mWelcomeBase, 0, Qt::AlignHCenter);
        mPages->addWidget(mHomePage);
    }

    void TMainPages_Ui::initSettingPage() {
        mSettingPage = new QWidget(mWin);
        mSettingPage->setObjectName("SettingPage");

        mSettingPageVLayout = new QVBoxLayout(mSettingPage);
        mSettingPageVLayout->setSpacing(5);
        mSettingPageVLayout->setObjectName("SettingPageVLayout");
        mSettingPageVLayout->setContentsMargins(5, 5, 5, 5);

        mSettingPageScrollArea = new QScrollArea(mSettingPage);
        mSettingPageScrollArea->setObjectName("ScrollArea");
        mSettingPageScrollArea->setStyleSheet("background: transparent;");
        mSettingPageScrollArea->setFrameShape(QFrame::NoFrame);
        mSettingPageScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mSettingPageScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mSettingPageScrollArea->setWidgetResizable(true);

        mSettingPageContent = new QWidget(mSettingPage);
        mSettingPageContent->setObjectName("SettingPageContent");
        mSettingPageContent->setGeometry(QRect(0, 0, 840, 580));
        mSettingPageContent->setStyleSheet("background: transparent;");

        mSettingPageContentVLayout = new QVBoxLayout(mSettingPageContent);
        mSettingPageContentVLayout->setSpacing(15);
        mSettingPageContentVLayout->setObjectName("SettingPageContentVLayout");
        mSettingPageContentVLayout->setContentsMargins(5, 5, 5, 5);

        mSettingPageContentTitleLabel = new QLabel(mSettingPageContent);
        mSettingPageContentTitleLabel->setObjectName("SettingPageContentTitleLabel");
        mSettingPageContentTitleLabel->setMaximumSize(QSize(16777215, 40));
        mSettingPageContentTitleLabel->setText("Custom Widgets Page");
        QFont font;
        font.setPointSize(16);
        mSettingPageContentTitleLabel->setFont(font);
        mSettingPageContentTitleLabel->setStyleSheet("font-size: 16pt");
        mSettingPageContentTitleLabel->setAlignment(Qt::AlignCenter);
        mSettingPageContentVLayout->addWidget(mSettingPageContentTitleLabel);

        mSettingPageContentDescLabel = new QLabel(mSettingPageContent);
        mSettingPageContentDescLabel->setObjectName("SettingPageContentDescLabel");
        mSettingPageContentDescLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        mSettingPageContentDescLabel->setWordWrap(true);
        mSettingPageContentDescLabel->setText("All widgets.");
        mSettingPageContentVLayout->addWidget(mSettingPageContentDescLabel);

        mRow1HLayout = new QHBoxLayout();
        mRow2HLayout = new QHBoxLayout();
        mRow3HLayout = new QHBoxLayout();
        mRow4HLayout = new QHBoxLayout();
        mRow5HLayout = new QHBoxLayout();
        mRow6HLayout = new QHBoxLayout();
        mSettingPageContentVLayout->addLayout(mRow1HLayout);
        mSettingPageContentVLayout->addLayout(mRow2HLayout);
        mSettingPageContentVLayout->addLayout(mRow3HLayout);
        mSettingPageContentVLayout->addLayout(mRow4HLayout);
        mSettingPageContentVLayout->addLayout(mRow5HLayout);
        mSettingPageContentVLayout->addLayout(mRow6HLayout);

        mSettingPageScrollArea->setWidget(mSettingPageContent);
        mSettingPageVLayout->addWidget(mSettingPageScrollArea);

        mPages->addWidget(mSettingPage);
    }

    void TMainPages_Ui::initVideoPage() {
        mVideoPage = new QWidget(mWin);
        mVideoPage->setObjectName("VideoPage");
        mVideoPage->setStyleSheet("QFrame { font-size: 16pt; }");

        mVideoPageHLayout = new QHBoxLayout(mVideoPage);
        mVideoPageHLayout->setObjectName("VideoPageHLayout");

        mVideoCtlBtnVLayout = new QVBoxLayout();
        mVideoPageHLayout->addLayout(mVideoCtlBtnVLayout);

        mVideoVLayout = new QVBoxLayout();
        mVideoPageHLayout->addLayout(mVideoVLayout);

        mVideoLabel = new QLabel(mVideoPage);
        mVideoVLayout->addWidget(mVideoLabel);

        mPages->addWidget(mVideoPage);
    }



};



