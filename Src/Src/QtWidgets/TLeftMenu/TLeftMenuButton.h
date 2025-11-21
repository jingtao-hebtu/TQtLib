/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuButton.h
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTMENUBUTTON_H
#define QTONEDARK_TLEFTMENUBUTTON_H

#include <QPushButton>
#include <QEvent>
#include "TFormatWid.h"
#include "TQDefines.h"
#include "TPaintController.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TLeftMenuBtnToolTip;

    class TAO_UTIL_API TLeftMenuButton : public QPushButton, public TFormatWid {

    Q_OBJECT

    public:
        TLeftMenuButton(QWidget *parent, QWidget *app_parent,
                        std::initializer_list<std::pair<std::string, std::string>> args = {},
                        std::initializer_list<std::pair<std::string, std::string>> op_args = {});

    private:
        void init();

        void initParams();

        void setupUi();

        void changeStyle(const QEvent::Type &event);

        void loadIcon();

    public:
        void setActive(bool is_active);

        void setActiveTab(bool is_active);

        void setActiveToggle(bool is_active);

        bool isActive() {return mIsActive;}

        bool isActiveTab() {return mIsActiveTab;}

        void setIcon(QString icon_path);

        void paintIcon(QPainter& painter, QRect rect, QColor icon_color);

        void paintIconClose(QPainter &painter, QRect rect, QColor icon_color);

        void paintIconActive(QPainter& painter);

    protected:
        void paintEvent(QPaintEvent *) override;

        void enterEvent(QEnterEvent *event) override;

        void leaveEvent(QEvent *event) override;

        void mousePressEvent(QMouseEvent *e) override;

        void mouseReleaseEvent(QMouseEvent *e) override;

        void moveToolTip();

    private:
        QWidget *mParent{nullptr};
        QWidget *mAppParent{nullptr};

        TPaintController mPaintController;

        bool mIsActive {false};
        bool mIsActiveTab {false};
        bool mIsActiveToggle {false};

        TLeftMenuBtnToolTip *mToolTip{nullptr};

        QString mFullText;
        QString mIconPath;
        QString mIconClosePath;
        QString mIconActivePath;

        QColor mCurBgColor;
        QColor mCurIconColor;

        QColor mBgColors[T_WID_STATE_NUM] = {QColor(0, 0, 0)};
        QColor mIconColors[T_WID_STATE_NUM] = {QColor(0, 0, 0)};

        QPixmap mIconPixmap;
        QPixmap mIconActivePixmap;
        QPixmap mIconClosePixmap;

    };

};


#endif //QTONEDARK_TLEFTMENUBUTTON_H
