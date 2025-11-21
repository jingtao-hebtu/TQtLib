/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TIconButton.h
   Author : tao.jing
   Date   : 2024/5/28
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TICONBUTTON_H
#define QTONEDARK_TICONBUTTON_H

#include <QPushButton>
#include <QEvent>
#include "TQDefines.h"
#include "TFormatString.h"
#include "TFormatWid.h"
#include "TStrListParam.h"
#include "TaoUtilDefine.h"


class QGraphicsDropShadowEffect;


namespace T_QtBase {

    class TToolTip;

    class TAO_UTIL_API TIconButton : public QPushButton, public TFormatWid {

    Q_OBJECT

    public:
        TIconButton(QWidget *parent, QWidget *app_parent, bool active,
                    TBase::TStrListParam args = {},
                    TBase::TStrListParam op_args = {});

    public:
        [[nodiscard]] bool isActive() const {return mActive;}
        void setActive(bool active);

        void setIcon(QString icon_path);

    protected:
        void paintEvent(QPaintEvent *event) override;

        void enterEvent(QEnterEvent *event) override;

        void leaveEvent(QEvent *event) override;

        void mousePressEvent(QMouseEvent *e) override;

        void mouseReleaseEvent(QMouseEvent *e) override;

        virtual void loadIcon();

        virtual void moveToolTip();

        virtual void iconPaint(QPainter &painter);

    private:
        void init();

        void initParams();

        void initUi();

        void changeStyle(const QEvent::Type& event);

    protected:
        QWidget *mParent{nullptr};
        QWidget *mAppParent{nullptr};

        TToolTip *mToolTip {nullptr};

        QPixmap mIconPixmap;

    private:
        QString mObjName;
        QString mIconPath;

        bool mActive {false};

        QColor mBgColors[T_WID_STATE_NUM] = {QColor(0, 0, 0)};
        QColor mIconColors[T_WID_STATE_NUM] = {QColor(0, 0, 0)};

        QColor mContextColor;
        QColor mCurBgColor;
        QColor mCurIconColor;
    };

}


#endif //QTONEDARK_TICONBUTTON_H
