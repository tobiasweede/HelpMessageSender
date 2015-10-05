# HelpMessageSender

## Installation

First *HelpMessageSender* must be compiled using *Qt Creator*. Afterwards the created executable file can be placed anywhere. On *Linux* it is suggested to place it in */usr/local/bin*, on Windows it could be placed in *C://EcoLabLib*.

Afterwards the configuration file has to be placed in the appropriate directory for the system. On *Linux* this directory is */etc/xdg/Economic Laboratory/*. On Windows the file has to be placed at *C:\\EcoLabLib\\HelpMessageSender.conf*. Then the file should be edited according to the laboratory's setup. The configuration file is crucial for *HelpMessageSender*'s functionality. If it is missing, *HelpMessageSender* will not have the proper ip address and port to connect to *Labcontrol* and will therefore be useless.

*HelpMessageSender* will try to connect to the server running *Labcontrol*. If there exists a firewall on your system, then the port specified via the *server_port* should not be blocked. Also the ports which shall be used by the z-Leaves should not be blocked.

## Building and Running on Windows

Install a recent *MinGW* version of *Qt* on your computer. Afterwards open the project file of *HelpMessageSender* and build it in *Debug* mode (which is the default). *HelpMessageSender* should run just fine from *Qt Creator*. If you want to run it normally you will have to put the following files from the *Qt* installation directory (e.g. C:\Qt\Qt5.4.2\5.4\mingw491\_32\bin) into the same directory as the created executable:

icuin53.dll
icudt53.dll
icuuc53.dll
libgcc\_s\_dw2-1.dll
libstdc++-6.dll
libwinpthread-1.dll
Qt5Cored.dll
Qt5Guid.dll
Qt5Networkd.dll
Qt5Widgetsd.dll

The *d* at the end of the *Qt* dlls marks them as debug versions. If disk space and resources shall be saved, *HelpMessageSender* can be built in *Release* mode. In this case, use the *Qt* files without the attached *d* (e.g. *Qt5Core.dll* instead of *Qt5Cored.dll*).
