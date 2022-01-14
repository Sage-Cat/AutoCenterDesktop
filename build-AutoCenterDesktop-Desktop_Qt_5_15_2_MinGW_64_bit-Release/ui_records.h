/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Records
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_customer;
    QLabel *label_seller;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_Customer;
    QComboBox *comboBox_Seller;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDateTimeEdit *line_datetime;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_add;
    QPushButton *btn_del;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *line_sum;
    QLabel *label_2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_print_barcode;
    QPushButton *btn_print_document;

    void setupUi(QWidget *Records)
    {
        if (Records->objectName().isEmpty())
            Records->setObjectName(QString::fromUtf8("Records"));
        Records->resize(849, 601);
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(12);
        Records->setFont(font);
        verticalLayout_3 = new QVBoxLayout(Records);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_customer = new QLabel(Records);
        label_customer->setObjectName(QString::fromUtf8("label_customer"));
        label_customer->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_customer->setFont(font1);

        verticalLayout_2->addWidget(label_customer);

        label_seller = new QLabel(Records);
        label_seller->setObjectName(QString::fromUtf8("label_seller"));
        label_seller->setEnabled(true);
        label_seller->setFont(font1);

        verticalLayout_2->addWidget(label_seller);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox_Customer = new QComboBox(Records);
        comboBox_Customer->setObjectName(QString::fromUtf8("comboBox_Customer"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Customer->sizePolicy().hasHeightForWidth());
        comboBox_Customer->setSizePolicy(sizePolicy);
        comboBox_Customer->setMinimumSize(QSize(200, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(15);
        font2.setUnderline(false);
        comboBox_Customer->setFont(font2);

        verticalLayout->addWidget(comboBox_Customer);

        comboBox_Seller = new QComboBox(Records);
        comboBox_Seller->setObjectName(QString::fromUtf8("comboBox_Seller"));
        sizePolicy.setHeightForWidth(comboBox_Seller->sizePolicy().hasHeightForWidth());
        comboBox_Seller->setSizePolicy(sizePolicy);
        comboBox_Seller->setMinimumSize(QSize(200, 0));
        comboBox_Seller->setFont(font2);

        verticalLayout->addWidget(comboBox_Seller);


        horizontalLayout_7->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(Records);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        line_datetime = new QDateTimeEdit(Records);
        line_datetime->setObjectName(QString::fromUtf8("line_datetime"));
        line_datetime->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_4->addWidget(line_datetime);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_5);

        line = new QFrame(Records);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_add = new QPushButton(Records);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_add->sizePolicy().hasHeightForWidth());
        btn_add->setSizePolicy(sizePolicy1);
        btn_add->setMinimumSize(QSize(40, 35));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon);

        horizontalLayout->addWidget(btn_add);

        btn_del = new QPushButton(Records);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));
        btn_del->setEnabled(true);
        sizePolicy1.setHeightForWidth(btn_del->sizePolicy().hasHeightForWidth());
        btn_del->setSizePolicy(sizePolicy1);
        btn_del->setMinimumSize(QSize(40, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_del->setIcon(icon1);

        horizontalLayout->addWidget(btn_del);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        tableView = new QTableView(Records);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("DejaVu Sans"));
        font3.setPointSize(14);
        tableView->setFont(font3);
        tableView->horizontalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(Records);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_7->setFont(font4);

        horizontalLayout_6->addWidget(label_7);

        line_sum = new QLabel(Records);
        line_sum->setObjectName(QString::fromUtf8("line_sum"));
        line_sum->setEnabled(true);
        line_sum->setMinimumSize(QSize(100, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("DejaVu Sans"));
        font5.setPointSize(16);
        line_sum->setFont(font5);
        line_sum->setStyleSheet(QString::fromUtf8("background-color : white; \n"
"margin-left: 5px; \n"
"margin-right: 5px;\n"
"margin-top:8px;\n"
"margin-bottom:8px;\n"
"padding-top: 3px;\n"
"padding-bottom: 3px;\n"
"padding-left: 3px;\n"
"padding-right: 3px;\n"
"\n"
""));
        line_sum->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(line_sum);

        label_2 = new QLabel(Records);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font5);

        horizontalLayout_6->addWidget(label_2);


        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(horizontalLayout_8);

        line_3 = new QFrame(Records);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_print_barcode = new QPushButton(Records);
        btn_print_barcode->setObjectName(QString::fromUtf8("btn_print_barcode"));
        QFont font6;
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        btn_print_barcode->setFont(font6);
        btn_print_barcode->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"font: bold 20px;\n"
"margin-left: 10px;"));

        horizontalLayout_2->addWidget(btn_print_barcode);

        btn_print_document = new QPushButton(Records);
        btn_print_document->setObjectName(QString::fromUtf8("btn_print_document"));
        btn_print_document->setFont(font6);
        btn_print_document->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"font: bold 20px;\n"
"margin-left: 10px;"));

        horizontalLayout_2->addWidget(btn_print_document);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Records);

        QMetaObject::connectSlotsByName(Records);
    } // setupUi

    void retranslateUi(QWidget *Records)
    {
        Records->setWindowTitle(QCoreApplication::translate("Records", "\320\220\320\262\321\202\320\276\320\246\320\265\320\275\321\202\321\200", nullptr));
        label_customer->setText(QCoreApplication::translate("Records", "\320\237\320\276\320\272\321\203\320\277\320\265\321\206\321\214:", nullptr));
        label_seller->setText(QCoreApplication::translate("Records", "\320\237\321\200\320\276\320\264\320\260\320\262\320\265\321\206\321\214:", nullptr));
        label->setText(QCoreApplication::translate("Records", "\320\232\320\276\320\273\320\270:", nullptr));
        line_datetime->setDisplayFormat(QCoreApplication::translate("Records", "M/d/yy h:mm:ss", nullptr));
        btn_add->setText(QString());
#if QT_CONFIG(shortcut)
        btn_add->setShortcut(QCoreApplication::translate("Records", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_del->setText(QString());
#if QT_CONFIG(shortcut)
        btn_del->setShortcut(QCoreApplication::translate("Records", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        label_7->setText(QCoreApplication::translate("Records", "\320\241\321\203\320\274\320\260 \320\261\320\265\320\267 \320\277\320\264\320\262:", nullptr));
        line_sum->setText(QCoreApplication::translate("Records", "\320\264\320\260\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("Records", "\320\263\321\200\320\275", nullptr));
        btn_print_barcode->setText(QCoreApplication::translate("Records", "\320\224\321\200\321\203\320\272\321\203\320\262\320\260\321\202\320\270 \320\265\321\202\320\270\320\272\320\265\321\202\320\272\320\270", nullptr));
#if QT_CONFIG(shortcut)
        btn_print_barcode->setShortcut(QCoreApplication::translate("Records", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        btn_print_document->setText(QCoreApplication::translate("Records", "\320\224\321\200\321\203\320\272\321\203\320\262\320\260\321\202\320\270 \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202", nullptr));
#if QT_CONFIG(shortcut)
        btn_print_document->setShortcut(QCoreApplication::translate("Records", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
    } // retranslateUi

};

namespace Ui {
    class Records: public Ui_Records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
