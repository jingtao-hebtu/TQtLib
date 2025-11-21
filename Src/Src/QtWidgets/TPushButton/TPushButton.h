/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TPushButton.h
   Author : tao.jing
   Date   : 2024/5/29
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TPUSHBUTTON_H
#define QTONEDARK_TPUSHBUTTON_H

#include <QPushButton>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TPushButton : public QPushButton, public TFormatWid {

    Q_OBJECT

    public:

        explicit TPushButton(QWidget *parent,
                             QString btn_text,
                             std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();

    private:
        QString mBtnText;
    };

}


#endif //QTONEDARK_TPUSHBUTTON_H
