/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TQtHelpers.cpp
   Author : tao.jing
   Date   : 2024/9/1
   Brief  :
**************************************************************************/
#include "TQtHelpers.h"
#include <QList>


namespace T_QtBase {

    void T_QtBase::getPointsXYRange(const QList<QPointF> &points, float &x_min, float &x_max,
                                    float &y_min, float &y_max) {
        if (points.isEmpty()) {
            return;
        }

        x_min = std::numeric_limits<float>::max();
        x_max = std::numeric_limits<float>::lowest();
        y_min = std::numeric_limits<float>::max();
        y_max = std::numeric_limits<float>::lowest();

        for (const QPointF& point : points) {
            if (point.x() < x_min) {
                x_min = static_cast<float>(point.x());
            }
            if (point.x() > x_max) {
                x_max = static_cast<float>(point.x());
            }
            if (point.y() < y_min) {
                y_min = static_cast<float>(point.y());
            }
            if (point.y() > y_max) {
                y_max = static_cast<float>(point.y());
            }
        }
    }
};