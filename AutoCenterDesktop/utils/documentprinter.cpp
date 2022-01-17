#include "documentprinter.h"

#include <QFile>
#include <QModelIndex>
#include <QPainter>
#include <QPrintDialog>
#include <QPrinter>
#include <QPageSize>
#include <QTextDocument>
#include <QTextStream>
#include <QTemporaryFile>
#include <QDesktopServices>

#include <QMessageBox>

#include "global.h"

DocumentPrinter::DocumentPrinter()
{
}

void DocumentPrinter::printPdvRahunok(const Person& seller, const QString& customerName, const QSqlTableModel* model,
                                      const QString &date, const QString &listnumber)
{
    QFile x(":pdv_rahunok.htm");
    x.open(QIODevice::ReadOnly);
    QTextStream in(&x);
    QString html_template = in.readAll();

    if (seller.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + seller.name + " некоректний ІБАН. Змініть його перед повтором спроби", QMessageBox::Ok);
        return;
    }

    // Get RR1, RR2
    const QString RR1 = seller.iban.mid(0, 10);
    const QString RR2 = seller.iban.mid(10);

    // Creating data and calculating all sum
    float all_sum {};
    const QString data { generateTableDataAndCalculateAllSum(model, all_sum) };

    // Calculating pdv
    const float pdv = all_sum * 0.2;
    const float all_sum_with_pdv = all_sum + pdv;

    const QString
        all { QString::number(all_sum, 'f', 2) + " грн" },
        just_pdv { QString::number(pdv, 'f', 2) + " грн" },
        all_with_pdv { QString::number(all_sum_with_pdv, 'f', 2) + " грн" };

    // Geting written prices
    const QString
        all_with_pdv_str { convertPriceInWords(all_sum_with_pdv) },
        pdv_str { convertPriceInWords(pdv) };

    html_template.replace(":SellerNameOnlyFIO", seller.name.mid(4));
    html_template.replace(":SellerName", seller.name);
    html_template.replace(":CustomerName", customerName);
    html_template.replace(":RR1", RR1);
    html_template.replace(":RR2", RR2);
    html_template.replace(":RRFull", seller.iban);
    html_template.replace(":Date", date);
    html_template.replace(":ListNumber", listnumber);
    html_template.replace(":IPN", seller.ipn);
    html_template.replace(":Bank", seller.bank);
    html_template.replace(":Number", seller.number);
    html_template.replace(":EDRPOY", seller.edrpoy);
    html_template.replace(":Data", data);
    html_template.replace(":All_with_Pdv_str", all_with_pdv_str);
    html_template.replace(":All_with_Pdv", all_with_pdv);
    html_template.replace(":All", all);
    html_template.replace(":Pdv_str", pdv_str);
    html_template.replace(":Pdv", just_pdv);
    html_template.replace(":i", QString::number(model->rowCount()));

    printHtmlForm(html_template);
}

void DocumentPrinter::printPdvNakladna(const Person &seller, const Person &customer, const QSqlTableModel *model, const QString &date, const QString &listnumber)
{
    QFile x(":pdv_nakladna.htm");
    x.open(QIODevice::ReadOnly);
    QTextStream in(&x);
    QString html_template = in.readAll();

    if (seller.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + seller.name + " некоректний ІБАН. Змініть його перед повтором спроби.", QMessageBox::Ok);
        return;
    }

    if (customer.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + customer.name + " некоректний ІБАН. Змініть його перед повтором спроби.", QMessageBox::Ok);
        return;
    }

    // Creating data and calculating all sum
    float all_sum {};
    const QString data { generateTableDataAndCalculateAllSum(model, all_sum) };

    // Calculating pdv
    const float pdv = all_sum * 0.2;
    const float all_sum_with_pdv = all_sum + pdv;

    const QString
        all { QString::number(all_sum, 'f', 2) + " грн" },
        just_pdv { QString::number(pdv, 'f', 2) + " грн" },
        all_with_pdv { QString::number(all_sum_with_pdv, 'f', 2) + " грн" };

    // Geting written prices
    const QString
        all_with_pdv_str { convertPriceInWords(all_sum_with_pdv) },
        pdv_str { convertPriceInWords(pdv) };

    html_template.replace(":SellerNameOnlyFIO", seller.name.mid(4));
    html_template.replace(":SellerName", seller.name);
    html_template.replace(":CustomerName", customer.name);
    html_template.replace(":c_Address", customer.address);
    html_template.replace(":c_EDRPOY", customer.edrpoy);
    html_template.replace(":c_IPN", customer.ipn);
    html_template.replace(":IBAN", seller.iban);
    html_template.replace(":Date", date);
    html_template.replace(":ListNumber", listnumber);
    html_template.replace(":IPN", seller.ipn);
    html_template.replace(":Bank", seller.bank);
    html_template.replace(":Number", seller.number);
    html_template.replace(":EDRPOY", seller.edrpoy);
    html_template.replace(":Data", data);
    html_template.replace(":All_with_Pdv_str", all_with_pdv_str);
    html_template.replace(":All_with_Pdv", all_with_pdv);
    html_template.replace(":All", all);
    html_template.replace(":Pdv_str", pdv_str);
    html_template.replace(":Pdv", just_pdv);
    html_template.replace(":i", QString::number(model->rowCount()));

    printHtmlForm(html_template);
}

void DocumentPrinter::printBezPdvRahunok(const Person &seller, const QString &customerName, const QSqlTableModel *model, const QString &date, const QString &listnumber)
{
    QFile x(":bez_pdv_rahunok.htm");
    x.open(QIODevice::ReadOnly);
    QTextStream in(&x);
    QString html_template = in.readAll();

    if (seller.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + seller.name + " некоректний ІБАН. Змініть його перед повтором спроби", QMessageBox::Ok);
        return;
    }

    // Get RR1, RR2
    const QString RR1 = seller.iban.mid(0, 10);
    const QString RR2 = seller.iban.mid(10);

    // Creating data and calculating all sum
    float all_sum {};
    const QString data { generateTableDataAndCalculateAllSum(model, all_sum) };

    const QString
        all { QString::number(all_sum, 'f', 2) + " грн" };

    // Geting written prices
    const QString
        all_str { convertPriceInWords(all_sum) };

    html_template.replace(":SellerNameOnlyFIO", seller.name.mid(4));
    html_template.replace(":SellerName", seller.name);
    html_template.replace(":CustomerName", customerName);
    html_template.replace(":RR1", RR1);
    html_template.replace(":RR2", RR2);
    html_template.replace(":RRFull", seller.iban);
    html_template.replace(":Date", date);
    html_template.replace(":ListNumber", listnumber);
    html_template.replace(":IPN", seller.ipn);
    html_template.replace(":Bank", seller.bank);
    html_template.replace(":Number", seller.number);
    html_template.replace(":EDRPOY", seller.edrpoy);
    html_template.replace(":Data", data);
    html_template.replace(":All_str", all_str);
    html_template.replace(":All", all);
    html_template.replace(":i", QString::number(model->rowCount()));

    printHtmlForm(html_template);
}

void DocumentPrinter::printBezPdvNakladna(const Person &seller, const QString &customerName, const QSqlTableModel *model, const QString &date, const QString &listnumber)
{
    QFile x(":bez_pdv_nakladna.htm");
    x.open(QIODevice::ReadOnly);
    QTextStream in(&x);
    QString html_template = in.readAll();

    if (seller.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + seller.name + " некоректний ІБАН. Змініть його перед повтором спроби", QMessageBox::Ok);
        return;
    }

    // Creating data and calculating all sum
    float all_sum {};
    const QString data { generateTableDataAndCalculateAllSum(model, all_sum) };

    const QString
        all { QString::number(all_sum, 'f', 2) + " грн" };

    // Geting written prices
    const QString
        all_str { convertPriceInWords(all_sum) };

    html_template.replace(":SellerNameOnlyFIO", seller.name.mid(4));
    html_template.replace(":SellerName", seller.name);
    html_template.replace(":CustomerName", customerName);
    html_template.replace(":IBAN", seller.iban);
    html_template.replace(":Date", date);
    html_template.replace(":ListNumber", listnumber);
    html_template.replace(":IPN", seller.ipn);
    html_template.replace(":Bank", seller.bank);
    html_template.replace(":EDRPOY", seller.edrpoy);
    html_template.replace(":Data", data);
    html_template.replace(":All_str", all_str);
    html_template.replace(":All", all);
    html_template.replace(":i", QString::number(model->rowCount()));

    printHtmlForm(html_template);
}

void DocumentPrinter::printBezPdvChek(const Person &seller, const QString &customerName, const QSqlTableModel *model, const QString &date, const QString &listnumber)
{
    QFile x(":bez_pdv_chek.htm");
    x.open(QIODevice::ReadOnly);
    QTextStream in(&x);
    QString html_template = in.readAll();

    if (seller.iban.size() < 10) {
        QMessageBox::warning(0, "Помилка", "У продавця " + seller.name + " некоректний ІБАН. Змініть його перед повтором спроби", QMessageBox::Ok);
        return;
    }

    // Creating data and calculating all sum
    float all_sum {};
    const QString data { generateTableDataAndCalculateAllSumForChek(model, all_sum) };

    const QString
        all { QString::number(all_sum, 'f', 2) + " грн" };

    // Geting written prices
    const QString
        all_str { convertPriceInWords(all_sum) };

    html_template.replace(":SellerNameOnlyFIO", seller.name.mid(4));
    html_template.replace(":SellerName", seller.name);
    html_template.replace(":Date", date);
    html_template.replace(":ListNumber", listnumber);
    html_template.replace(":Data", data);
    html_template.replace(":All_str", all_str);
    html_template.replace(":All", all);

    printHtmlForm(html_template);
}

void DocumentPrinter::printHtmlForm(const QString& html)
{
    QFile tmpFile(QLatin1String( "html_doc.html" ));
    tmpFile.open(QIODevice::WriteOnly);
    QTextStream out( &tmpFile );
    out << html;
    tmpFile.close();
    QDesktopServices::openUrl( QUrl("html_doc.html") );

//    QPrinter printer(QPrinter::HighResolution);
//    printer.setPageMargins(0,0,0,0, QPrinter::Millimeter);
//    printer.setPaperSize(QPrinter::A4);

//    QPrintDialog dlg(&printer);
//    if (dlg.exec() == QPrintDialog::Accepted) {
//        printer.setFullPage(true);
//        QTextDocument TextDocument;
//        TextDocument.setHtml(html);
//        TextDocument.print(&printer);
//    }
}

QString DocumentPrinter::convertPriceInWords(float sum)
{
    Q_ASSERT(sum > 0 && sum < 999999.99);

    QString part_one {}, part_two {};
    int integer = static_cast<int>(sum);
    int hundredth = static_cast<int>(100.0 * (sum - static_cast<float>(integer)));

    // fisrt & second digits
    if (integer % 10 != 0 && integer % 100 == 1) {
        switch (integer % 10) {
        case 1:
            part_one = "одинадцять гривень " + part_one;
            break;
        case 2:
            part_one = "дванадцять гривень " + part_one;
            break;
        case 3:
            part_one = "тринадцять гривень " + part_one;
            break;
        case 4:
            part_one = "чотирнадцять гривень " + part_one;
            break;
        case 5:
            part_one = "п'ятнадцять гривень " + part_one;
            break;
        case 6:
            part_one = "шістнадцять гривень " + part_one;
            break;
        case 7:
            part_one = "сімнадцять гривень " + part_one;
            break;
        case 8:
            part_one = "вісімнадцять гривень " + part_one;
            break;
        case 9:
            part_one = "дев'ятнадцять гривень " + part_one;
            break;
        }
    } else {
        switch (integer % 10) {
        case 0:
            part_one = "гривень " + part_one;
            break;
        case 1:
            part_one = "одна гривня " + part_one;
            break;
        case 2:
            part_one = "дві гривні " + part_one;
            break;
        case 3:
            part_one = "три гривні " + part_one;
            break;
        case 4:
            part_one = "чотири гривні " + part_one;
            break;
        case 5:
            part_one = "п'ять гривень " + part_one;
            break;
        case 6:
            part_one = "шість гривень " + part_one;
            break;
        case 7:
            part_one = "сім гривень " + part_one;
            break;
        case 8:
            part_one = "вісім гривень " + part_one;
            break;
        case 9:
            part_one = "дев'ять гривень " + part_one;
            break;
        }
        integer /= 10;
        switch (integer % 10) {
        case 1:
            part_one = "десять " + part_one;
            break;
        case 2:
            part_one = "двадцять " + part_one;
            break;
        case 3:
            part_one = "тридцять " + part_one;
            break;
        case 4:
            part_one = "сорок " + part_one;
            break;
        case 5:
            part_one = "п'ятдесят " + part_one;
            break;
        case 6:
            part_one = "шістдесят " + part_one;
            break;
        case 7:
            part_one = "сімдесят " + part_one;
            break;
        case 8:
            part_one = "вісімдесят " + part_one;
            break;
        case 9:
            part_one = "дев'яносто " + part_one;
            break;
        }
    }
    // third digit
    integer /= 10;
    switch (integer % 10) {
    case 1:
        part_one = "сто " + part_one;
        break;
    case 2:
        part_one = "двісті " + part_one;
        break;
    case 3:
        part_one = "триста " + part_one;
        break;
    case 4:
        part_one = "чотириста " + part_one;
        break;
    case 5:
        part_one = "п'ятсот " + part_one;
        break;
    case 6:
        part_one = "шістсот " + part_one;
        break;
    case 7:
        part_one = "сімсот " + part_one;
        break;
    case 8:
        part_one = "вісімсот " + part_one;
        break;
    case 9:
        part_one = "дев'ятсот " + part_one;
        break;
    }

    // fourth & fifth digits
    integer /= 10;
    if (integer % 10 != 0 && integer % 100 == 1) {
        switch (integer % 10) {
        case 1:
            part_one = "одинадцять тисяч " + part_one;
            break;
        case 2:
            part_one = "дванадцять тисяч " + part_one;
            break;
        case 3:
            part_one = "тринадцять тисяч " + part_one;
            break;
        case 4:
            part_one = "чотирнадцять тисяч " + part_one;
            break;
        case 5:
            part_one = "п'ятнадцять тисяч " + part_one;
            break;
        case 6:
            part_one = "шістнадцять тисяч " + part_one;
            break;
        case 7:
            part_one = "сімнадцять тисяч" + part_one;
            break;
        case 8:
            part_one = "вісімнадцять тисяч" + part_one;
            break;
        case 9:
            part_one = "дев'ятнадцять тисяч " + part_one;
            break;
        }
    } else {
        const QString thousand = integer % 100 == 0 && integer % 1000 == 0 ? "одна тисяча " : "тисяч ";
        switch (integer % 10) {
        case 1:
            part_one = thousand + part_one;
            break;
        case 2:
            part_one = "дві тисячі " + part_one;
            break;
        case 3:
            part_one = "три тисячі " + part_one;
            break;
        case 4:
            part_one = "чотири тисячі " + part_one;
            break;
        case 5:
            part_one = "п'ять тисяч " + part_one;
            break;
        case 6:
            part_one = "шість тисяч " + part_one;
            break;
        case 7:
            part_one = "сім тисяч " + part_one;
            break;
        case 8:
            part_one = "вісім тисяч " + part_one;
            break;
        case 9:
            part_one = "дев'ять тисяч " + part_one;
            break;
        }
        integer /= 10;
        switch (integer % 10) {
        case 1:
            part_one = "десять " + part_one;
            break;
        case 2:
            part_one = "двадцять " + part_one;
            break;
        case 3:
            part_one = "тридцять " + part_one;
            break;
        case 4:
            part_one = "сорок " + part_one;
            break;
        case 5:
            part_one = "п'ятдесят " + part_one;
            break;
        case 6:
            part_one = "шістдесят " + part_one;
            break;
        case 7:
            part_one = "сімдесят " + part_one;
            break;
        case 8:
            part_one = "вісімдесят " + part_one;
            break;
        case 9:
            part_one = "дев'яносто " + part_one;
            break;
        }
    }

    // sixth number
    integer /= 10;
    switch (integer % 10) {
    case 1:
        part_one = "сто " + part_one;
        break;
    case 2:
        part_one = "двісті " + part_one;
        break;
    case 3:
        part_one = "триста " + part_one;
        break;
    case 4:
        part_one = "чотириста " + part_one;
        break;
    case 5:
        part_one = "п'ятсот " + part_one;
        break;
    case 6:
        part_one = "шістсот " + part_one;
        break;
    case 7:
        part_one = "сімсот " + part_one;
        break;
    case 8:
        part_one = "вісімсот " + part_one;
        break;
    case 9:
        part_one = "дев'ятсот " + part_one;
        break;
    }

    /* -------------------------------------------------------- */

    if (hundredth != 0) {
        if (hundredth % 10 != 0 && hundredth % 100 == 1) {
            switch (hundredth % 10) {
            case 1:
                part_two = "одинадцять копійок " + part_two;
                break;
            case 2:
                part_two = "дванадцять копійок " + part_two;
                break;
            case 3:
                part_two = "тринадцять копійок " + part_two;
                break;
            case 4:
                part_two = "чотирнадцять копійок " + part_two;
                break;
            case 5:
                part_two = "п'ятнадцять копійок " + part_two;
                break;
            case 6:
                part_two = "шістнадцять копійок " + part_two;
                break;
            case 7:
                part_two = "сімнадцять копійок" + part_two;
                break;
            case 8:
                part_two = "вісімнадцять копійок" + part_two;
                break;
            case 9:
                part_two = "дев'ятнадцять копійок " + part_two;
                break;
            }
        } else {
            switch (hundredth % 10) {
            case 0:
                part_two = "копійок " + part_two;
                break;
            case 1:
                part_two = "одна копійка " + part_two;
                break;
            case 2:
                part_two = "дві копійки " + part_two;
                break;
            case 3:
                part_two = "три копійки " + part_two;
                break;
            case 4:
                part_two = "чотири копійки " + part_two;
                break;
            case 5:
                part_two = "п'ять копійок " + part_two;
                break;
            case 6:
                part_two = "шість копійок " + part_two;
                break;
            case 7:
                part_two = "сім копійок" + part_two;
                break;
            case 8:
                part_two = "вісім копійок" + part_two;
                break;
            case 9:
                part_two = "дев'ять копійок " + part_two;
                break;
            }
            hundredth /= 10;
            switch (hundredth % 10) {
            case 1:
                part_two = "десять " + part_two;
                break;
            case 2:
                part_two = "двадцять " + part_two;
                break;
            case 3:
                part_two = "тридцять " + part_two;
                break;
            case 4:
                part_two = "сорок " + part_two;
                break;
            case 5:
                part_two = "п'ятдесят " + part_two;
                break;
            case 6:
                part_two = "шістдесят " + part_two;
                break;
            case 7:
                part_two = "сімдесят " + part_two;
                break;
            case 8:
                part_two = "вісімдесят " + part_two;
                break;
            case 9:
                part_two = "дев'яносто " + part_two;
                break;
            }
        }
    }

    return part_one + part_two;
}

QString DocumentPrinter::generateTableDataAndCalculateAllSum(const QSqlTableModel *model, float &all_sum)
{
    QString data {};
    for (int i = 0; i < model->rowCount(); ++i) {
        const float price = model->index(i, PRICE_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        const float sum = model->index(i, SUM_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        all_sum += sum;

        QString row = TABLE_ROW;
        row.replace(":Number", QString::number(i + 1));
        row.replace(":Code", model->index(i, CODE_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Name", model->index(i, NAME_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Count", model->index(i, COUNT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Unit", model->index(i, UNIT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Price", QString::number(price, 'f', 2));
        row.replace(":Sum", QString::number(sum, 'f', 2));

        data += row + "\n";
    }
    return data;
}

QString DocumentPrinter::generateTableDataAndCalculateAllSumForChek(const QSqlTableModel *model, float &all_sum)
{
    QString data {};
    for (int i = 0; i < model->rowCount(); ++i) {
        const float price = model->index(i, PRICE_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        const float sum = model->index(i, SUM_COLUMN_INDEX).data(Qt::DisplayRole).toFloat();
        all_sum += sum;

        QString row = TABLE_ROW_FOR_CHECK;
        row.replace(":Code", model->index(i, CODE_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Name", model->index(i, NAME_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Count", model->index(i, COUNT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Unit", model->index(i, UNIT_COLUMN_INDEX).data(Qt::DisplayRole).toString());
        row.replace(":Price", QString::number(price, 'f', 2));
        row.replace(":Sum", QString::number(sum, 'f', 2));

        data += row + "\n";
    }
    return data;
}
