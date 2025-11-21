/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnBtnToolTip.h
   Author : tao.jing
   Date   : 2024/7/8
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTCOLUMNBTNTOOLTIP_H
#define QTONEDARK_TLEFTCOLUMNBTNTOOLTIP_H

#include "TToolTip.h"
#include "TaoUtilDefine.h"


class QGraphicsDropShadowEffect;


namespace T_QtBase {

    class TAO_UTIL_API TLeftColumnBtnToolTip : public TToolTip {

        Q_OBJECT

    public:
        explicit TLeftColumnBtnToolTip(QWidget *parent,
                                     std::initializer_list<std::pair<std::string, std::string>> args = {});
    private:
        QGraphicsDropShadowEffect *mShadow {nullptr};
    };

}

#endif //QTONEDARK_TLEFTCOLUMNBTNTOOLTIP_H
