QT += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogs/addproduct.cpp \
    dialogs/askforprinter.cpp \
    dialogs/editcustomer.cpp \
    dialogs/editseller.cpp \
    dialogs/findproduct.cpp \
    dialogs/loadsupplierpricelist.cpp \
    dialogs/setlisttype.cpp \
    main.cpp \
    mainwindow.cpp \
    utils/barcodelabelprinter.cpp \
    utils/code128/code128.cpp \
    utils/code128/code128item.cpp \
    utils/comboboxitemdelegateforunit.cpp \
    utils/documentprinter.cpp \
    utils/pricelistparsertodb.cpp \
    utils/xmldocumentloader.cpp \
    widgets/cars.cpp \
    widgets/customers.cpp \
    widgets/info.cpp \
    widgets/lists.cpp \
    widgets/products.cpp \
    widgets/records.cpp \
    widgets/sellers.cpp

HEADERS += \
    dialogs/addproduct.h \
    dialogs/askforprinter.h \
    dialogs/editcustomer.h \
    dialogs/editseller.h \
    dialogs/findproduct.h \
    dialogs/loadsupplierpricelist.h \
    dialogs/setlisttype.h \
    global.h \
    mainwindow.h \
    utils/barcodelabelprinter.h \
    utils/code128/code128.h \
    utils/code128/code128item.h \
    utils/comboboxitemdelegateforunit.h \
    utils/documentprinter.h \
    utils/pricelistparsertodb.h \
    utils/xmldocumentloader.h \
    widgets/cars.h \
    widgets/customers.h \
    widgets/info.h \
    widgets/lists.h \
    widgets/products.h \
    widgets/records.h \
    widgets/sellers.h

FORMS += \
    dialogs/addproduct.ui \
    dialogs/askforprinter.ui \
    dialogs/editcustomer.ui \
    dialogs/editseller.ui \
    dialogs/findproduct.ui \
    dialogs/loadsupplierpricelist.ui \
    dialogs/setlisttype.ui \
    mainwindow.ui \
    widgets/cars.ui \
    widgets/customers.ui \
    widgets/info.ui \
    widgets/lists.ui \
    widgets/products.ui \
    widgets/records.ui \
    widgets/sellers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources/all.qrc
