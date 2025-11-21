/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QLeftMenuTest.cpp
   Author : tao.jing
   Date   : 2024/6/19
   Brief  :
**************************************************************************/
#include <QApplication>
#include <QVBoxLayout>
#include <QHeaderView>
#include "TTitleBar.h"
#include "TDraggableWidget.h"
#include "TLog.h"


int main(int argc, char *argv[]) {

    TBase::initDateLog(argc, argv);

    QApplication a(argc, argv);

    // Dialog as container
    T_QtBase::TDraggableWidget main_w(nullptr);
    main_w.setFixedSize(800, 600);

    QHBoxLayout h_layout;
    main_w.setLayout(&h_layout);

    QVBoxLayout v_layout;
    h_layout.addLayout(&v_layout);

    T_QtBase::TTitleBar title_bar(&main_w, &main_w, {
            {"logo_width", "160"},
            {"radius",     "8"}
    });
    title_bar.addCustomizedButtons({
                                           {
                                                   {"name", "search"},
                                                   {"is_active", "false"},
                                                   {"obj_name", "btn_search"},
                                                   {"icon_path", ":Icons/Customized/png/Search.png"},
                                                   {"tooltip_text", "Search"},
                                           },
                                           {
                                                   {"name", "setting"},
                                                   {"is_active", "false"},
                                                   {"obj_name", "btn_setting"},
                                                   {"icon_path", ":Icons/Customized/png/Setting.png"},
                                                   {"tooltip_text", "Setting"},
                                           },
                                   });

    v_layout.addWidget(&title_bar, 0, Qt::AlignHCenter);
    main_w.show();

    return QApplication::exec();

}



