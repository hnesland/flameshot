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

#include "jottalaunchertool.h"
#include "jottaclishare.h"

JottaLauncher::JottaLauncher(QObject *parent) : AbstractActionTool(parent) {

}

bool JottaLauncher::closeOnButtonPressed() const {
    return true;
}

QIcon JottaLauncher::icon(const QColor &background, bool inEditor) const {
    Q_UNUSED(inEditor);
    return QIcon(iconPath(background) + "open_with.svg");
}
QString JottaLauncher::name() const {
    return tr("Jotta Launcher");
}

QString JottaLauncher::nameID() {
    return QLatin1String("");
}

QString JottaLauncher::description() const {
    return tr("Upload with jotta-cli");
}

QWidget* JottaLauncher::widget() {
    return new JottaCliShare(capture);
}

CaptureTool* JottaLauncher::copy(QObject *parent) {
    return new JottaLauncher(parent);
}

void JottaLauncher::pressed(const CaptureContext &context) {
    capture = context.selectedScreenshotArea();
    emit requestAction(REQ_CAPTURE_DONE_OK);
    emit requestAction(REQ_ADD_EXTERNAL_WIDGETS);
}
