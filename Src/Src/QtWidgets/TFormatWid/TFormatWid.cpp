/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFormatWid.cpp
   Author : tao.jing
   Date   : 2024/6/2
   Brief  :
**************************************************************************/
#include "TFormatWid.h"
#include <QWidget>
#include <utility>
#include "TException.h"


namespace T_QtBase {

    /*
    TFormatWid::TFormatWid(T_QtBase::TFormatString style_string,
                           const std::map<std::string, std::string> &default_param_map,
                           std::initializer_list<std::pair<std::string, std::string>> args,
                           std::initializer_list<std::pair<std::string, std::string>> op_args)
            : mStyleFString(std::move(style_string)) {
        mParamHandler.merge(default_param_map);
        mParamHandler.merge(args);
        mParamHandler.merge(op_args);
    }*/

    TFormatWid::TFormatWid(TFormatString style_string,
                           TBase::TStrListParam default_param_map,
                           TBase::TStrListParam args,
                           TBase::TStrListParam op_args)
            : mStyleFString(std::move(style_string)) {
        mParamHandler.merge(default_param_map);
        mParamHandler.merge(args);
        mParamHandler.merge(op_args);
    }

    void TFormatWid::updateStyle(TFormatString style_string,
                                 const std::map<std::string, std::string> &default_param_map,
                                 std::initializer_list<std::pair<std::string, std::string>> args,
                                 std::initializer_list<std::pair<std::string, std::string>> op_args) {
        mStyleFString = std::move(style_string);
        mParamHandler.merge(default_param_map);
        mParamHandler.merge(args);
        mParamHandler.merge(op_args);
        formatStyleString();
    }

    void TFormatWid::formatStyleString() {
        auto style_string = mStyleFString.format(mParamHandler.getParams());

        auto wid = dynamic_cast<QWidget *>(this);
        if (wid) {
            wid->setStyleSheet(style_string);
        } else {
            TBASE_LOG_THROW_RUNTIME("Not a sub class of QWidget, failed to dynamic_cast.");
        }
    }

    void TFormatWid::mergeParams(std::initializer_list<std::pair<std::string, std::string>> args) {
        mParamHandler.merge(args);
    }

    template<typename T>
    T TFormatWid::getParam(const std::string &name) const {
        return mParamHandler.get<T>(name);
    }

    template bool TFormatWid::getParam(const std::string &name) const;

    template int TFormatWid::getParam(const std::string &name) const;

    template double TFormatWid::getParam(const std::string &name) const;

    template std::string TFormatWid::getParam(const std::string &name) const;

    template<typename T>
    void TFormatWid::setParam(const std::string &name, const T &value) {
        mParamHandler.set<T>(name, value);
    }

    template void TFormatWid::setParam(const std::string &name, const bool &value);

    template void TFormatWid::setParam(const std::string &name, const int &value);

    template void TFormatWid::setParam(const std::string &name, const double &value);

    template void TFormatWid::setParam(const std::string &name, const std::string &value);

};
