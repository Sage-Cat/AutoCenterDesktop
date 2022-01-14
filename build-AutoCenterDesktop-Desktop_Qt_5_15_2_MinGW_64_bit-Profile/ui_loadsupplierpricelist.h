/********************************************************************************
** Form generated from reading UI file 'loadsupplierpricelist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSUPPLIERPRICELIST_H
#define UI_LOADSUPPLIERPRICELIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadSupplierPricelist
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_path;
    QPushButton *btn_explorer;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_load;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_cancel;
    QProgressBar *progressBar;
    QLabel *label_status;

    void setupUi(QDialog *LoadSupplierPricelist)
    {
        if (LoadSupplierPricelist->objectName().isEmpty())
            LoadSupplierPricelist->setObjectName(QString::fromUtf8("LoadSupplierPricelist"));
        LoadSupplierPricelist->resize(467, 256);
        verticalLayout = new QVBoxLayout(LoadSupplierPricelist);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(LoadSupplierPricelist);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Alef"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line_path = new QLineEdit(LoadSupplierPricelist);
        line_path->setObjectName(QString::fromUtf8("line_path"));
        line_path->setFont(font);

        horizontalLayout_2->addWidget(line_path);

        btn_explorer = new QPushButton(LoadSupplierPricelist);
        btn_explorer->setObjectName(QString::fromUtf8("btn_explorer"));
        btn_explorer->setMinimumSize(QSize(30, 30));
        btn_explorer->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_explorer->setIcon(icon);

        horizontalLayout_2->addWidget(btn_explorer);


        verticalLayout->addLayout(horizontalLayout_2);

        line_2 = new QFrame(LoadSupplierPricelist);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(LoadSupplierPricelist);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        comboBox = new QComboBox(LoadSupplierPricelist);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(LoadSupplierPricelist);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_load = new QPushButton(LoadSupplierPricelist);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        btn_load->setFont(font);
        btn_load->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btn_load);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_cancel = new QPushButton(LoadSupplierPricelist);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setFont(font);
        btn_cancel->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(btn_cancel);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(LoadSupplierPricelist);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setAutoFillBackground(false);
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar);

        label_status = new QLabel(LoadSupplierPricelist);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_status);


        retranslateUi(LoadSupplierPricelist);
        QObject::connect(btn_cancel, SIGNAL(clicked()), LoadSupplierPricelist, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoadSupplierPricelist);
    } // setupUi

    void retranslateUi(QDialog *LoadSupplierPricelist)
    {
        LoadSupplierPricelist->setWindowTitle(QCoreApplication::translate("LoadSupplierPricelist", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\277\321\200\320\260\320\271\321\201\320\273\320\270\321\201\321\202", nullptr));
        label->setText(QCoreApplication::translate("LoadSupplierPricelist", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 xml-\321\204\320\260\320\271\320\273:", nullptr));
        line_path->setText(QString());
        btn_explorer->setText(QString());
        label_2->setText(QCoreApplication::translate("LoadSupplierPricelist", "\320\237\320\276\321\201\321\202\320\260\321\207\320\260\320\273\321\214\320\275\320\270\320\272:", nullptr));
        btn_load->setText(QCoreApplication::translate("LoadSupplierPricelist", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270", nullptr));
        btn_cancel->setText(QCoreApplication::translate("LoadSupplierPricelist", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        progressBar->setFormat(QCoreApplication::translate("LoadSupplierPricelist", "%p%", nullptr));
        label_status->setText(QCoreApplication::translate("LoadSupplierPricelist", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadSupplierPricelist: public Ui_LoadSupplierPricelist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSUPPLIERPRICELIST_H
