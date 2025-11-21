/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TToggleBox.h
   Author : tao.jing
   Date   : 2024/5/30
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TTOGGLEBOX_H
#define QTONEDARK_TTOGGLEBOX_H


#include <QCheckBox>
#include "TFormatWid.h"
#include "TStrParamHandler.h"
#include "TaoUtilDefine.h"


class QPropertyAnimation;


namespace T_QtBase {

    class TAO_UTIL_API TToggleBox : public QCheckBox, public TFormatWid {

    Q_OBJECT

        Q_PROPERTY(int position READ position WRITE setPosition NOTIFY positionChanged)

    public:
        TToggleBox(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:

        void init();

    public:

        [[nodiscard]] int position() const { return mPosition; }

        void setPosition(int target_pos);

        [[nodiscard]] bool hitButton(const QPoint &pos) const override;

        void paintEvent(QPaintEvent *event) override;

    signals:

        void positionChanged(int);

    public slots:

        void setupAnimation(int value);

    private:
        QColor mBgColor;
        QColor mCircleColor;
        QColor mActiveColor;

        QPropertyAnimation *mAnimation{nullptr};

        int mPosition {3};
    };

}

#endif //QTONEDARK_TTOGGLEBOX_H
