// Copyright(c) 2017-2018 Alejandro Sirgo Rica & Contributors
//
// This file is part of Flameshot.
//
//     Flameshot is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     Flameshot is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with Flameshot.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "src/utils/desktopfileparse.h"
#include <QWidget>
#include <QMap>

class QVBoxLayout;
class LoadSpinner;
class QLabel;

class JottaCliShare: public QWidget {
    Q_OBJECT
public:
    explicit JottaCliShare(const QPixmap &p, QWidget *parent = nullptr);

private:
    QPixmap m_pixmap;
    QVBoxLayout *m_vLayout;
    QLabel *m_infoLabel;
    LoadSpinner *m_spinner;
    QString m_tempFile;

    void upload();
};
