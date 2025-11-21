/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnButton.cpp
   Author : tao.jing
   Date   : 2024/7/8
   Brief  :
**************************************************************************/
#include "TLeftColumnButton.h"
#include <QPainter>
#include "TToolTip.h"


namespace T_QtBase {

    static std::map<std::string, std::string> StyleDefaultParams{
            {"tooltip_text",       ""},
            {"tooltip_bg_color",   "#1B1E23"},

            {"bg_color",           "#343B48"},
            {"bg_color_hover",     "#3C4454"},
            {"bg_color_pressed",   "#2C313C"},

            {"icon_color",         "#C3CCDF"},
            {"icon_color_hover",   "#DCE1EC"},
            {"icon_color_pressed", "#EDF0F5"},
            {"icon_color_active",  "#F5F6F9"},

            {"text_foreground",    "#8A95AA"},
            {"context_color",      "#568AF2"},
    };

    TLeftColumnButton::TLeftColumnButton(QWidget *parent, QWidget *app_parent, bool active,
                                         std::initializer_list<std::pair<std::string, std::string>> args,
                                         std::initializer_list<std::pair<std::string, std::string>> op_args)
            : TIconButton(parent, app_parent, active, args, op_args) {
        updateStyle("", StyleDefaultParams, args);
    }

    void TLeftColumnButton::moveToolTip() {
        auto global_pos = mapToGlobal(QPoint(0, 0));
        auto pos = mParent->mapFromGlobal(global_pos);

        auto pos_x = (pos.x() - mToolTip->width()) + width() + 5;
        auto pos_y = pos.y() + getParam<int>("top_margin");

        mToolTip->move(pos_x, pos_y);
    }

    void TLeftColumnButton::iconPaint(QPainter &painter) {
        if (!mIconPixmap.isNull()) {
            QPainter icon_painter(&mIconPixmap);
            icon_painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
            icon_painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
            if (isActive()) {
                icon_painter.fillRect(mIconPixmap.rect(), QColor(getParam<std::string>("context_color").c_str()));
            } else {
                icon_painter.fillRect(mIconPixmap.rect(), QColor(getParam<std::string>("icon_color").c_str()));
            }
            painter.drawPixmap(
                    static_cast<int>((rect().width() - mIconPixmap.width()) / 2),
                    static_cast<int>((rect().height() - mIconPixmap.height()) / 2), mIconPixmap);
            icon_painter.end();
        }
    }

}
