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
#include <QDialog>
#include <QFrame>
#include "TLeftMenu.h"
#include "TLog.h"


int main(int argc, char *argv[]) {

    TBase::initDateLog(argc, argv);

    QApplication a(argc, argv);

    QDialog main_w(nullptr);
    main_w.setFixedSize(600, 400);

    QHBoxLayout h_layout;
    main_w.setLayout(&h_layout);
    h_layout.setAlignment(Qt::AlignCenter);

    QFrame left_menu_frame(&main_w);
    int left_menu_content_margins = 3;
    int left_column_size_minimum = 50;
    int left_column_size_maximum = 240;
    left_menu_frame.setMaximumSize(left_column_size_minimum + (left_menu_content_margins * 2), 17280);
    left_menu_frame.setMinimumSize(left_column_size_minimum + (left_menu_content_margins * 2), 0);

    QHBoxLayout left_menu_layout(&left_menu_frame);
    left_menu_layout.setContentsMargins(
            left_menu_content_margins,
            left_menu_content_margins,
            left_menu_content_margins,
            left_menu_content_margins
    );

    T_QtBase::TLeftMenu left_menu(&left_menu_frame, &main_w, {

    });
    left_menu_layout.addWidget(&left_menu);
    left_menu.addCustomizedButtons({
                                           {
                                                   {"obj_name", "BtnHome"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Home.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Home.png"},
                                                   {"full_text", "Home"},
                                                   {"tooltip_text", "Home page"},
                                                   {"show_top", "true"},
                                                   {"is_active", "true"}
                                           },
                                           {
                                                   {"obj_name", "BtnWidgets"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Widgets.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Widgets.png"},
                                                   {"full_text", "Show Custom Widgets"},
                                                   {"tooltip_text", "Show Custom Widgets"},
                                                   {"show_top", "true"},
                                                   {"is_active", "false"}
                                           },
                                           {
                                                   {"obj_name", "BtnVideo"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Video.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Video.png"},
                                                   {"full_text", "Open video"},
                                                   {"tooltip_text", "Open video"},
                                                   {"show_top", "true"},
                                                   {"is_active", "false"}
                                           },
                                           {
                                                   {"obj_name", "BtnOpenFolder"},
                                                   {"icon_path", ":Icons/LeftMenu/png/OpenFolder.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/OpenFolder.png"},
                                                   {"full_text", "Open folder"},
                                                   {"tooltip_text", "Open folder"},
                                                   {"show_top", "true"},
                                                   {"is_active", "false"}
                                           },
                                           {
                                                   {"obj_name", "BtnSave"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Save.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Save.png"},
                                                   {"full_text", "Save"},
                                                   {"tooltip_text", "Save"},
                                                   {"show_top", "true"},
                                                   {"is_active", "false"}
                                           },
                                           {
                                                   {"obj_name", "BtnInfo"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Info.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Info.png"},
                                                   {"full_text", "Info"},
                                                   {"tooltip_text", "Info"},
                                                   {"show_top", "false"},
                                                   {"is_active", "false"}
                                           },
                                           {
                                                   {"obj_name", "BtnSettings"},
                                                   {"icon_path", ":Icons/LeftMenu/png/Settings.png"},
                                                   {"icon_path_active", ":Icons/LeftMenu/png/Settings.png"},
                                                   {"full_text", "Settings"},
                                                   {"tooltip_text", "Settings"},
                                                   {"show_top", "false"},
                                                   {"is_active", "false"}
                                           },
                                   });

    h_layout.addWidget(&left_menu_frame);
    main_w.show();

    return QApplication::exec();

}



