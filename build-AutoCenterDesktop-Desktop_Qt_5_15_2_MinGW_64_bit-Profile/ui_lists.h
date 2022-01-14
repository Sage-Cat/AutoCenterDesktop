/********************************************************************************
** Form generated from reading UI file 'lists.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTS_H
#define UI_LISTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lists
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QPushButton *btn_create;
    QPushButton *btn_load;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radio_all;
    QRadioButton *radio_org;
    QRadioButton *radio_not_org;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *Lists)
    {
        if (Lists->objectName().isEmpty())
            Lists->setObjectName(QString::fromUtf8("Lists"));
        Lists->resize(981, 607);
        verticalLayout = new QVBoxLayout(Lists);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_add = new QPushButton(Lists);
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

        btn_del = new QPushButton(Lists);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));
        btn_del->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_del->sizePolicy().hasHeightForWidth());
        btn_del->setSizePolicy(sizePolicy);
        btn_del->setMinimumSize(QSize(40, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon1);

        horizontalLayout_3->addWidget(btn_del);

        btn_create = new QPushButton(Lists);
        btn_create->setObjectName(QString::fromUtf8("btn_create"));
        sizePolicy.setHeightForWidth(btn_create->sizePolicy().hasHeightForWidth());
        btn_create->setSizePolicy(sizePolicy);
        btn_create->setMinimumSize(QSize(40, 35));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/page.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_create->setIcon(icon2);

        horizontalLayout_3->addWidget(btn_create);

        btn_load = new QPushButton(Lists);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        sizePolicy.setHeightForWidth(btn_load->sizePolicy().hasHeightForWidth());
        btn_load->setSizePolicy(sizePolicy);
        btn_load->setMinimumSize(QSize(40, 35));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_load->setIcon(icon3);

        horizontalLayout_3->addWidget(btn_load);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        groupBox = new QGroupBox(Lists);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radio_all = new QRadioButton(groupBox);
        radio_all->setObjectName(QString::fromUtf8("radio_all"));
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(12);
        font.setUnderline(true);
        radio_all->setFont(font);
        radio_all->setChecked(true);

        horizontalLayout->addWidget(radio_all);

        radio_org = new QRadioButton(groupBox);
        radio_org->setObjectName(QString::fromUtf8("radio_org"));
        radio_org->setFont(font);

        horizontalLayout->addWidget(radio_org);

        radio_not_org = new QRadioButton(groupBox);
        radio_not_org->setObjectName(QString::fromUtf8("radio_not_org"));
        radio_not_org->setFont(font);

        horizontalLayout->addWidget(radio_not_org);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(Lists);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font1;
        font1.setPointSize(16);
        tableView->setFont(font1);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Lists);

        QMetaObject::connectSlotsByName(Lists);
    } // setupUi

    void retranslateUi(QWidget *Lists)
    {
        Lists->setWindowTitle(QCoreApplication::translate("Lists", "Form", nullptr));
        btn_add->setText(QString());
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Lists", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QString());
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Lists", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_create->setText(QString());
#if QT_CONFIG(shortcut)
        btn_create->setShortcut(QCoreApplication::translate("Lists", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_load->setText(QString());
#if QT_CONFIG(shortcut)
        btn_load->setShortcut(QCoreApplication::translate("Lists", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QString());
        radio_all->setText(QCoreApplication::translate("Lists", "\320\243\321\201\321\226", nullptr));
        radio_org->setText(QCoreApplication::translate("Lists", "\320\236\321\200\320\263\320\260\320\275\321\226\320\267\320\260\321\206\321\226\321\227", nullptr));
        radio_not_org->setText(QCoreApplication::translate("Lists", "\320\237\320\276\320\272\321\203\320\277\321\206\321\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lists: public Ui_Lists {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTS_H
