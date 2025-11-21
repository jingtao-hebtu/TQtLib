/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TGrips.h
   Author : tao.jing
   Date   : 2024/6/21
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TGRIPS_H
#define QTONEDARK_TGRIPS_H

#include <QWidget>
#include "TGripWidgets.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    enum TGripType {
        TOP_LEFT = 0,
        TOP_RIGHT = 1,
        BOTTOM_LEFT = 2,
        BOTTOM_RIGHT = 3,
        TOP = 4,
        BOTTOM = 5,
        LEFT = 6,
        RIGHT = 7,
    };

    class TAO_UTIL_API TGrips : public QWidget {

    public:
        TGrips(QWidget *parent, TGripType position, bool is_transparent = true);

    protected:
        void resizeEvent(QResizeEvent *event) override;

    private:
        void initGrips(TGripType position);

    private:
        QWidget *mParent {nullptr};
        TGripWidgets *mWid {nullptr};

        bool mIsTransparent {true};
    };

};


#endif //QTONEDARK_TGRIPS_H
