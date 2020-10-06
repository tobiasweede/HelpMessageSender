/*
 * Copyright 2015 Markus Prasser
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

#include "helpmessagewindow.h"
#include <QApplication>
#include <QDebug>
#include <exception>

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    try {
        std::string filename;
        if(std::filesystem::exists("./HelpMessageSender.json"))
            filename = "./HelpMessageSender.json";
        else if(std::filesystem::exists("/etc/HelpMessageSender/HelpMessageSender.json"))
            filename = "/etc/HelpMessageSender/HelpMessageSender.json";
        else
            throw std::runtime_error("No config not found");
        std::ifstream f(filename.c_str());
        pt::ptree root;
        if (f.good())
            pt::read_json(f, root);
        else
            throw std::runtime_error("Error reading config file" + filename);
        QString server_ip = QString::fromStdString(root.get<std::string>("server_ip",
                                                                         "No server_ip found / set in config!"));
        quint16 client_help_server_port = root.get<unsigned short>("client_help_server_port",
                                                                   0);
        // qDebug() << server_ip;
        // qDebug() << client_help_server_port;

        lcHelpMessageWindow w{ server_ip,
                    client_help_server_port };
        w.show();
        return a.exec();
    } catch(std::exception& e) {
        qDebug() << e.what();
        QMessageBox msgBox;
        msgBox.setText( QString::fromStdString(e.what()));
        msgBox.exec();
    }
}
