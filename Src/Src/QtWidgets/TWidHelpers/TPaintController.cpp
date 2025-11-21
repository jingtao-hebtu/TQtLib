/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TPaintController.cpp
   Author : tao.jing
   Date   : 2024/8/24
   Brief  :
**************************************************************************/
#include "TPaintController.h"


namespace T_QtBase {


    bool TPaintController::needUpdate(std::initializer_list<std::pair<std::string, bool>> args) {
        if (mFirstUpdate) {
            for (const auto &arg : args) {
                mCondMap[arg.first.c_str()] = arg.second;
            }
            mFirstUpdate = false;
            return true;
        }

        bool need_update = false;
        for (const auto &arg : args) {
            if (mCondMap.contains(arg.first.c_str())) {
                if (mCondMap[arg.first.c_str()] != arg.second) {
                    need_update = true;
                    mCondMap[arg.first.c_str()] = arg.second;
                }
            } else {
                need_update = true;
                mCondMap[arg.first.c_str()] = arg.second;
            }
        }
        return need_update;
    }

};