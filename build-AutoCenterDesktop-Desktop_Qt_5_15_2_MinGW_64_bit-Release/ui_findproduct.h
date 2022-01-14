/********************************************************************************
** Form generated from reading UI file 'findproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDPRODUCT_H
#define UI_FINDPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FindProduct
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QLineEdit *line_search;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_reject;

    void setupUi(QDialog *FindProduct)
    {
        if (FindProduct->objectName().isEmpty())
            FindProduct->setObjectName(QString::fromUtf8("FindProduct"));
        FindProduct->resize(314, 134);
        verticalLayout = new QVBoxLayout(FindProduct);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(FindProduct);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font;
        font.setPointSize(16);
        comboBox->setFont(font);

        verticalLayout->addWidget(comboBox);

        line_search = new QLineEdit(FindProduct);
        line_search->setObjectName(QString::fromUtf8("line_search"));
        line_search->setFont(font);

        verticalLayout->addWidget(line_search);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_search = new QPushButton(FindProduct);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setFont(font);

        horizontalLayout->addWidget(btn_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_reject = new QPushButton(FindProduct);
        btn_reject->setObjectName(QString::fromUtf8("btn_reject"));
        btn_reject->setFont(font);

        horizontalLayout->addWidget(btn_reject);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FindProduct);
        QObject::connect(btn_reject, SIGNAL(clicked()), FindProduct, SLOT(reject()));

        QMetaObject::connectSlotsByName(FindProduct);
    } // setupUi

    void retranslateUi(QDialog *FindProduct)
    {
        FindProduct->setWindowTitle(QCoreApplication::translate("FindProduct", "\320\227\320\275\320\260\320\271\321\202\320\270 \321\202\320\276\320\262\320\260\321\200", nullptr));
        btn_search->setText(QCoreApplication::translate("FindProduct", "\320\227\320\275\320\260\320\271\321\202\320\270", nullptr));
        btn_reject->setText(QCoreApplication::translate("FindProduct", "\320\222\321\226\320\264\320\274\321\226\320\275\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindProduct: public Ui_FindProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDPRODUCT_H
