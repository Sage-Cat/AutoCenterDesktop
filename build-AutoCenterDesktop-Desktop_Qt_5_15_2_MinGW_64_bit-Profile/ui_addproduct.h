/********************************************************************************
** Form generated from reading UI file 'addproduct.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPRODUCT_H
#define UI_ADDPRODUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddProduct
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_17;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *line_name;
    QLineEdit *line_code;
    QLineEdit *line_catalog;
    QLineEdit *line_tnved;
    QLineEdit *line_unit;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_reject_3;

    void setupUi(QDialog *AddProduct)
    {
        if (AddProduct->objectName().isEmpty())
            AddProduct->setObjectName(QString::fromUtf8("AddProduct"));
        AddProduct->resize(401, 225);
        verticalLayout = new QVBoxLayout(AddProduct);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_17 = new QLabel(AddProduct);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(12);
        label_17->setFont(font);

        verticalLayout_5->addWidget(label_17);

        label_11 = new QLabel(AddProduct);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        verticalLayout_5->addWidget(label_11);

        label_15 = new QLabel(AddProduct);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        verticalLayout_5->addWidget(label_15);

        label_16 = new QLabel(AddProduct);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        verticalLayout_5->addWidget(label_16);

        label_14 = new QLabel(AddProduct);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        line_name = new QLineEdit(AddProduct);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setFont(font);

        verticalLayout_6->addWidget(line_name);

        line_code = new QLineEdit(AddProduct);
        line_code->setObjectName(QString::fromUtf8("line_code"));
        line_code->setFont(font);

        verticalLayout_6->addWidget(line_code);

        line_catalog = new QLineEdit(AddProduct);
        line_catalog->setObjectName(QString::fromUtf8("line_catalog"));
        line_catalog->setFont(font);

        verticalLayout_6->addWidget(line_catalog);

        line_tnved = new QLineEdit(AddProduct);
        line_tnved->setObjectName(QString::fromUtf8("line_tnved"));
        line_tnved->setFont(font);

        verticalLayout_6->addWidget(line_tnved);

        line_unit = new QLineEdit(AddProduct);
        line_unit->setObjectName(QString::fromUtf8("line_unit"));
        line_unit->setFont(font);

        verticalLayout_6->addWidget(line_unit);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_5);

        line = new QFrame(AddProduct);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btn_add = new QPushButton(AddProduct);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setFont(font);

        horizontalLayout_6->addWidget(btn_add);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btn_reject_3 = new QPushButton(AddProduct);
        btn_reject_3->setObjectName(QString::fromUtf8("btn_reject_3"));
        btn_reject_3->setFont(font);

        horizontalLayout_6->addWidget(btn_reject_3);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(AddProduct);
        QObject::connect(btn_reject_3, SIGNAL(clicked()), AddProduct, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddProduct);
    } // setupUi

    void retranslateUi(QDialog *AddProduct)
    {
        AddProduct->setWindowTitle(QCoreApplication::translate("AddProduct", "\320\224\320\276\320\264\320\260\321\202\320\270 \321\202\320\276\320\262\320\260\321\200", nullptr));
        label_17->setText(QCoreApplication::translate("AddProduct", "\320\235\320\260\320\267\320\262\320\260:", nullptr));
        label_11->setText(QCoreApplication::translate("AddProduct", "\320\232\320\276\320\264:", nullptr));
        label_15->setText(QCoreApplication::translate("AddProduct", "\320\232\320\260\321\202\320\260\320\273\320\276\320\263:", nullptr));
        label_16->setText(QCoreApplication::translate("AddProduct", "\320\242\320\235\320\222\320\225\320\224:", nullptr));
        label_14->setText(QCoreApplication::translate("AddProduct", "\320\236\320\264\320\270\320\275\320\270\321\206\321\226:", nullptr));
        line_name->setText(QString());
        line_code->setText(QString());
        line_catalog->setText(QString());
        line_tnved->setText(QString());
        line_unit->setText(QCoreApplication::translate("AddProduct", "\321\210\321\202.", nullptr));
        btn_add->setText(QCoreApplication::translate("AddProduct", "\320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
        btn_reject_3->setText(QCoreApplication::translate("AddProduct", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProduct: public Ui_AddProduct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPRODUCT_H
