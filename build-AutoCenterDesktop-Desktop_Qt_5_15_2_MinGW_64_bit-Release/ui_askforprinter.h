/********************************************************************************
** Form generated from reading UI file 'askforprinter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASKFORPRINTER_H
#define UI_ASKFORPRINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AskForPrinter
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_accept;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_reject;

    void setupUi(QDialog *AskForPrinter)
    {
        if (AskForPrinter->objectName().isEmpty())
            AskForPrinter->setObjectName(QString::fromUtf8("AskForPrinter"));
        AskForPrinter->resize(241, 80);
        verticalLayout = new QVBoxLayout(AskForPrinter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(AskForPrinter);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_accept = new QPushButton(AskForPrinter);
        btn_accept->setObjectName(QString::fromUtf8("btn_accept"));

        horizontalLayout->addWidget(btn_accept);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_reject = new QPushButton(AskForPrinter);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));

        horizontalLayout->addWidget(btn_reject);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AskForPrinter);
        QObject::connect(btn_reject, SIGNAL(clicked()), AskForPrinter, SLOT(reject()));

        QMetaObject::connectSlotsByName(AskForPrinter);
    } // setupUi

    void retranslateUi(QDialog *AskForPrinter)
    {
        AskForPrinter->setWindowTitle(QCoreApplication::translate("AskForPrinter", "Dialog", nullptr));
        btn_accept->setText(QCoreApplication::translate("AskForPrinter", "\320\236\320\261\321\200\320\260\321\202\320\270", nullptr));
        btn_reject->setText(QCoreApplication::translate("AskForPrinter", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AskForPrinter: public Ui_AskForPrinter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASKFORPRINTER_H
