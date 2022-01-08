QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogs/setlisttype.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/customers.cpp \
    widgets/lists.cpp \
    widgets/records.cpp \
    widgets/sellers.cpp

HEADERS += \
    dialogs/setlisttype.h \
    global.h \
    mainwindow.h \
    widgets/customers.h \
    widgets/lists.h \
    widgets/records.h \
    widgets/sellers.h

FORMS += \
    dialogs/setlisttype.ui \
    mainwindow.ui \
    widgets/customers.ui \
    widgets/lists.ui \
    widgets/records.ui \
    widgets/sellers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources/all.qrc
