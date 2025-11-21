/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TWindow.h
   Author : tao.jing
   Date   : 2024/6/3
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TWINDOW_H
#define QTONEDARK_TWINDOW_H

#include <QFrame>
#include "TFormatWid.h"
#include "TaoUtilDefine.h"


class QBoxLayout;
class QGraphicsDropShadowEffect;

namespace T_QtBase {

    class TAO_UTIL_API TWindow : public QFrame, public TFormatWid {

    public:
        TWindow(QWidget* parent, std::initializer_list<std::pair<std::string, std::string>> args = {});

    public:
        void setStyle(std::initializer_list<std::pair<std::string, std::string>> args = {});

    private:
        void init();

    private:
        QGraphicsDropShadowEffect* mShadow {nullptr};
        QBoxLayout* mMainLayout {nullptr};
    };

}


#endif //QTONEDARK_TWINDOW_H
