/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTitleButtonToolTip.h
   Author : tao.jing
   Date   : 2024/6/6
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TTITLEBUTTONTOOLTIP_H
#define QTONEDARK_TTITLEBUTTONTOOLTIP_H

#include "TToolTip.h"
#include "TaoUtilDefine.h"


class QGraphicsDropShadowEffect;


namespace T_QtBase {

    class TAO_UTIL_API TTitleButtonToolTip : public TToolTip {

    public:
        explicit TTitleButtonToolTip(QWidget *parent,
                                     std::initializer_list<std::pair<std::string, std::string>> args = {});
    private:
        QGraphicsDropShadowEffect *mShadow {nullptr};
    };

}


#endif //QTONEDARK_TTITLEBUTTONTOOLTIP_H
