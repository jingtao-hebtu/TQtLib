/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TTableWidget.cpp
   Author : tao.jing
   Date   : 2024/6/3
   Brief  :
**************************************************************************/
#include "TTableWidget.h"


namespace T_QtBase {

    static TFormatString TTableWidgetStyleString = R"(
        /* ////////////////////////////////////
        QTableWidget */
        QTableWidget {
            background-color: {bg_color};
            padding: 5px;
            border-radius: {radius}px;
            gridline-color: {grid_line_color};
            color: {color};
        }
        QTableWidget::item{
            border-color: none;
            padding-left: 5px;
            padding-right: 5px;
            gridline-color: rgb(44, 49, 60);
            border-bottom: 1px solid {bottom_line_color};
        }
        QTableWidget::item:selected{
            background-color: {selection_color};
        }
        QHeaderView::section{
            background-color: rgb(33, 37, 43);
            max-width: 30px;
            border: 1px solid rgb(44, 49, 58);
            border-style: none;
            border-bottom: 1px solid rgb(44, 49, 60);
            border-right: 1px solid rgb(44, 49, 60);
        }
        QTableWidget::horizontalHeader {
            background-color: rgb(33, 37, 43);
        }
        QTableWidget QTableCornerButton::section {
            border: none;
            background-color: {header_horizontal_color};
            padding: 3px;
            border-top-left-radius: {radius}px;
        }
        QHeaderView::section:horizontal
        {
            border: none;
            background-color: {header_horizontal_color};
            padding: 3px;
        }
        QHeaderView::section:vertical
        {
            border: none;
            background-color: {header_vertical_color};
            padding-left: 5px;
            padding-right: 5px;
            border-bottom: 1px solid {bottom_line_color};
            margin-bottom: 1px;
        }

        /* ////////////////////////////////////
        ScrollBars */
        QScrollBar:horizontal {
            border: none;
            background: {scroll_bar_bg_color};
            height: 8px;
            margin: 0px 21px 0 21px;
            border-radius: 0px;
        }
        QScrollBar::handle:horizontal {
            background: {context_color};
            min-width: 25px;
            border-radius: 4px
        }
        QScrollBar::add-line:horizontal {
            border: none;
            background: {scroll_bar_btn_color};
            width: 20px;
            border-top-right-radius: 4px;
            border-bottom-right-radius: 4px;
            subcontrol-position: right;
            subcontrol-origin: margin;
        }
        QScrollBar::sub-line:horizontal {
            border: none;
            background: {scroll_bar_btn_color};
            width: 20px;
            border-top-left-radius: 4px;
            border-bottom-left-radius: 4px;
            subcontrol-position: left;
            subcontrol-origin: margin;
        }
        QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal
        {
             background: none;
        }
        QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal
        {
             background: none;
        }
        QScrollBar:vertical {
            border: none;
            background: {scroll_bar_bg_color};
            width: 8px;
            margin: 21px 0 21px 0;
            border-radius: 0px;
        }
        QScrollBar::handle:vertical {
            background: {context_color};
            min-height: 25px;
            border-radius: 4px
        }
        QScrollBar::add-line:vertical {
             border: none;
            background: {scroll_bar_btn_color};
             height: 20px;
            border-bottom-left-radius: 4px;
            border-bottom-right-radius: 4px;
             subcontrol-position: bottom;
             subcontrol-origin: margin;
        }
        QScrollBar::sub-line:vertical {
            border: none;
            background: {scroll_bar_btn_color};
             height: 20px;
            border-top-left-radius: 4px;
            border-top-right-radius: 4px;
             subcontrol-position: top;
             subcontrol-origin: margin;
        }
        QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {
             background: none;
        }

        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
             background: none;
        }
    )";

    static std::map<std::string, std::string> TTableWidgetStyleDefaultParams{
            {"radius",                "8"},
            {"color",                 "#FFF"},
            {"bg_color",              "#444"},
            {"selection_color",       "#FFF"},
            {"header_horizontal_color",
                                      "#333"},
            {"header_vertical_color", "#444"},
            {"bottom_line_color",     "#555"},
            {"grid_line_color",       "#555"},
            {"scroll_bar_bg_color",   "#FFF"},
            {"scroll_bar_btn_color",  "#333"},
            {"context_color",         "#00ABE8"},
    };


    TTableWidget::TTableWidget(QWidget *parent, std::initializer_list<std::pair<std::string, std::string>> args)
            : QTableWidget(parent), TFormatWid(TTableWidgetStyleString, TTableWidgetStyleDefaultParams, args) {
        init();
    }

    void TTableWidget::init() {
        formatStyleString();
    }

}



