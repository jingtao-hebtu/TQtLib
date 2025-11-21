/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFormatWid.h
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TFORMATWID_H
#define QTONEDARK_TFORMATWID_H

#include "TFormatString.h"
#include "TStrParamHandler.h"
#include "TStrListParam.h"
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TFormatWid {

    public:
        /*
        TFormatWid(TFormatString style_string,
                   const std::map<std::string, std::string> &default_param_map,
                   std::initializer_list<std::pair<std::string, std::string>> args,
                   std::initializer_list<std::pair<std::string, std::string>> op_args = {});*/

        TFormatWid(TFormatString style_string,
                   TBase::TStrListParam default_param_map,
                   TBase::TStrListParam args,
                   TBase::TStrListParam op_args = {});

        virtual ~TFormatWid() = default;

    protected:
        void updateStyle(TFormatString style_string,
                         const std::map<std::string, std::string> &default_param_map,
                         std::initializer_list<std::pair<std::string, std::string>> args,
                         std::initializer_list<std::pair<std::string, std::string>> op_args = {});

        void formatStyleString();

        void mergeParams(std::initializer_list<std::pair<std::string, std::string>> args);

        template<typename T>
        T getParam(const std::string& name) const;

        template<typename T>
        void setParam(const std::string& name, const T& value);

    protected:
        TFormatString mStyleFString = R"()";
        TBase::TStrParamHandler mParamHandler;

    };
};

#endif //QTONEDARK_TFORMATWID_H
