/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TOneDarkConfig.cpp
   Author : tao.jing
   Date   : 2024/8/2
   Brief  :
**************************************************************************/
#include "TOneDarkConfig.h"
#include "TConfig.h"
#include "TSysUtils.h"
#include "TException.h"


namespace T_QtBase {

    void TOneDarkConfig::init(const std::string& base_dir) {
        mBaseDir = base_dir;
        initUiSettings();
        initThemeSettings();
    }

    void TOneDarkConfig::initUiSettings() {
        bool found = false;
        std::string file_path(mBaseDir + "/OneDark/settings.json");
        file_path = TBase::searchFileInParentDirs(file_path, found);
        if (!found) {
            TBASE_LOG_THROW_RUNTIME("Config file %s not found.", file_path.c_str());
        }
        TBase::TConfig::instance().addJsonConfigFile(file_path);
    }

    void TOneDarkConfig::initThemeSettings() {
        bool found = false;
        std::string file_path(mBaseDir + "/OneDark/theme.json");
        file_path = TBase::searchFileInParentDirs(file_path, found);
        if (!found) {
            TBASE_LOG_THROW_RUNTIME("Config file %s not found.", file_path.c_str());
        }
        TBase::TConfig::instance().addJsonConfigFile(file_path);
    }

};
