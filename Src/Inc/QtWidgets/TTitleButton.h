/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTitleButton.h
   Author : tao.jing
   Date   : 2024/6/6
   Brief  : 
**************************************************************************/
#ifndef QTONEDARK_TTITLEBUTTON_H
#define QTONEDARK_TTITLEBUTTON_H

#include <QWidget>
#include "TIconButton.h"
#include "TFormatWid.h"
#include "TStrListParam.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TTitleButtonToolTip;

    class TAO_UTIL_API TTitleButton : public TIconButton {

    Q_OBJECT

    public:
        TTitleButton(QWidget *parent, QWidget *app_parent, bool active,
                TBase::TStrListParam args = {}, TBase::TStrListParam op_args = {});

    private:
        void moveToolTip() override;
    };

}

#endif //QTONEDARK_TTITLEBUTTON_H
