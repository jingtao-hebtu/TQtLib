/**************************************************************************

           Copyright(C), tao.jing All rights reserved

 **************************************************************************
   File   : TLeftColumnIcon.h
   Author : tao.jing
   Date   : 2024/6/24
   Brief  :
**************************************************************************/
#ifndef QTONEDARK_TLEFTCOLUMNICON_H
#define QTONEDARK_TLEFTCOLUMNICON_H

#include <QWidget>
#include "TaoUtilDefine.h"

class QPixmap;
class QLabel;
class QVBoxLayout;


namespace T_QtBase {

    class TAO_UTIL_API TLeftColumnIcon : public QWidget {

        Q_OBJECT

    public:
        explicit TLeftColumnIcon(QWidget *parent, QString icon_path, QString icon_color);

        void setIcon(const QString& icon_path, const QString& icon_color = "");

    private:
        void init();

        void setupUi();

    private:
        QString mIconPath;
        QString mIconColor;

        QVBoxLayout *mVLayout {nullptr};
        QLabel *mIcon {nullptr};
        QPixmap mIconPixmap;
    };

};


#endif //QTONEDARK_TLEFTCOLUMNICON_H
