/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TSlider.h
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TSLIDER_H
#define QTONEDARK_TSLIDER_H

#include <QSlider>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TSlider : public QSlider, public TFormatWid {

    Q_OBJECT

    public:
        TSlider(QWidget *parent,
                std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();
    };

};


#endif //QTONEDARK_TSLIDER_H
