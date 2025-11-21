/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLineEdit.h
   Author : tao.jing
   Date   : 2024/5/27
   Brief  : 
**************************************************************************/
#ifndef QTONEDARK_TLINEEDIT_H
#define QTONEDARK_TLINEEDIT_H

#include <QLineEdit>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TLineEdit : public QLineEdit, public TFormatWid {

    Q_OBJECT

    public:
        TLineEdit(QWidget *parent,
                  std::initializer_list<std::pair<std::string, std::string>> args={});

    private:
        void init();
    };

};


#endif //QTONEDARK_TLINEEDIT_H
