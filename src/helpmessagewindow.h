/*
 * Copyright 2015-2016 Markus Prasser
 *
 * This file is part of HelpMessageSender.
 *
 *  HelpMessageSender is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  HelpMessageSender is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with HelpMessageSender.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HELPMESSAGEWINDOW_H
#define HELPMESSAGEWINDOW_H

#include "ui_helpmessagewindow.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QtNetwork>

namespace Ui {
class HelpMessageWindow;
}

class lcHelpMessageWindow final : public QMainWindow {
    Q_OBJECT

public:
    explicit lcHelpMessageWindow( const QString &argServerIP,
                                  const unsigned short int &argServerPort,
                                  QWidget *argParent = nullptr );
    ~lcHelpMessageWindow();

private:
    quint16 blockSize = 0;
    QTcpSocket *helpMessageSocket = nullptr;
    QNetworkSession *networkSession = nullptr;
    const quint16 serverPort = 0;
    const QHostAddress serverAddress;
    Ui::HelpMessageWindow *ui = nullptr;

private slots:
    void DisplayError( QAbstractSocket::SocketError socketError );
    void OpenedSession();
    void ReadHelpReply();
    void RequestHelp();
};

#endif // HELPMESSAGEWINDOW_H
