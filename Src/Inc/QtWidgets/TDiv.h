/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TDiv.h
   Author : tao.jing
   Date   : 2024/6/6
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TDIV_H
#define QTONEDARK_TDIV_H

#include <QWidget>
#include "TFormatWid.h"


class QFrame;
class QHBoxLayout;


namespace T_QtBase {

    class TDiv : public QWidget, public TFormatWid {

        Q_OBJECT

    public:
        explicit TDiv(QWidget *parent,
                      std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();

    private:
        QHBoxLayout *mMainLayout {nullptr};
        QFrame *mFrame {nullptr};

    };

}


#endif //QTONEDARK_TDIV_H
