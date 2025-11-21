/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TCreditsBar.h
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TCREDITSBAR_H
#define QTONEDARK_TCREDITSBAR_H

#include <QWidget>
#include "TFormatWid.h"
#include "TStrParamHandler.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TCreditsBar : public QWidget, public TFormatWid {

    Q_OBJECT

    public:

        explicit TCreditsBar(QWidget *parent,
                             std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:

        void init();

        void setupUi();

    };
}


#endif //QTONEDARK_TCREDITSBAR_H
