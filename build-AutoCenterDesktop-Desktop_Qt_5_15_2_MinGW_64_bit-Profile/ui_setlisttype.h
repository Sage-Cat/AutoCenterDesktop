/********************************************************************************
** Form generated from reading UI file 'setlisttype.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETLISTTYPE_H
#define UI_SETLISTTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetListType
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_apply;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_reject;

    void setupUi(QDialog *SetListType)
    {
        if (SetListType->objectName().isEmpty())
            SetListType->setObjectName(QString::fromUtf8("SetListType"));
        SetListType->resize(250, 107);
        verticalLayout = new QVBoxLayout(SetListType);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(SetListType);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_apply = new QPushButton(SetListType);
        btn_apply->setObjectName(QString::fromUtf8("btn_apply"));

        horizontalLayout->addWidget(btn_apply);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_reject = new QPushButton(SetListType);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));

        horizontalLayout->addWidget(btn_reject);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SetListType);
        QObject::connect(btn_reject, SIGNAL(clicked()), SetListType, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetListType);
    } // setupUi

    void retranslateUi(QDialog *SetListType)
    {
        SetListType->setWindowTitle(QCoreApplication::translate("SetListType", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \321\202\320\270\320\277 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        btn_apply->setText(QCoreApplication::translate("SetListType", "\320\236\320\261\321\200\320\260\321\202\320\270", nullptr));
        btn_reject->setText(QCoreApplication::translate("SetListType", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetListType: public Ui_SetListType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLISTTYPE_H
