/********************************************************************************
** Form generated from reading UI file 'products.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTS_H
#define UI_PRODUCTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Products
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QPushButton *btn_load;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_find;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *Products)
    {
        if (Products->objectName().isEmpty())
            Products->setObjectName(QString::fromUtf8("Products"));
        Products->resize(981, 607);
        verticalLayout = new QVBoxLayout(Products);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_add = new QPushButton(Products);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_add->sizePolicy().hasHeightForWidth());
        btn_add->setSizePolicy(sizePolicy);
        btn_add->setMinimumSize(QSize(40, 35));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon);

        horizontalLayout_3->addWidget(btn_add);

        btn_del = new QPushButton(Products);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));
        btn_del->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_del->sizePolicy().hasHeightForWidth());
        btn_del->setSizePolicy(sizePolicy);
        btn_del->setMinimumSize(QSize(40, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon1);

        horizontalLayout_3->addWidget(btn_del);

        btn_load = new QPushButton(Products);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        sizePolicy.setHeightForWidth(btn_load->sizePolicy().hasHeightForWidth());
        btn_load->setSizePolicy(sizePolicy);
        btn_load->setMinimumSize(QSize(40, 35));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_load->setIcon(icon2);

        horizontalLayout_3->addWidget(btn_load);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_find = new QPushButton(Products);
        btn_find->setObjectName(QString::fromUtf8("btn_find"));
        QFont font;
        font.setFamily(QString::fromUtf8("Carlito"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        btn_find->setFont(font);

        horizontalLayout_3->addWidget(btn_find);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(Products);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font1;
        font1.setPointSize(16);
        tableView->setFont(font1);
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Products);

        QMetaObject::connectSlotsByName(Products);
    } // setupUi

    void retranslateUi(QWidget *Products)
    {
        Products->setWindowTitle(QCoreApplication::translate("Products", "Form", nullptr));
        btn_add->setText(QString());
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Products", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QString());
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Products", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_load->setText(QString());
#if QT_CONFIG(shortcut)
        btn_load->setShortcut(QCoreApplication::translate("Products", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_find->setText(QCoreApplication::translate("Products", "\320\227\320\275\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Products: public Ui_Products {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTS_H
