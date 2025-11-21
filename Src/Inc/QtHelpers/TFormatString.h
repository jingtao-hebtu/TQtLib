/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TFormatString.h
   Author : tao.jing
   Date   : 2024/5/26
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_QFORMATSTRING_H
#define QTONEDARK_QFORMATSTRING_H


#include <QDebug>
#include <map>
#include <iostream>
#include "TaoUtilDefine.h"


namespace T_QtBase {

    class TAO_UTIL_API TFormatString {

    public:
        // -- Constructors --

        TFormatString() : mFormatString("") {}

        TFormatString(const char *c_str) : mFormatString(c_str) {}

        TFormatString(QString qstr) : mFormatString(std::move(qstr)) {}

        TFormatString(const TFormatString &other) : mFormatString(other.mFormatString) {}

        TFormatString(TFormatString &&other) noexcept : mFormatString(std::move(other.mFormatString)) {}

        // -- operators --

        TFormatString& operator=(const char* cstr);

        TFormatString& operator=(const QString &qstr);

        TFormatString& operator=(const TFormatString &other);

        TFormatString& operator=(TFormatString &&other) noexcept;

        operator QString() const { return mFormatString; }

        operator const char*() const {
            mStdString = mFormatString.toStdString();
            return mStdString.c_str();
        }

        friend QDebug operator<<(QDebug dbg, const TFormatString & formatString) {
            dbg.nospace() << formatString.mFormatString;
            return dbg.space();
        }

        friend std::ostream& operator<<(std::ostream &os, const TFormatString &formatString) {
            os << formatString.mFormatString.toStdString();
            return os;
        }

        // -- Member Functions --

        [[nodiscard]] QString toQString() const;

        [[nodiscard]] std::string toStdString() const;

        [[nodiscard]] const char* toCString() const;

        [[nodiscard]] QString format(const std::map<std::string, std::string> &args) const;

        [[nodiscard]] QString format(const QMap<QString, QString> &args) const;

        [[nodiscard]] QString format(std::initializer_list<std::pair<QString, QString>> args) const;

    private:
        QString mFormatString;
        mutable std::string mStdString;
    };

}


#endif //QTONEDARK_QFORMATSTRING_H
