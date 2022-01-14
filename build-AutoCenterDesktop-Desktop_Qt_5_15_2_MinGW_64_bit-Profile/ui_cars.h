/********************************************************************************
** Form generated from reading UI file 'cars.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARS_H
#define UI_CARS_H

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

class Ui_Cars
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *Cars)
    {
        if (Cars->objectName().isEmpty())
            Cars->setObjectName(QString::fromUtf8("Cars"));
        Cars->resize(782, 592);
        verticalLayout = new QVBoxLayout(Cars);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_add = new QPushButton(Cars);
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

        horizontalLayout->addWidget(btn_add);

        btn_del = new QPushButton(Cars);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));
        btn_del->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_del->sizePolicy().hasHeightForWidth());
        btn_del->setSizePolicy(sizePolicy);
        btn_del->setMinimumSize(QSize(40, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon1);

        horizontalLayout->addWidget(btn_del);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(Cars);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Cars);

        QMetaObject::connectSlotsByName(Cars);
    } // setupUi

    void retranslateUi(QWidget *Cars)
    {
        Cars->setWindowTitle(QCoreApplication::translate("Cars", "Form", nullptr));
        btn_add->setText(QString());
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Cars", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QString());
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Cars", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class Cars: public Ui_Cars {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARS_H
