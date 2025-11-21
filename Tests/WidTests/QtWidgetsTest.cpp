/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : QtWidgetsTest.cpp
   Author : tao.jing
   Date   : 2024/5/27
   Brief  :
**************************************************************************/
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QHeaderView>
#include "TLineEdit.h"
#include "TIconButton.h"
#include "TPushButton.h"
#include "TToggleBox.h"
#include "TCircularProgress.h"
#include "TCreditsBar.h"
#include "TSlider.h"
#include "TTableWidget.h"
#include "TWindow.h"
#include "TTitleBar.h"
#include "TDraggableWidget.h"
#include "TLeftMenu.h"
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

    T_QtBase::TSlider slider(&main_w, {
            {"margin",               "8"},
            {"bg_size",              "10"},
            {"bg_radius",            "5"},
            {"handle_margin",        "-3"},
            {"handle_size",          "16"},
            {"handle_radius",        "8"},
            {"bg_color",             "#3c4454"},
            {"bg_color_hover",       "#272c36"},
            {"handle_color",         "#568af2"},
            {"handle_color_hover",   "#6c99f4"},
            {"handle_color_pressed", "#3f6fd1"},
    });
    slider.setMinimumHeight(100);
    h_layout.addWidget(&slider);

    T_QtBase::TLineEdit line_edit(&main_w, {{"color", "#0FF"}});
    T_QtBase::TIconButton icon_btn(&main_w, &main_w, false, {
            {"obj_name",           "icon_btn"},
            {"width",              "30"},
            {"height",             "30"},
            {"radius",             "8"},
            {"tooltip_text",       "IconButton2"},
            {"icon_path",          "D:/icon_heart.svg"},
            {"icon_color",         "#C3CCDF"},
            {"icon_color_hover",   "#DCE1EC"},
            {"icon_color_pressed", "#6C99F4"},
            {"icon_color_active",  "#F5F6F9"},
            {"bg_color",           "#2C313C"},
            {"bg_color_hover",     "#3C4454"},
            {"bg_color_pressed",   "#FF007F"},
    });

    T_QtBase::TPushButton push_btn(&main_w, "PushButton");
    push_btn.setMinimumWidth(120);
    push_btn.setMinimumHeight(40);

    T_QtBase::TToggleBox toggle_box(&main_w, {
            {"bg_color",     "#777"},
            {"circle_color", "#DDD"},
            {"active_color", "#00BCFF"},
            {"width",        "50"}
    });

    /*
    T_QtBase::TCircularProgress cp(&main_w, {
            {"bg_color", "#272C36"}, {"text_color", "#222222"},
            {"progress_color", "#568AF2"},
            {"value", "80"}, {"font_size", "14"}
    });
    cp.setFixedSize(200,200);*/

    T_QtBase::TCreditsBar cb(&main_w, {
            {"radius",    "12"},
            {"font_size", "12"},
    });

    T_QtBase::TTableWidget tw(&main_w);
    tw.setColumnCount(3);
    tw.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tw.setSelectionMode(QAbstractItemView::ExtendedSelection);
    tw.setSelectionBehavior(QAbstractItemView::SelectRows);
    tw.setMinimumHeight(100);

    /*
    T_QtBase::TWindow t_window(&main_w, {
            {"layout_type", "horizontal"}
    });
    */

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

    QFrame left_menu_frame(&main_w);
    int left_menu_content_margins = 3;
    int left_column_size_minimum = 50;
    //int left_column_size_maximum = 240;
    left_menu_frame.setMaximumSize(left_column_size_minimum + (left_menu_content_margins * 2), 17280);
    left_menu_frame.setMinimumSize(left_column_size_minimum + (left_menu_content_margins * 2), 60);

    QHBoxLayout left_menu_layout(&left_menu_frame);
    left_menu_layout.setContentsMargins(
            left_menu_content_margins,
            left_menu_content_margins,
            left_menu_content_margins,
            left_menu_content_margins
    );

    T_QtBase::TLeftMenu left_menu(&left_menu_frame, &main_w, {

    });

    v_layout.addWidget(&title_bar, 0, Qt::AlignHCenter);
    v_layout.addWidget(&line_edit, 0, Qt::AlignHCenter);
    v_layout.addWidget(&icon_btn, 0, Qt::AlignHCenter);
    v_layout.addWidget(&push_btn, 0, Qt::AlignHCenter);
    v_layout.addWidget(&toggle_box, 0, Qt::AlignHCenter);
    //v_layout.addWidget(&cp, 0, Qt::AlignHCenter);
    v_layout.addWidget(&cb, 0, Qt::AlignHCenter);
    v_layout.addWidget(&tw, 0, Qt::AlignHCenter);

    //h_layout.addWidget(&t_window, 0, Qt::AlignVCenter);
    h_layout.addWidget(&left_menu_frame);

    main_w.show();

    return QApplication::exec();

}



