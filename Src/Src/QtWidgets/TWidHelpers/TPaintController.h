/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TPaintController.h
   Author : tao.jing
   Date   : 2024/8/24
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TPAINTCONTROLLER_H
#define QTONEDARK_TPAINTCONTROLLER_H

#include <QMap>


namespace T_QtBase {

    class TPaintController {

    public:
        TPaintController() = default;

        bool needUpdate(std::initializer_list<std::pair<std::string, bool> > args);

    private:
        bool mFirstUpdate {true};
        QMap<QString, bool> mCondMap;

    };

};

#endif //QTONEDARK_TPAINTCONTROLLER_H
