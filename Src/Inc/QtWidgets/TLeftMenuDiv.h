/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuDiv.h
   Author : tao.jing
   Date   : 2024/6/15
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTMENUDIV_H
#define QTONEDARK_TLEFTMENUDIV_H

#include <QWidget>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


class QFrame;
class QHBoxLayout;


namespace T_QtBase {

    class TAO_UTIL_API TLeftMenuDiv : public QWidget, public TFormatWid {

    public:
        explicit TLeftMenuDiv(QWidget *parent,
                      std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();

    private:
        QHBoxLayout *mMainLayout {nullptr};
        QFrame *mFrame {nullptr};

    };

}


#endif //QTONEDARK_TLEFTMENUDIV_H
