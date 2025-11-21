/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTableWidget.h
   Author : tao.jing
   Date   : 2024/6/3
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TTABLEWIDGET_H
#define QTONEDARK_TTABLEWIDGET_H

#include <QTableWidget>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TTableWidget : public QTableWidget, public TFormatWid {

    public:
        TTableWidget(QWidget* parent, std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();

    };

}


#endif //QTONEDARK_TTABLEWIDGET_H
