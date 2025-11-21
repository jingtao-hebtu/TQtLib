/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnButton.h
   Author : tao.jing
   Date   : 2024/7/8
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTCOLUMNBUTTON_H
#define QTONEDARK_TLEFTCOLUMNBUTTON_H

#include "TIconButton.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TLeftColumnButton : public TIconButton {

        Q_OBJECT

    public:
        TLeftColumnButton(QWidget *parent, QWidget *app_parent, bool active,
                std::initializer_list<std::pair<std::string, std::string>> args = {},
                std::initializer_list<std::pair<std::string, std::string>> op_args = {});

    protected:
        void moveToolTip() override;

        void iconPaint(QPainter &painter) override;
    };

};



#endif //QTONEDARK_TLEFTCOLUMNBUTTON_H
