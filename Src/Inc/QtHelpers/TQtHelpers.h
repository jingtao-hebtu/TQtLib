/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TQtHelpers.h
   Author : tao.jing
   Date   : 2024/9/1
   Brief  :
**************************************************************************/
#ifndef BREAKERAPP_TQTHELPERS_H
#define BREAKERAPP_TQTHELPERS_H


#include <QPointF>
#include "TaoUtilDefine.h"


namespace T_QtBase {

    void TAO_UTIL_API getPointsXYRange(const QList<QPointF> &points, float &x_min, float &x_max,
                          float &y_min, float &y_max);

};


#endif //BREAKERAPP_TQTHELPERS_H
