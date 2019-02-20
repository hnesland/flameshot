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

#include "src/utils/filenamehandler.h"
#include "src/utils/confighandler.h"
#include "src/widgets/loadspinner.h"
#include "jottaclishare.h"
#include <QDir>
#include <QProcess>
#include <QPixmap>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

JottaCliShare::JottaCliShare(const QPixmap &p, QWidget *parent):
    QWidget(parent), m_pixmap(p)
{
    setWindowTitle(tr("Upload to Jotta"));

    m_spinner = new LoadSpinner(this);
    m_spinner->setColor(ConfigHandler().uiMainColorValue());
    m_spinner->start();

    m_infoLabel = new QLabel(tr("Uploading Image"));

    m_vLayout = new QVBoxLayout();
    setLayout(m_vLayout);
    m_vLayout->addWidget(m_spinner, 0, Qt::AlignHCenter);
    m_vLayout->addWidget(m_infoLabel);

    setAttribute(Qt::WA_DeleteOnClose);

    upload();
}

void JottaCliShare::upload() {
    if (!QFileInfo(m_tempFile).isReadable()) {
        m_tempFile = FileNameHandler().generateAbsolutePath(QDir::tempPath()) + ".png";
        bool ok = m_pixmap.save(m_tempFile);
        if (!ok) {
            QMessageBox::about(this, tr("Error"), tr("Unable to write in")
                               + QDir::tempPath());
            return;
        }
    }

    QString command = "jotta-cli archive \"" + m_tempFile + "\" --share --clipboard --nogui";
    QProcess::startDetached(command);
    close();
}

