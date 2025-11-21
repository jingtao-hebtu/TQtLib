/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TIconButton.cpp
   Author : tao.jing
   Date   : 2024/5/28
   Brief  :
**************************************************************************/
#include "TIconButton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QSvgRenderer>
#include <QMap>
#include <utility>
#include "TToolTip.h"
#include "TLog.h"


namespace T_QtBase {

    TIconButton::TIconButton(QWidget *parent, QWidget *app_parent, bool active,
                             TBase::TStrListParam args,
                             TBase::TStrListParam op_args)
            : QPushButton(parent), mParent(parent), mAppParent(app_parent), mActive(active),
              TFormatWid("", {
                      {"obj_name",                ""},

                      {"tooltip_text",            ""},
                      {"tooltip_bg_color",        "#1B1E23"},
                      {"tooltip_text_foreground", "#8A95AA"},

                      {"width",                   "50"},
                      {"height",                  "30"},
                      {"radius",                  "8"},
                      {"top_margin",              "40"},

                      {"bg_color",                "#343B48"},
                      {"bg_color_hover",          "#3C4454"},
                      {"bg_color_pressed",        "#2C313C"},
                      {"icon_color",              "#C3CCDF"},
                      {"icon_color_hover",        "#DCE1EC"},
                      {"icon_color_pressed",      "#EDF0F5"},
                      {"icon_color_active",       "#F5F6F9"},
                      {"context_color",           "#568AF2"}
              }, args, op_args) {
        init();
    }

    void TIconButton::init() {
        initParams();
        initUi();
    }

    void TIconButton::initParams() {
        mBgColors[T_WID_DEFAULT] = QColor(getParam<std::string>("bg_color").c_str());
        mBgColors[T_WID_HOVER] = QColor(getParam<std::string>("bg_color_hover").c_str());
        mBgColors[T_WID_PRESSED] = QColor(getParam<std::string>("bg_color_pressed").c_str());

        mIconColors[T_WID_DEFAULT] = QColor(getParam<std::string>("icon_color").c_str());
        mIconColors[T_WID_HOVER] = QColor(getParam<std::string>("icon_color_hover").c_str());
        mIconColors[T_WID_PRESSED] = QColor(getParam<std::string>("icon_color_pressed").c_str());
        mIconColors[T_WID_ACTIVE] = QColor(getParam<std::string>("icon_color_active").c_str());

        mContextColor = QColor(getParam<std::string>("context_color").c_str());
        mCurBgColor = mBgColors[T_WID_DEFAULT];
        mCurIconColor = mIconColors[T_WID_DEFAULT];

        mIconPath = QString(getParam<std::string>("icon_path").c_str());
        mObjName = QString(getParam<std::string>("obj_name").c_str());
    }

    void TIconButton::initUi() {
        setFixedSize(QSize(getParam<int>("width"), getParam<int>("height")));
        setCursor(Qt::PointingHandCursor);
        setObjectName(mObjName);

        mToolTip = new TToolTip(mAppParent, {
                {"tooltip_text",            getParam<std::string>("tooltip_text")},
                {"tooltip_bg_color",        getParam<std::string>("tooltip_bg_color")},
                {"tooltip_text_foreground", getParam<std::string>("tooltip_text_foreground")}
        });
        mToolTip->hide();

        loadIcon();
    }

    void TIconButton::setActive(bool active) {
        mActive = active;
        repaint();
    }

    void TIconButton::paintEvent(QPaintEvent *event) {
        Q_UNUSED(event);

        QPainter painter;
        painter.begin(this);
        painter.setRenderHint(QPainter::RenderHint::Antialiasing);

        QColor brush_color;
        if (mActive) {
            brush_color = mContextColor;
        } else {
            brush_color = mCurBgColor;
        }

        QBrush brush(brush_color);
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        painter.drawRoundedRect(rect(),
                                getParam<int>("radius"), getParam<int>("radius"));
        iconPaint(painter);
        painter.end();
    }

    void TIconButton::changeStyle(const QEvent::Type &event) {
        switch (event) {
            case QEvent::Enter:
                mCurBgColor = mBgColors[T_WID_HOVER];
                mCurIconColor = mIconColors[T_WID_HOVER];
                repaint();
                break;
            case QEvent::Leave:
                mCurBgColor = mBgColors[T_WID_DEFAULT];
                mCurIconColor = mIconColors[T_WID_DEFAULT];
                repaint();
                break;
            case QEvent::MouseButtonPress:
                mCurBgColor = mBgColors[T_WID_PRESSED];
                mCurIconColor = mIconColors[T_WID_PRESSED];
                repaint();
                break;
            case QEvent::MouseButtonRelease:
                mCurBgColor = mBgColors[T_WID_HOVER];
                mCurIconColor = mIconColors[T_WID_HOVER];
                repaint();
                break;
            default:
                break;
        }
    }

    void TIconButton::enterEvent(QEnterEvent *event) {
        Q_UNUSED(event);
        changeStyle(QEvent::Enter);
        moveToolTip();
        mToolTip->show();
    }

    void TIconButton::leaveEvent(QEvent *event) {
        Q_UNUSED(event);
        changeStyle(QEvent::Leave);
        moveToolTip();
        mToolTip->hide();
    }

    void TIconButton::mousePressEvent(QMouseEvent *e) {
        if (e->button() == Qt::LeftButton) {
            changeStyle(QEvent::MouseButtonPress);
            setFocus();
            emit clicked();
        }
    }

    void TIconButton::mouseReleaseEvent(QMouseEvent *e) {
        if (e->button() == Qt::LeftButton) {
            changeStyle(QEvent::MouseButtonRelease);
            emit released();
        }
    }

    void TIconButton::setIcon(QString icon_path) {
        if (mIconPath == icon_path) {
            return;
        }
        mIconPath = std::move(icon_path);
        loadIcon();
        repaint();
    }

    void TIconButton::loadIcon() {
        if (mIconPath == "") {
            return;
        }

        mIconPixmap = QPixmap(mIconPath);
        QPainter icon_painter(&mIconPixmap);
        icon_painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        icon_painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        icon_painter.fillRect(mIconPixmap.rect(), mCurIconColor);
        icon_painter.end();
    }

    void TIconButton::moveToolTip() {
        auto global_pos = mapToGlobal(QPoint(0, 0));
        auto pos = mParent->mapFromGlobal(global_pos);

        auto pos_x = (pos.x() - static_cast<int>(mToolTip->width() / 2)) + static_cast<int>((width() / 2));
        auto pos_y = pos.y() - getParam<int>("top_margin");

        mToolTip->move(pos_x, pos_y);
    }

    void TIconButton::iconPaint(QPainter &painter) {
        if (!mIconPixmap.isNull()) {
            painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
            painter.drawPixmap(
                    static_cast<int>((rect().width() - mIconPixmap.width()) / 2),
                    static_cast<int>((rect().height() - mIconPixmap.height()) / 2), mIconPixmap);
        }
    }


}
