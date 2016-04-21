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

#include "helpmessagewindow.h"
#include <QApplication>

int main( int argc, char *argv[] ) {
    QApplication a{ argc, argv };

    QTranslator qtTranslator;
    qtTranslator.load( "://translations/hmc-" + QLocale::system().name(),
                       QLibraryInfo::location( QLibraryInfo::TranslationsPath ) );
    a.installTranslator( &qtTranslator );

#ifdef Q_OS_UNIX
    QSettings labSettings{ "Economic Laboratory", "HelpMessageSender" };
#endif
#ifdef Q_OS_WIN
    QSettings labSettings{ "C:\\EcoLabLib\\HelpMessageSender.conf",
                           QSettings::IniFormat, this };
#endif
    lcHelpMessageWindow w{ labSettings.value( "server_ip", "127.0.0.1" ).toString(),
                           static_cast<unsigned short int>(
                               labSettings.value( "client_help_server_port",
                                                  "0" ).toUInt() ) };
    w.show();

    return a.exec();
}
