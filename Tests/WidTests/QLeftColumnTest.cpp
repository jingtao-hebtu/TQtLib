/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QLeftColumnTest.cpp
   Author : tao.jing
   Date   : 2024/7/11
   Brief  : 
**************************************************************************/
#include <QApplication>
#include <QVBoxLayout>
#include <QHeaderView>
#include "TLeftColumn.h"
#include "TDraggableWidget.h"
#include "TLog.h"


int main(int argc, char *argv[]) {

    TBase::initDateLog(argc, argv);

    QApplication a(argc, argv);

    // Dialog as container
    T_QtBase::TDraggableWidget main_w(nullptr);
    main_w.setFixedSize(400, 300);

    QVBoxLayout v_layout;
    main_w.setLayout(&v_layout);

    QWidget central_wid(&main_w);
    central_wid.setFixedSize(380, 120);
    QVBoxLayout central_widget_layout(&central_wid);
    central_widget_layout.setContentsMargins(0,0,0,0);
    v_layout.addLayout(&central_widget_layout);

    T_QtBase::TLeftColumn left_column(
            &central_wid,
            &central_wid,
            {
                    {"text_title", "Settings Left Frame"},
                    {"text_title_size", "10"},
                    {"text_title_color", "#8A95AA"},

                    {"icon_path", ":Icons/Customized/png/Setting.png"},
                    {"icon_close_path", ":Icons/LeftColumn/png/Close.png"},

                    {"bg_color", "#3C4454"},
                    {"border_radius", "8"},

                    {"btn_color", "#3C4454"},
                    {"btn_color_hover", "#343B48"},
                    {"btn_color_pressed", "#2C313C"},

                    {"icon_color", "#C3CCDF"},
                    {"icon_color_hover", "#DCE1EC"},
                    {"icon_color_pressed", "#6C99F4"},
            }
    );

    central_widget_layout.addWidget(&left_column, 0, Qt::AlignHCenter);
    main_w.show();

    return QApplication::exec();

}
