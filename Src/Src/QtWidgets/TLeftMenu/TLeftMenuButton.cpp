/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftMenuButton.cpp
   Author : tao.jing
   Date   : 2024/6/17
   Brief  :
**************************************************************************/
#include "TLeftMenuButton.h"
#include <QEvent>
#include <QSvgRenderer>
#include <QPainter>
#include <QMouseEvent>
#include <utility>
#include "TLeftMenuBtnToolTip.h"
#include "TException.h"


namespace T_QtBase {

    TLeftMenuButton::TLeftMenuButton(QWidget *parent, QWidget *app_parent,
                                     std::initializer_list<std::pair<std::string, std::string>> args,
                                     std::initializer_list<std::pair<std::string, std::string>> op_args)
            : QPushButton(parent), mParent(parent), mAppParent(app_parent),
              TFormatWid("", {
                      {"obj_name",                  ""},
                      {"full_text",                 ""},
                      {"is_active",                 "false"},
                      {"is_active_tab",             "false"},
                      {"is_toggle_active",          "false"},

                      {"margin",                    "4"},
                      {"width",                     "50"},

                      {"bg_color",                  "#1B1E23"},
                      {"bg_color_hover",            "#1B1E23"},
                      {"bg_color_pressed",          "#272C36"},
                      {"context_color",             "#568AF2"},
                      {"text_active",               "#DCE1EC"},

                      {"icon_path",                 ":Icons/Base/png/NoImg.png"},
                      {"icon_close_path",           ":Icons/Base/png/NoImg.png"},
                      {"icon_active_path",          ":Icons/Base/png/NoImg.png"},

                      {"icon_color",                "#C3CCDF"},
                      {"icon_color_hover",          "#DCE1EC"},
                      {"icon_color_pressed",        "#568AF2"},
                      {"icon_color_active",         "#F5F6F9"},

                      {"tooltip_text",              ""},
                      {"tooltip_text_active_color", "#DCE1EC"},
                      {"tooltip_bg_color",          "#1B1E23"},
                      {"tooltip_text_foreground",   "#8A95AA"},
              }, args, op_args) {
        init();
    }

    void TLeftMenuButton::init() {
        initParams();
        setupUi();
        formatStyleString();
    }

    void TLeftMenuButton::initParams() {
        mIsActive = getParam<bool>("is_active");
        mIsActiveTab = getParam<bool>("is_active_tab");
        mIsActiveToggle = getParam<bool>("is_toggle_active");

        mFullText = getParam<std::string>("full_text").c_str();

        mIconPath = getParam<std::string>("icon_path").c_str();
        mIconClosePath = getParam<std::string>("icon_close_path").c_str();
        mIconActivePath = getParam<std::string>("icon_active_path").c_str();

        mBgColors[T_WID_DEFAULT] = QColor(getParam<std::string>("bg_color").c_str());
        mBgColors[T_WID_HOVER] = QColor(getParam<std::string>("bg_color_hover").c_str());
        mBgColors[T_WID_PRESSED] = QColor(getParam<std::string>("bg_color_pressed").c_str());

        mIconColors[T_WID_DEFAULT] = QColor(getParam<std::string>("icon_color").c_str());
        mIconColors[T_WID_HOVER] = QColor(getParam<std::string>("icon_color_hover").c_str());
        mIconColors[T_WID_PRESSED] = QColor(getParam<std::string>("icon_color_pressed").c_str());
        mIconColors[T_WID_ACTIVE] = QColor(getParam<std::string>("icon_color_active").c_str());

        mCurBgColor = mBgColors[T_WID_DEFAULT];
        mCurIconColor = mIconColors[T_WID_DEFAULT];
    }

    void TLeftMenuButton::setupUi() {
        setText(mFullText);
        setCursor(Qt::PointingHandCursor);
        setMaximumHeight(getParam<int>("width"));
        setMinimumHeight(getParam<int>("width"));
        setObjectName(getParam<std::string>("obj_name"));

        mToolTip = new TLeftMenuBtnToolTip(mAppParent, {
                {"tooltip_text",            getParam<std::string>("tooltip_text")},
                {"tooltip_bg_color",        getParam<std::string>("tooltip_bg_color")},
                {"tooltip_text_foreground", getParam<std::string>("tooltip_text_foreground")},
                {"context_color",           getParam<std::string>("context_color")}
        });
        mToolTip->hide();

        loadIcon();
    }

    void TLeftMenuButton::changeStyle(const QEvent::Type &event) {
        switch (event) {
            case QEvent::Enter:
                if (mCurBgColor != mBgColors[T_WID_HOVER] &&
                    mCurIconColor != mIconColors[T_WID_HOVER]) {
                    mCurBgColor = mBgColors[T_WID_HOVER];
                    mCurIconColor = mIconColors[T_WID_HOVER];
                    repaint();
                }
                break;
            case QEvent::Leave:
                if (mCurBgColor != mBgColors[T_WID_DEFAULT] &&
                    mCurIconColor != mIconColors[T_WID_DEFAULT]) {
                    mCurBgColor = mBgColors[T_WID_DEFAULT];
                    mCurIconColor = mIconColors[T_WID_DEFAULT];
                    repaint();
                }
                break;
            case QEvent::MouseButtonPress:
                if (mCurBgColor != mBgColors[T_WID_PRESSED] &&
                    mCurIconColor != mIconColors[T_WID_PRESSED]) {
                    mCurBgColor = mBgColors[T_WID_PRESSED];
                    mCurIconColor = mIconColors[T_WID_PRESSED];
                    repaint();
                }
                break;
            case QEvent::MouseButtonRelease:
                if (mCurBgColor != mBgColors[T_WID_HOVER] &&
                    mCurIconColor != mIconColors[T_WID_HOVER]) {
                    mCurBgColor = mBgColors[T_WID_HOVER];
                    mCurIconColor = mIconColors[T_WID_HOVER];
                    repaint();
                }
                break;
            default:
                break;
        }
    }

    void TLeftMenuButton::setActive(bool is_active) {
        if (mIsActive == is_active) {
            return;
        }

        mIsActive = is_active;
        if (!mIsActive) {
            mCurBgColor = mBgColors[T_WID_HOVER];
            mCurIconColor = mIconColors[T_WID_DEFAULT];
        }
        repaint();
    }

    void TLeftMenuButton::setActiveTab(bool is_active) {
        if (mIsActiveTab == is_active) {
            return;
        }

        mIsActiveTab = is_active;
        if (!mIsActiveTab) {
            mCurBgColor = mBgColors[T_WID_HOVER];
            mCurIconColor = mIconColors[T_WID_DEFAULT];
        }
        repaint();
    }

    void TLeftMenuButton::setActiveToggle(bool is_active) {
        if (mIsActiveToggle == is_active) {
            return;
        }

        mIsActiveToggle = is_active;
    }

    void TLeftMenuButton::setIcon(QString icon_path) {
        mIconPath = std::move(icon_path);
        loadIcon();
        repaint();
    }

    void TLeftMenuButton::loadIcon() {
        if (mIconPath != "") {
            mIconPixmap = QPixmap(mIconPath);
            QPainter icon_painter(&mIconPixmap);
            icon_painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
            icon_painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
            icon_painter.fillRect(mIconPixmap.rect(), mIconColors[T_WID_DEFAULT]);
            icon_painter.end();
        }

        if (mIconClosePath != "") {
            mIconClosePixmap = QPixmap(mIconClosePath);
        }

        if (mIconActivePath != "") {
            mIconActivePixmap = QPixmap(mIconActivePath);
        }
    }

    void TLeftMenuButton::paintEvent(QPaintEvent *) {
        QPainter painter;
        painter.begin(this);
        painter.setRenderHint(QPainter::RenderHint::Antialiasing);
        painter.setPen(Qt::NoPen);
        painter.setFont(font());

        // Rectangles
        QRect rect_inside(4, 5, width() - 8, height() - 10);
        QRect rect_icon(0, 0, 50, height());
        QRect rect_blue(4, 5, 20, height() - 10);
        QRect rect_inside_active(7, 5, width(), height() - 10);
        QRect rect_text(45, 0, width() - 50, height());

        if (mIsActive) {
            // Draw BG
            painter.setBrush(QColor(getParam<std::string>("context_color").c_str()));
            painter.drawRoundedRect(rect_blue, 8, 8);
            // Draw BG inside
            painter.setBrush(mBgColors[T_WID_DEFAULT]);
            painter.drawRoundedRect(rect_inside_active, 8, 8);
            // Draw active
            paintIconActive(painter);
            // Draw text
            painter.setPen(QColor(getParam<std::string>("text_active").c_str()));
            painter.drawText(rect_text, Qt::AlignVCenter, text());
            // Draw icons
            paintIcon(painter, rect_icon, mCurIconColor);
        } else if (mIsActiveTab) {
            // Draw BG
            painter.setBrush(mBgColors[T_WID_PRESSED]);
            painter.drawRoundedRect(rect_blue, 8, 8);
            // Draw BG inside
            painter.setBrush(mBgColors[T_WID_DEFAULT]);
            painter.drawRoundedRect(rect_inside_active, 8, 8);
            // Draw active
            paintIconActive(painter);
            // Draw text
            painter.setPen(QColor(getParam<std::string>("text_active").c_str()));
            painter.drawText(rect_text, Qt::AlignVCenter, text());
            // Draw icons
            paintIcon(painter, rect_icon, mCurIconColor);
        } else {
            // Draw BG inside
            painter.setBrush(mCurBgColor);
            painter.drawRoundedRect(rect_inside, 8, 8);
            // Draw text
            painter.setPen(QColor(getParam<std::string>("tooltip_text_foreground").c_str()));
            painter.drawText(rect_text, Qt::AlignVCenter, text());

            if (mIsActiveToggle) {
                paintIconClose(painter, rect_icon, QColor(getParam<std::string>("context_color").c_str()));
            } else {
                paintIcon(painter, rect_icon, mCurIconColor);
            }
        }

        painter.end();
    }

    void TLeftMenuButton::paintIcon(QPainter &painter, QRect rect, QColor icon_color) {
        Q_UNUSED(icon_color);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.drawPixmap(
                (rect.width() - mIconPixmap.width()) / 2,
                (rect.height() - mIconPixmap.height()) / 2,
                mIconPixmap);
    }

    void TLeftMenuButton::paintIconClose(QPainter &painter, QRect rect, QColor icon_color) {
        Q_UNUSED(icon_color);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.drawPixmap(
                (rect.width() - mIconClosePixmap.width()) / 2,
                (rect.height() - mIconClosePixmap.height()) / 2,
                mIconClosePixmap);
    }

    void TLeftMenuButton::paintIconActive(QPainter &painter) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        painter.drawPixmap(width() - 5, 0, mIconActivePixmap);
    }

    void TLeftMenuButton::enterEvent(QEnterEvent *event) {
        Q_UNUSED(event);
        changeStyle(QEvent::Enter);
        if (width() == 50) {
            auto tooltip_text = getParam<std::string>("tooltip_text");
            if (!tooltip_text.empty()) {
                moveToolTip();
                mToolTip->show();
            }
        }
    }

    void TLeftMenuButton::leaveEvent(QEvent *event) {
        Q_UNUSED(event);
        changeStyle(QEvent::Leave);
        mToolTip->hide();
    }

    void TLeftMenuButton::mousePressEvent(QMouseEvent *e) {
        if (e->button() == Qt::LeftButton) {
            changeStyle(QEvent::MouseButtonPress);
            mToolTip->hide();
            emit clicked();
        }
    }

    void TLeftMenuButton::mouseReleaseEvent(QMouseEvent *e) {
        if (e->button() == Qt::LeftButton) {
            changeStyle(QEvent::MouseButtonRelease);
            emit released();
        }
    }

    void TLeftMenuButton::moveToolTip() {
        auto global_pos = mapToGlobal(QPoint(0, 0));
        auto pos = mAppParent->mapFromGlobal(global_pos);

        auto pos_x = pos.x() + width() + 5;
        auto pos_y = pos.y() + static_cast<int>((height() - mToolTip->height()) / 2);

        mToolTip->move(pos_x, pos_y);
    }


};


