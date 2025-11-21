/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TUiTypeParamHandler.cpp
   Author : tao.jing
   Date   : 2024/5/31
   Brief  :
**************************************************************************/
#include "TUiTypeParamHandler.h"
#include <sstream>
#include "TException.h"


namespace T_QtBase {

    QString TUiTypeParamHandler::convertToQColorString(const std::string& param_name) {
        auto param = mParameters[param_name];

        if (param->getType() == typeid(int)) {
            int value_int = (*this)[param_name];
            std::ostringstream oss;
            oss << "#" << std::hex << std::uppercase << value_int;
            return oss.str().c_str();
        } else if (param->getType() == typeid(std::string)) {
            std::string value_str = (*this)[param_name];
            return value_str.c_str();
        } else {
            TBASE_LOG_THROW_RUNTIME("Invalid conversion, param name %s.", param_name.c_str());
        }
    }

    std::string TUiTypeParamHandler::getStdStringParam(const std::string &param_name) {
        auto param = mParameters[param_name];
        return param->getValueAsString();
    }

    QString TUiTypeParamHandler::getQStringParam(const std::string &param_name) {
        return getStdStringParam(param_name).c_str();
    }
}
