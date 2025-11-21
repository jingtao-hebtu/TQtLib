/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTitleBar.h
   Author : tao.jing
   Date   : 2024/6/8
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TTITLEBAR_H
#define QTONEDARK_TTITLEBAR_H

#include "TFormatWid.h"
#include "TDraggableWidget.h"
#include "TStrListParam.h"
#include "TaoUtilDefine.h"


class QLabel;
class QFrame;
class QSvgWidget;
class QHBoxLayout;
class QVBoxLayout;


namespace T_QtBase {

    class TDiv;
    class TIconButton;
    class TTitleButton;

    class TAO_UTIL_API TTitleBar : public TDraggableWidget, public TFormatWid {

    Q_OBJECT

    public:
        explicit TTitleBar(QWidget *parent,
                           QWidget *app_parent,
                           TBase::TStrListParam args={});

        void addCustomizedButtons(const std::vector<std::initializer_list<std::pair<std::string, std::string>>>& btn_args);

    signals:
        void btnClicked(QObject *sender_btn);

        void btnReleased(QObject *sender_btn);

        void deActiveAll();

        void maximizeRestore();

    public slots:
        void onMaximizeRestore();

        void onHandlerBtnClicked();

        void onHandlerBtnReleased();

        void onDeActiveAll();

    public:
        TTitleButton* getTitleBtnByObjName(const QString& obj_name);

    protected:
        bool eventFilter(QObject *watched, QEvent *event) override;

    private:
        void init(TBase::TStrListParam args={});

        void setupUi(TBase::TStrListParam args={});

        void initActions();

    private:
        TDraggableWidget *mParent {nullptr};
        QWidget *mAppParent {nullptr};

        //std::initializer_list<std::pair<std::string, std::string>> mInitArgs;
        TBase::TStrListParam mInitArgs;
        //std::vector<std::pair<std::string, std::string>> mInitArgs;

        // Ui
        QVBoxLayout *mTitleBarLayout {nullptr};
        QFrame *mBgFrame {nullptr};
        QHBoxLayout *mBgLayout {nullptr};

        TDiv *mLogoToLabelDiv {nullptr};
        TDiv *mLabelToCustomBtnDiv {nullptr};
        TDiv *mCustomBtnToSysBtnDiv {nullptr};

        QLabel *mTopLogo {nullptr};
        QVBoxLayout *mTopLogoLayout {nullptr};
        QSvgWidget *mLogoSvg {nullptr};

        // Title label
        QLabel *mTitleLabel {nullptr};

        // Customized buttons
        QHBoxLayout *mCustomBtnLayout {nullptr};
        QMap<QString, TTitleButton*> mCustomBtnMap;

        // System buttons
        QHBoxLayout *mSystemBtnLayout {nullptr};
        TIconButton *mMinimizeBtn {nullptr};
        TIconButton *mMaximizeBtn {nullptr};
        TIconButton *mCloseBtn {nullptr};
    };

};


#endif //QTONEDARK_TTITLEBAR_H
