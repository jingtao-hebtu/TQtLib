/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TUiTypeParamHandler.h
   Author : tao.jing
   Date   : 2024/5/31
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TUITYPEPARAMHANDLER_H
#define QTONEDARK_TUITYPEPARAMHANDLER_H

#include "TTypeParamHandler.h"
#include <QString>
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TUiTypeParamHandler : public TBase::TTypeParamHandler {

    public:

        using TBase::TTypeParamHandler::TTypeParamHandler;

        QString convertToQColorString(const std::string& param_name);

        std::string getStdStringParam(const std::string& param_name);

        QString getQStringParam(const std::string& param_name);

    };

}


#endif //QTONEDARK_TUITYPEPARAMHANDLER_H
