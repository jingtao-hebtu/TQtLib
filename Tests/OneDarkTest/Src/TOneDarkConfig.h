/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TOneDarkConfig.h
   Author : tao.jing
   Date   : 2024/8/2
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TONEDARKCONFIG_H
#define QTONEDARK_TONEDARKCONFIG_H

#include "TSingleton.h"
#include <string>


namespace T_QtBase {

    class TOneDarkConfig : public TBase::TSingleton<TOneDarkConfig> {

    public:
        void init(const std::string& base_dir = "Configs");

    private:
        void initUiSettings();
        void initThemeSettings();

    private:
        std::string mBaseDir {"Tests/Configs"};

    };

};

#endif //QTONEDARK_TONEDARKCONFIG_H
