/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuBtnToolTip.h
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTMENUBTNTOOLTIP_H
#define QTONEDARK_TLEFTMENUBTNTOOLTIP_H

#include "TToolTip.h"
#include "TaoUtilDefine.h"


class QGraphicsDropShadowEffect;


namespace T_QtBase {

    class TAO_UTIL_API TLeftMenuBtnToolTip : public TToolTip {

    public:

        TLeftMenuBtnToolTip(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        QGraphicsDropShadowEffect *mShadow{nullptr};
    };

};



#endif //QTONEDARK_TLEFTMENUBTNTOOLTIP_H
