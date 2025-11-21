/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QtHelpersTest.cpp
   Author : tao.jing
   Date   : 2024/5/27
   Brief  : 
**************************************************************************/
#include <iostream>
#include <QDebug>
#include "TFormatString.h"


int main(int argc, char *argv[]) {
    (void)(argc);
    (void)(argv);

    T_QtBase::TFormatString f_string = "Hello, {name}! Welcome to {place}.";

    // QMap formatting
    QMap<QString, QString> params;
    params["name"] = "Alice";
    params["place"] = "Wonderland";
    QString result1 = f_string.format(params);
    qDebug() << result1;  // Output: "Hello, Alice! Welcome to Wonderland."

    // variable parameter list
    QString result2 = f_string.format({{"name", "Bob"}, {"place", "Narnia"}});
    qDebug() << result2;  // Output: "Hello, Bob! Welcome to Narnia."

    // Conversion to QString and const char *
    QString qstr = f_string;
    qDebug() << qstr;  // Output: "Hello, {name}! Welcome to {place}."
    const char* cstr = f_string;
    qDebug() << cstr;  // Output: "Hello, {name}! Welcome to {place}."

    // std::ostream output
    std::cout << f_string << std::endl;  // Output: "Hello, {name}! Welcome to {place}."
    std::cout << result2.toStdString() << std::endl;  // Output: "Hello, Bob! Welcome to Narnia."

    return 0;

}