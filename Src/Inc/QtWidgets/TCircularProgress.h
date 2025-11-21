/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TCircularProgress.h
   Author : tao.jing
   Date   : 2024/5/29
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TCIRCULARPROGRESS_H
#define QTONEDARK_TCIRCULARPROGRESS_H

#include <QWidget>
#include "TFormatWid.h"
#include "TUiTypeParamHandler.h"


namespace T_QtBase {

    class TCircularProgress : public QWidget, public TFormatWid {

    Q_OBJECT

    public:

        TCircularProgress(QWidget *parent,
                          std::initializer_list<std::pair<std::string, std::string>> args = {});

    public:

        void setValue(int value);

    private:

        void init();

        void initParams();

    protected:

        void paintEvent(QPaintEvent *event) override;

    private:
        QColor mBgColor;
        QColor mTextColor;
        QColor mProgressColor;

        int mValue {0};
        int mMaxValue {100};

    };

}


#endif //QTONEDARK_TCIRCULARPROGRESS_H
