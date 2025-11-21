/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TToolTip.h
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TTOOLTIP_H
#define QTONEDARK_TTOOLTIP_H

#include <QLabel>
#include "TFormatWid.h"


class QGraphicsDropShadowEffect;


namespace T_QtBase {

    class TToolTip : public QLabel, public TFormatWid {

        Q_OBJECT

    public:

        explicit TToolTip(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args = {});

        void updateText(QString text);

    protected:
        void init();

    private:
        QString mToolTipText{""};
        QGraphicsDropShadowEffect *mShadow{nullptr};
    };

};



#endif //QTONEDARK_TTOOLTIP_H
