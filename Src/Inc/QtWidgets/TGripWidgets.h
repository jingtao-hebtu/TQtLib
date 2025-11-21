/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TGripWidgets.h
   Author : tao.jing
   Date   : 2024/6/20
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TGRIPWIDGETS_H
#define QTONEDARK_TGRIPWIDGETS_H

#include <string>
#include "TaoUtilDefine.h"


class QFrame;
class QWidget;


namespace T_QtBase {

    class TAO_UTIL_API TGripWidgets {

    public:
        void setTopLeftGrip(QWidget *form);

        void setTopRightGrip(QWidget *form);

        void setBottomLeftGrip(QWidget *form);

        void setBottomRightGrip(QWidget *form);

        void setTopGrip(QWidget *form);

        void setBottomGrip(QWidget *form);

        void setLeftGrip(QWidget *form);

        void setRightGrip(QWidget *form);

        QFrame *topLeftGrip() { return mTopLeftGrip; };

        QFrame *topRightGrip() { return mTopRightGrip; };

        QFrame *bottomLeftGrip() { return mBottomLeftGrip; };

        QFrame *bottomRightGrip() { return mBottomRightGrip; };

        QFrame *topGrip() { return mTopGrip; };

        QFrame *bottomGrip() { return mBottomGrip; };

        QFrame *leftGrip() { return mLeftGrip; };

        QFrame *rightGrip() { return mRightGrip; };

    private:
        static void setCornerGrip(QFrame *&grip, QWidget *form, const std::string& obj_name);

    private:
        QFrame *mTopLeftGrip{nullptr};
        QFrame *mTopRightGrip{nullptr};
        QFrame *mBottomLeftGrip{nullptr};
        QFrame *mBottomRightGrip{nullptr};
        QFrame *mTopGrip{nullptr};
        QFrame *mBottomGrip{nullptr};
        QFrame *mLeftGrip{nullptr};
        QFrame *mRightGrip{nullptr};
    };

};


#endif //QTONEDARK_TGRIPWIDGETS_H
