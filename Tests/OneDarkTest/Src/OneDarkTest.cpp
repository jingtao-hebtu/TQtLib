/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : main.cpp
   Author : tao.jing
   Date   : 2024/5/27
   Brief  :
**************************************************************************/
#include <QApplication>
#include "TMainWindow.h"
#include "TOneDarkConfig.h"
#include <iostream>


int main(int argc, char *argv[]) {

    std::cout << "TOneDark." << std::endl;

    T_QtBase::TOneDarkConfig::instance().init("Tests/Configs");

    //QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    T_QtBase::TMainWindow w;
    w.show();

    return QApplication::exec();
}



