/********************************************************************************
** Form generated from reading UI file 'customers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERS_H
#define UI_CUSTOMERS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Customers
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QPushButton *btn_info;
    QPushButton *btn_cars;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *Customers)
    {
        if (Customers->objectName().isEmpty())
            Customers->setObjectName(QString::fromUtf8("Customers"));
        Customers->resize(782, 592);
        verticalLayout = new QVBoxLayout(Customers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_add = new QPushButton(Customers);
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

        btn_del = new QPushButton(Customers);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));
        btn_del->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_del->sizePolicy().hasHeightForWidth());
        btn_del->setSizePolicy(sizePolicy);
        btn_del->setMinimumSize(QSize(40, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon1);

        horizontalLayout->addWidget(btn_del);

        btn_info = new QPushButton(Customers);
        btn_info->setObjectName(QString::fromUtf8("btn_info"));
        btn_info->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_info->sizePolicy().hasHeightForWidth());
        btn_info->setSizePolicy(sizePolicy);
        btn_info->setMinimumSize(QSize(40, 35));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_info->setIcon(icon2);

        horizontalLayout->addWidget(btn_info);

        btn_cars = new QPushButton(Customers);
        btn_cars->setObjectName(QString::fromUtf8("btn_cars"));
        btn_cars->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_cars->sizePolicy().hasHeightForWidth());
        btn_cars->setSizePolicy(sizePolicy);
        btn_cars->setMinimumSize(QSize(40, 35));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/car.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_cars->setIcon(icon3);

        horizontalLayout->addWidget(btn_cars);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Customers);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(Customers);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::CurrentChanged|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Customers);

        QMetaObject::connectSlotsByName(Customers);
    } // setupUi

    void retranslateUi(QWidget *Customers)
    {
        Customers->setWindowTitle(QCoreApplication::translate("Customers", "Form", nullptr));
        btn_add->setText(QString());
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Customers", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QString());
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Customers", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_info->setText(QString());
#if QT_CONFIG(shortcut)
        btn_info->setShortcut(QCoreApplication::translate("Customers", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_cars->setText(QString());
#if QT_CONFIG(shortcut)
        btn_cars->setShortcut(QCoreApplication::translate("Customers", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("Customers", "\320\235\320\260\321\217\320\262\320\275\321\226\321\201\321\202\321\214 \320\206\320\237\320\235 \320\263\320\276\320\262\320\276\321\200\320\270\321\202\321\214 \320\277\321\200\320\276 \321\202\320\265, \321\211\320\276 \320\272\320\273\321\226\321\224\320\275\321\202 - \321\206\320\265 \320\276\321\200\320\263\320\260\320\275\321\226\320\267\320\260\321\206\321\226\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customers: public Ui_Customers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERS_H
