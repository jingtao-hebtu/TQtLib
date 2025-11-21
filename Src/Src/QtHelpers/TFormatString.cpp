/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QFormatString.cpp
   Author : tao.jing
   Date   : 2024/5/26
   Brief  :
**************************************************************************/
#include <QDebug>
#include "TFormatString.h"


namespace T_QtBase {

    TFormatString& TFormatString::operator=(const char* cstr) {
        mFormatString = cstr;
        return *this;
    }

    TFormatString& TFormatString::operator=(const QString &qstr) {
        mFormatString = qstr;
        return *this;
    }

    TFormatString& TFormatString::operator=(const TFormatString &other) {
        if (this != &other) {
            mFormatString = other.mFormatString;
        }
        return *this;
    }

    TFormatString& TFormatString::operator=(TFormatString &&other) noexcept {
        if (this != &other) {
            mFormatString = std::move(other.mFormatString);
        }
        return *this;
    }

    QString TFormatString::toQString() const {
        return mFormatString;
    }

    std::string TFormatString::toStdString() const {
        return mFormatString.toStdString();
    }

    const char *TFormatString::toCString() const {
        return mFormatString.toStdString().c_str();
    }

    QString TFormatString::format(const std::map<std::string, std::string> &args) const {
        QString result = mFormatString;
        for (const auto& entry : args) {
            result.replace("{" + QString(entry.first.c_str()) + "}", QString(entry.second.c_str()));
        }
        return result;
    }

    QString TFormatString::format(const QMap<QString, QString> &args) const {
        QString result = mFormatString;
        for (auto it = args.begin(); it != args.end(); ++it) {
            result.replace("{" + it.key() + "}", it.value());
        }
        return result;
    }

    QString TFormatString::format(std::initializer_list<std::pair<QString, QString>> args) const {
        QMap<QString, QString> argMap;
        for (const auto& arg : args) {
            argMap.insert(arg.first, arg.second);
        }
        return format(argMap);
    }



}
