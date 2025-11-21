/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTitleButton.cpp
   Author : tao.jing
   Date   : 2024/6/6
   Brief  :
**************************************************************************/
#include "TTitleButton.h"
#include "TToolTip.h"
#include <QWidget>


namespace T_QtBase {

    TTitleButton::TTitleButton(QWidget *parent, QWidget *app_parent, bool active,
                               TBase::TStrListParam args, TBase::TStrListParam op_args)
            : TIconButton(parent, app_parent, active, args, op_args) {

    }

    void TTitleButton::moveToolTip() {
        auto global_pos = mapToGlobal(QPoint(0, 0));
        auto pos = mAppParent->mapFromGlobal(global_pos);

        auto pos_x = pos.x() -
                     static_cast<int>((mToolTip->width() - width()) / 2.0);

        // Show tooltip below the button
        auto pos_y = pos.y() + height() + getParam<int>("top_margin");

        mToolTip->move(pos_x, pos_y);
    }

}